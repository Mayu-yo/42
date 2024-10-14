/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:23:29 by mayu              #+#    #+#             */
/*   Updated: 2024/10/14 12:32:59 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				return (error_exit("Error: Wrong argument", NULL, NULL));
			j++;
		}
		i++;
	}
	return (0);
}

int	input_check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		return (error_exit("Error: Wrong argument", NULL, NULL));
	if (check_args(argc, argv))
		return (1);
	return (0);
}

int	print_message(t_setting *settings, t_philo *philo, char *str)
{
	usleep(10);
	pthread_mutex_lock(settings->print);
	if (philo->settings->dead_flag == true)
	{
		pthread_mutex_unlock(settings->print);
		return (1);
	}
	printf("%d %d ", get_current_time() - philo->start_time, philo->id + 1);
	printf("%s\n", str);
	pthread_mutex_unlock(settings->print);
	return (0);
}
