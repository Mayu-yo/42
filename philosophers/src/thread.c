/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mayu <mayu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 22:24:51 by mayu              #+#    #+#             */
/*   Updated: 2024/09/25 22:26:58 by mayu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	thread_init(t_philo *philos, t_setting *settings)
{
	int	i;
	int	start_time;

	i = 0;
	start_time = get_current_time();
	while (i < settings->philo_num)
	{
		philos[i].start_time = start_time;
		if (pthread_create(&philos[i].thread, NULL, action, &philos[i]))
			return (error_exit("pthread_create failed", settings, philos));
		i++;
	}
	i = 0;
	while (i < settings->philo_num)
	{
		if (pthread_join(philos[i].thread, NULL))
			return (error_exit("pthread_join failed", settings, philos));
		if (pthread_join(philos[i].dead_thread, NULL))
			return (error_exit("pthread_join failed", settings, philos));
		i++;
	}
	return (0);
}

void	*is_dead(void *p_philo)
{
	t_philo	*philo;
	int		time;
	
	philo = (t_philo *)p_philo;
	while (1)
	{
		pthread_mutex_lock(philo->settings->print);
		if (philo->settings->dead_flag == true)
		{
			pthread_mutex_unlock(philo->settings->print);
			return (NULL);
		}
		time = get_current_time() - philo->last_meal;
		if (time >= philo->time_to_die || philo->settings->must_eat_times == philo->eat_count)
		{
			philo->settings->dead_flag = true;
			usleep(100);
			printf("%d %d died\n", get_current_time() - philo->start_time, philo->id);
			pthread_mutex_unlock(philo->settings->print);
			return (NULL);
		}
		pthread_mutex_unlock(philo->settings->print);
		usleep(500);
	}
}

void	*action(void *p_philo)
{
	t_philo	*philo;

	philo = (t_philo *)p_philo;
	philo->last_meal = get_current_time();
	if (pthread_create(&philo->dead_thread, NULL, is_dead, philo))
		return (free_all(philo, philo->settings));
	while(1)
	{
		if (eat(philo->settings, philo))
			return (NULL);
		if (sleep_and_think(philo->settings, philo))
			return (NULL);
	}
	return (NULL);
}
