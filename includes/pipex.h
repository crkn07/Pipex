/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:57:33 by crtorres          #+#    #+#             */
/*   Updated: 2023/03/13 13:41:24 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/wait.h>
# include "../libft/libft.h"
# include <errno.h>

# define ARG_ERROR  1

typedef struct s_pipe
{
	char	**path;
	int		pipe_fds[2];
	int		pid1;
	int		pid2;
	int		status;
}	t_pipe;

int main(int argc, char* argv[], char **env);
void    exit_error(int err, char *msg, int errcode);
void	double_pointer_free(char **ptr);

#endif