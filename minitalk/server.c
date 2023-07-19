/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayyamad <mayyamad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:40:25 by mayyamad          #+#    #+#             */
/*   Updated: 2023/07/19 16:06:16 by mayyamad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signal_handler(int signal, siginfo_t *info, void *context)
{
	static int	bit;
	static int	i;

	(void)context;
	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		if (kill(info->si_pid, SIGUSR1) == -1)
		{
			ft_putendl_fd("error\n", 1);
			exit(1);
		}
		bit = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	act1;

	ft_printf("%d\n", getpid());
	act1.sa_sigaction = signal_handler;
	sigemptyset(&act1.sa_mask);
	act1.sa_flags = SA_SIGINFO;
	act1.sa_flags = 0;
	sigaddset(&act1.sa_mask, SIGUSR2);
	sigaddset(&act1.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &act1, NULL);
	sigaction(SIGUSR2, &act1, NULL);
	while (1)
		pause();
}
