#include "../philo.h"

void monitoring()
{

}

void *action(void *p_philo)//time_to_deadの情報が必要
{
	t_philo *philo;

	philo = (t_philo *)p_philo;
	//time_to_dead超えたらdeadフラグ建てる
}

void eat()
{

}



void thread_init(t_philo *philos, t_setting *settings)
{
	int i;

	i = 0;
	if (pthread_mutex_init(settings->fork, NULL))
		error_print("pthread_init failed");
	philos->start_time = get_current_time();
	while (i < settings->philo_num)
	{
		if (pthread_create(&philos[i], NULL, &action, (&philos[i])))
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
		if (pthread_join(&philos[i], NULL))
			error_print("pthread_join failed");
		i++;
	}
	if (pthread_mutex_destroy(settings->fork))
		error_print("pthread_mutex_destroy failed");
}