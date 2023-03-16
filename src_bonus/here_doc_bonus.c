/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 12:03:15 by crtorres          #+#    #+#             */
/*   Updated: 2023/03/16 16:29:36 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	here_doc(char *argv, t_pipe pipex)
{
	int		file;
	char	*buf;

	file = open(".here_doc_tmp", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (file < 0)
		exit_error(ERR_HEREDOC, argv, 1);
	while (1)
	{
		write(1, "heredoc> ", 9);
		if (get_next_line(0, &buf) < 0)
			exit(1);
		if (!(ft_strncmp(argv, buf, ft_strlen(argv) + 1)))
			break ;
		write(file, buf, ft_strlen(buf));
		write(file, "\n", 1);
		free(buf);
	}
	free (buf);
	close(file);
}