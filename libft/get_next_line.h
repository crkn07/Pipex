/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 18:37:34 by crtorres          #+#    #+#             */
/*   Updated: 2023/02/21 16:45:29 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE BUFSIZ
# endif

# if BUFFER_SIZE > 9223372036854775806L /*Double long*/
# endif

# include "unistd.h"
# include "stdlib.h"
# include "fcntl.h"
# include "stdio.h"

char	*get_next_line(int fd);
char	*ft_read_and_stash(int fd, char *stash);
char	*ft_stash(char *stash);
char	*ft_get_line(char *stash);
size_t	ft_strlengnl(char *str);
char	*ft_strjoingnl(char *s1, char *s2);
char	*ft_strchrgnl(char *str, int c);

#endif