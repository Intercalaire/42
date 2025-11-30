/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:18:51 by vgodart           #+#    #+#             */
/*   Updated: 2023/11/20 12:18:53 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int to_find);
size_t	ft_strlen(char const *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

#endif
