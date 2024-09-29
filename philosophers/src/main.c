/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:23:32 by mayu              #+#    #+#             */
/*   Updated: 2024/09/29 15:28:14 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	main(int argc, char **argv)
{
	t_setting	*settings;
	t_philo		*philos;

	if (input_check(argc, argv))
		return (1);
	settings = init_data(argc, argv);
	if (init_mutex(settings))
		return (1);
	philos = init_philo(settings);
	if (!philos)
		return (1);
	if (thread_init(philos, settings))
		return (1);
	ft_exit(philos, settings);
	return (0);
}

// __attribute__((destructor)) static void destructor()
// {
// 	system("leaks -q philo");
// }
