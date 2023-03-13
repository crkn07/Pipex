/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crtorres <crtorres@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 20:24:43 by jisokang          #+#    #+#             */
/*   Updated: 2023/02/02 17:16:52 by crtorres         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

# ifndef OPEN_MAX
#  define OPEN_MAX 32
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int		get_next_line(int fd, char **line);
char	*ft_strjoin_gnl(char *s1, char const *s2);
char	*ft_strdup_gnl(const char *s1);
//size_t	ft_strlen_gnl(const char *s);
size_t	t_strlcpy_gnl(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat_gnl(char *dest, const char *src, size_t dstsize);

#endif
