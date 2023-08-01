/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 11:25:38 by crtorres          #+#    #+#             */
/*   Updated: 2023/07/28 17:07:16 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/**
 * The function `double_pointer_free` frees the memory allocated for a double
 * pointer and its contents.
 * 
 * @param ptr The parameter `ptr` is a double pointer to a character, which 
 * means it is a pointer to a pointer to a character.
 */
void	double_pointer_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free (ptr[i]);
		i++;
	}
	free (ptr);
}

/**
 * The function "checkcommand_in_path" checks if a given command is present in 
 * any of the directories specified in the "path" array.
 * 
 * @param path A double pointer to a char array, representing the list of
 * directories in the system's PATH variable.
 * @param command A string representing the command to be checked in the path.
 * 
 * @return a pointer to a character array (string) that represents the full 
 * path of the command if it is found in one of the directories specified in 
 * the `path` array. If the command is not found, the function returns NULL.
 */
char	*checkcommand_in_path(char **path, char *command)
{
	char	*fcmd;
	int		i;

	i = 0;
	while (path[i])
	{
		fcmd = ft_strjoin(path[i], command);
		if (access(fcmd, X_OK) == 0)
		{
			double_pointer_free(path);
			return (fcmd);
		}
		free (fcmd);
		i++;
	}
	return (NULL);
}

/**
 * It prints an error message and exits the program
 * 
 * @param err the error number
 * @param msg the error message to be displayed
 * @param errnum The error number that will be returned to the shell.
 */
void	exit_error(int err, char *msg, int errnum)
{
	if (err == 1)
		ft_putstr_fd("Invalid number of arguments\n", 2);
	else if (err == 2)
		perror("Pipe error :");
	else if (err == 3)
		perror("Fork error:");
	else if (err == 4)
		perror("no such file or directory :");
	else if (err == 5)
		msg = ft_strjoin(msg, ": no such file or directory");
	else if (err == 6)
		perror("command not found :");
	exit (errnum);
}
