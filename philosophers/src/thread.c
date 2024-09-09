#include "../philo.h"

void thread_init(t_philo *philos, t_setting *settings)
{
	int i;
	int start_time;

	i = 0;
	start_time = get_current_time();
	while (i < settings->philo_num)
	{
		philos[i].start_time = start_time;
		if (pthread_create(&philos[i].thread, NULL, action, &philos[i]))
			error_print("pthread_create failed", settings, philos);
		i++;
	}
	i = 0;
	while (i < settings->philo_num)
	{
		if (pthread_join(philos[i].thread, NULL))
			error_print("pthread_join failed", settings, philos);
		if (pthread_join(philos[i].dead_thread, NULL))
			error_print("pthread_join failed", settings, philos);
		i++;
	}
}

void *is_dead(void *p_philo)
{
	t_philo *philo;
	int time;
	philo = (t_philo *)p_philo;
	while (1)
	{
		if (philo->settings->dead_flag == true)
			return (NULL);
		time = get_current_time() - philo->last_meal;
		if (time >= philo->time_to_die)
		{
			pthread_mutex_lock(philo->settings->print);
			philo->settings->dead_flag = true;
			usleep(100);
			printf("%d %d died\n", get_current_time() - philo->start_time, philo->id);
			pthread_mutex_unlock(philo->settings->print);
			return (NULL);
		}
		usleep(500);
	}
}

void *action(void *p_philo)
{
	t_philo *philo;

	philo = (t_philo *)p_philo;
	philo->last_meal = get_current_time();
	if (pthread_create(&philo->dead_thread, NULL, is_dead, philo))
		error_print("pthread_create failed", philo->settings, philo);
	while(1)
	{
		if (eat(philo->settings, philo))
			return (NULL);
		if (sleep_and_think(philo->settings, philo))
			return (NULL);
	}
	return (NULL);
}
