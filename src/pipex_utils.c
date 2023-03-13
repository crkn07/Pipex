/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:25:38 by crtorres          #+#    #+#             */
/*   Updated: 2023/03/13 12:40:25 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	double_pointer_free(char **ptr)
{
    int i;

    i = 0;
    while (ptr[i])
    {
        free (ptr[i]);
        i++;
    }
    free (ptr);
}

void    exit_error(int err, char *msg, int errcode)
{
    if(err == 1)
        ft_putstr_fd("Invalid number of arguments\n", 2);
    else if(err == 2)
        perror("Pipe error :");
    else if(err == 3)
        perror("Fork error:");
    else if(err == 4)
        perror("no such file or directory :");
    else if(err == 5)
        perror("no such file or directory :");
    else if(err == 6)
        perror("command not found :");
    free(msg);
    exit (errcode);
}