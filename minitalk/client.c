/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgodart <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 12:33:02 by vgodart           #+#    #+#             */
/*   Updated: 2024/01/31 12:33:04 by vgodart          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_receiver = 0;

void	sig_handler(int sig)
{
	if (sig == SIGUSR2)
		g_receiver = 1;
}

int	char_to_bin(char c, int pid)
{
	int	bit_index;
	int	time;

	bit_index = 0;
	time = 0;
	while (bit_index < 8)
	{
		g_receiver = 0;
		if (c & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		bit_index++;
		while (!g_receiver)
		{
			if (time++ >= 10)
			{
				ft_printf("Error, no response from server\n");
				return (-1);
			}
			sleep(1);
		}
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;
	int	byte_index;

	if (argc != 3)
	{
		ft_printf("%s", "Error, Invalid number of arguments\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
	{
		ft_printf("Error, PID incorrect\n");
		return (1);
	}
	byte_index = 0;
	signal(SIGUSR2, sig_handler);
	while (argv[2][byte_index])
	{
		if (char_to_bin(argv[2][byte_index], pid) == 0)
			byte_index++;
		else
			return (-1);
	}
	return (0);
}
