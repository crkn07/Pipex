/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:25:38 by crtorres          #+#    #+#             */
/*   Updated: 2023/03/14 12:34:45 by crtorres         ###   ########.fr       */
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

/**
 * It prints an error message and exits the program
 * 
 * @param err the error number
 * @param msg the error message to be displayed
 * @param errnum The error number that will be returned to the shell.
 */
void    exit_error(int err, char *msg, int errnum)
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
        msg = ft_strjoin(msg, "no such file or directory :");
    else if(err == 6)
        perror("command not found :");
    free(msg);
    exit (errnum);
}