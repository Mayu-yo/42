/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:40:29 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/19 17:23:00 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	g_flag = 1;

void	signal_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		g_flag = 1;
	}
	else
	{
		ft_putendl_fd("error\n", 1);
		exit (0);
	}
}

void	send_char(int pid, char str)
{
	int	i;

	i = 0;
	g_flag = 0;
	while (i < 8)
	{
		if ((str & (0x01 << i)) != 0)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				ft_putendl_fd("error\n", 1);
				exit (1);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				ft_putendl_fd("error\n", 1);
				exit (1);
			}
		}
		usleep(50);
		i++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid;

	i = 0;
	if (argc != 3)
	{
		ft_putendl_fd("Usase: ./client [PID] [message]", 1);
		return (0);
	}
	pid = ft_atoi_pid(argv[1]);
	if (pid == -1)
	{
		ft_putendl_fd("Usase: ./client [PID] [message]", 1);
		return (0);
	}
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (argv[2][i])
	{
		if (g_flag == 1)
			send_char(pid, argv[2][i++]);
	}
	send_char(pid, '\n');
	return (0);
}
