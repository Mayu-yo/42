#include "../philo.h"

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
		error_print("pthread_create failed");
	while(1)
	{
		if (eat(philo->settings, philo))
			return (NULL);
		if (sleep_and_think(philo->settings, philo))
			return (NULL);
	}
	return (NULL);
}

int eat(t_setting *settings, t_philo *philo)
{
	if (take_fork(settings, philo))
		return (1);
	if (print_message(settings, philo, "is eating"))
		return (1);
	ft_usleep(settings->time_to_eat);
	philo->last_meal = get_current_time();
	drop_fork(philo);
	return (0);
}

int take_fork(t_setting *settings, t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		pthread_mutex_lock(philo->r_fork);
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		pthread_mutex_lock(philo->l_fork);
	}
	philo->last_meal = get_current_time();
	if (print_message(settings, philo, "has taken a fork"))
		return (1);
	return (0);
}

void drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

int sleep_and_think(t_setting *settings, t_philo *philo)
{
	if (print_message(settings, philo, "is sleeping"))
		return (1);
	ft_usleep(settings->time_to_sleep);
	if (print_message(settings, philo, "is thinking"))
		return (1);
	return (0);
}