/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:32:14 by mayu              #+#    #+#             */
/*   Updated: 2024/09/25 22:32:29 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	error_exit(char *str, t_setting *settings, t_philo *philos)
{
	if (settings || philos)
		free_all(philos, settings);
	printf("%s\n", str);
	return (1);
}

void	ft_exit(t_philo *philo, t_setting *settings)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(settings->print);
	while (i < settings->philo_num)
	{
		pthread_mutex_destroy(&settings->fork[i]);
		i++;
	}
	free_all(philo, settings);
}

void	*free_all(t_philo *philos, t_setting *settings)
{
	if (settings->fork)
		free(settings->fork);
	if (settings->print)
		free(settings->print);
	if (settings)
		free(settings);
	if (philos)
		free(philos);
	return (NULL);
}
