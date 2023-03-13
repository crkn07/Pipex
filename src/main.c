/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:56:23 by crtorres          #+#    #+#             */
/*   Updated: 2023/03/13 17:25:06 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

#define READ_END    0    /* index pipe extremo lectura */
#define WRITE_END   1    /* index pipe extremo escritura */

#define FILE_NAME  "file.txt"   /* nombre del archivo donde escribir */

static char	*found_cmd(char **path, char **cmd, char *argv)
{
    char *new_cmd;
    int i;

    i = 0;
    if (access(cmd[0], X_OK) == 0)
    {
		double_pointer_free(path);
		new_cmd = ft_strjoin("", cmd[0]);
		return (new_cmd);
	}
    if (ft_strchr(cmd[0], '/') &&)
}

static void child1(char **path, char *argv[], int *pipe_fd, char **env)
{
    char    *path_cmd;
    char    **cmd;
    int     fd_input;
    
    fd_input = open(argv[1], O_RDONLY);
    if (fd_input == -1)
    {
        double_pointer_free(path);
        exit_error(4, argv[1], errno);
    }
    dup2(fd_input, STDIN_FILENO);
    close(fd_input);
    close(pipe_fd[0]);
    dup2(pipe_fd[1], STDOUT_FILENO);
    close(pipe_fd[1]);
    cmd = ft_split(argv[2], ' ');
    path_cmd = found_cmd(path, cmd, argv[2]);
    if (execve(path_cmd, cmd, env) == -1)
    {
        free(path_cmd);
        double_pointer_free(cmd);
        exit (errno);   
    }
}

static void child2(char **path, char *argv[], int *pipe_fd, char **env)
{
    char    *pth_cmd;
    char    **cmd;
    int     fd_output;

    fd_output = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd_output == -1)
    {
        double_pointer_free(path);
        exit_error(5, argv[4], errno);
    }
    dup2(pipe_fd[0], STDIN_FILENO);
    dup2(fd_output, STDOUT_FILENO);
    close(fd_output);
    close(pipe_fd[0]);
    cmd = ft_split(argv[3], ' ');
    pth_cmd = found_cmd(path, cmd, argv[3]);
    if (execve(pth_cmd, cmd, env) == -1)
    {
        free(pth_cmd);
        double_pointer_free(cmd);
        exit(errno);
    }
}

int main(int argc, char *argv[], char **env)   
{
    t_pipe  pipex;
    
    if (argc != 5)
        exit_error(ARG_ERROR, NULL, 1);
    pipex.path = find_path(env);
}