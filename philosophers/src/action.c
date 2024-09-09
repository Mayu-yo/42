#include "../philo.h"


int eat(t_setting *settings, t_philo *philo)
{
	if (take_fork(settings, philo))
	{
		drop_fork(philo);
		return (1);
	}
	if (print_message(settings, philo, "is eating"))
	{
		drop_fork(philo);
		return (1);
	}
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