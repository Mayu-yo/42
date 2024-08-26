#include "../philo.h"

// void monitoring()
// {

// }

void thread_init(t_philo *philos, t_setting *settings)
{
	int i;

	i = 0;
	if (pthread_mutex_init(settings->fork, NULL))
		error_print("pthread_init failed");
	philos->start_time = get_current_time();
	while (i < settings->philo_num)
	{
		if (pthread_create(philos[i].thread, NULL, &action, (&philos[i])))
			error_print("pthread_create failed");
		i++;
	}
}

void thread_destroy(t_philo *philos, t_setting *settings)
{
	int i;

	i = 0;
	while (i < settings->philo_num)
	{
		if (pthread_join(*philos[i].thread, NULL))
			error_print("pthread_join failed");
		i++;
	}
	if (pthread_mutex_destroy(settings->fork))
		error_print("pthread_mutex_destroy failed");
}