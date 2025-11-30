/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 10:16:10 by vgodart           #+#    #+#             */
/*   Updated: 2023/11/15 15:25:35 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const	char *sign, ...);
int		ft_putchar_fd(char c, int fd);
size_t	ft_strlen(const char *s);
int		ft_putstr_fd(char *s, int fd);
int		ft_base_fd(unsigned int n, char	*base, int fd);
int		ft_putnbr_fd(int n, int fd);
int		ft_hexa_fd(unsigned long n, char *base, int fd);

#endif
