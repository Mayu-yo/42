#include "../philo.h"

void *action(void *p_philo)//time_to_deadの情報が必要
{
	t_philo *philo;

	philo = (t_philo *)p_philo;
	//time_to_dead超えたらdeadフラグ建てる
	while (1)
	{
		if (get_current_time() - philo->last_meal > philo->time_to_die)
		{
			philo->dead = 1;
			print_message(philo->settings, philo, "died");
			break ;
		}
		eat(philo->settings, philo);
		sleep_and_think(philo->settings, philo);
	}
	return ((void *)0);
}

void eat(t_setting *settings, t_philo *philo)
{
	take_fork(settings, philo);
	print_message(settings, philo, "is eating");
	philo->last_meal = get_current_time();
	ft_usleep(settings->time_to_eat);
	drop_fork(philo);
}

void take_fork(t_setting *settings, t_philo *philo)
{
	pthread_mutex_lock(philo->r_fork);
	print_message(settings, philo, "has taken a fork");
	pthread_mutex_lock(philo->l_fork);
	print_message(settings, philo, "has taken a fork");
}

void drop_fork(t_philo *philo)
{
	pthread_mutex_unlock(philo->r_fork);
	pthread_mutex_unlock(philo->l_fork);
}

void sleep_and_think(t_setting *settings, t_philo *philo)
{
	print_message(settings, philo, "is sleeping");
	ft_usleep(settings->time_to_sleep);
	print_message(settings, philo, "is thinking");
}