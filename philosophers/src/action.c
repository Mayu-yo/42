#include "../philo.h"

int is_dead(t_philo *philo)
{
	int time;
	
	pthread_mutex_lock(philo->settings->dead);
	time = get_current_time() - philo->last_meal;
	if (time >= philo->time_to_die)
	{
		// philo->settings->dead = 1;
		print_message(philo->settings, philo, "died");
		pthread_mutex_unlock(philo->settings->dead);
		return (1);
	}
	pthread_mutex_unlock(philo->settings->dead);
	return (0);
}

void *action(void *p_philo)//time_to_deadの情報が必要
{
	t_philo *philo;

	philo = (t_philo *)p_philo;
	philo->last_meal = get_current_time();//
	//time_to_dead超えたらdeadフラグ建てる
	while (!is_dead(philo))
	{
		
		// if (get_current_time() - philo->last_meal > philo->time_to_die)
		// {
		// 	philo->dead = 1;
		// 	print_message(philo->settings, philo, "died");
		// 	break ;
		// }
		// printf("philo id: %d", philo->id);
		// printf("action\n");
		eat(philo->settings, philo);
		sleep_and_think(philo->settings, philo);
	}
	return (NULL);
}

void eat(t_setting *settings, t_philo *philo)
{
	// printf("philo id: %d", philo->id);
	// printf("eat\n");
	take_fork(settings, philo);
	print_message(settings, philo, "is eating");
	ft_usleep(settings->time_to_eat);
	philo->last_meal = get_current_time();
	drop_fork(philo);
}

void take_fork(t_setting *settings, t_philo *philo)
{
	// printf("philo id: takefork%d\n", philo->id);
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