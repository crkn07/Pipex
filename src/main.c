/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:56:23 by crtorres          #+#    #+#             */
/*   Updated: 2023/03/12 12:46:00 by crtorres         ###   ########.fr       */
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
    if (access(cmd[0], F_OK) == 0)
    {
		double_pointer_free(path);
		new_cmd = ft_strjoin("", cmd[0]);
		return (new_cmd);
	}
}

int main(int argc, char *argv[], char **env)   
{
    t_pipe  pipex;
    
    if (argc != 5)
        exit_error(ARG_ERROR, NULL, 1);
    pipex.path = find_path(env);
}