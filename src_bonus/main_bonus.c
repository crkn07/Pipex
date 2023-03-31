/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:56:23 by crtorres          #+#    #+#             */
/*   Updated: 2023/03/29 15:14:37 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

/* static void        system_exec(char *cmdtemplate)
 {
         FILE* fp = popen(cmdtemplate, "r");
         if (fp == NULL) {
                 ft_putstr_fd("Error opening command", 2);
                 ft_putstr_fd(cmdtemplate, 2);
                 return ;
         }
         char output[1024];
         size_t n = fread(output, 1, sizeof(output), fp);
         output[n] = '\0';
         ft_putstr_fd(output, 2);
 }
static void exit_checks(void)
 {
    char cmdtemplate[1024];
    ft_putstr_fd("\n\n******************************************\n", 2);
    ft_putstr_fd("Open fds:\n", 2);
    sprintf(cmdtemplate, "lsof -p %d | grep CHR", getpid());
    system_exec(cmdtemplate);
    ft_putstr_fd("\nLeaks:\n", 2);
    sprintf(cmdtemplate, "leaks %d", getpid());
    system_exec(cmdtemplate);
    ft_putstr_fd("******************************************\n", 2);
 } */
/**
 * It reads from stdin until it finds the delimiter, then it writes everything 
 * it read to the pipe
 * 
 * @param argv the arguments passed to the command
 * @param pipe_fd The pipe file descriptor.
 */
void	put_hdc(char **argv, int *pipe_fd)
{
	char	*buf;

	close(pipe_fd[0]);
	write(1, "pipe heredoc> ", 14);
	buf = get_next_line(STDIN_FILENO);
	ft_putstr_fd(buf, pipe_fd[1]);
	while (buf)
	{
		if ((ft_strncmp(buf, argv[2], ft_strlen(argv[2])) == 0)
			&& (ft_strlen(buf) == ft_strlen(argv[2])))
		{
			free(buf);
			exit(0);
		}
		write(1, "pipe heredoc> ", 14);
		ft_putstr_fd(buf, pipe_fd[1]);
		buf = get_next_line(STDIN_FILENO);
	}
	free(buf);
}

/**
 * It creates a pipe, forks, and then the child process writes to the pipe and
 * the parent process reads from the pipe
 * 
 * @param argv The command line arguments.
 */
void	here_doc(char **argv)
{
	int		pipe_fd[2];
	pid_t	pid;
	int		*status;

	if (pipe(pipe_fd) == -1)
		exit(0);
	pid = fork();
	if (pid == -1)
		exit(0);
	status = 0;
	if (pid == 0)
		put_hdc(argv, pipe_fd);
	else
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN_FILENO);
		waitpid(pid, status, 0);
	}
}

/**
 * It creates a pipe, forks, and then executes the command in the child process
 * 
 * @param cmd the command to be executed
 * @param envp the environment variables
 */
void	do_pipe(char *cmd, char **envp)
{
	pid_t	pid;
	t_pipe	ppex;

	if (pipe(ppex.fd_pipe) == -1)
		exit_error(PIPE_ERR, NULL, 2);
	pid = fork();
	if (pid == -1)
		exit_error(FORK_ERR, NULL, 3);
	if (pid == 0)
	{
		close(ppex.fd_pipe[0]);
		dup2(ppex.fd_pipe[1], STDOUT_FILENO);
		exec(cmd, envp);
	}
	else
	{
		close(ppex.fd_pipe[1]);
		dup2(ppex.fd_pipe[0], STDIN_FILENO);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		i;
	t_pipe	pipex;

	if (argc < 5)
		exit_error(ARG_ERR, NULL, 1);
	if ((ft_strlen(argv[argc - 2]) || ft_strlen(argv[argc - 3])) == '\0')
		exit_error(COM_ERR, *argv, 127);
	if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[1])) == 0)
	{
		if (argc < 6)
			exit_error(ARG_ERR, NULL, 1);
		i = 3;
		pipex.fd_out = open_file(argv[argc - 1], 2);
		here_doc(argv);
	}
	else
	{
		i = 2;
		pipex.fd_in = open_file(argv[1], 0);
		pipex.fd_out = open_file(argv[argc - 1], 1);
		dup2(pipex.fd_in, STDIN_FILENO);
	}
	while (i < argc - 2)
		do_pipe(argv[i++], envp);
	dup2(pipex.fd_out, STDOUT_FILENO);
	exec(argv[argc - 2], envp);
}
