#include "../philo.h"

void monitoring()
{

}

void action(void *p_philo)//time_to_deadの情報が必要
{
	t_philo *philo;

	philo = (t_philo *)p_philo;
	//time_to_dead超えたらdeadフラグ建てる
}

void thread_init(t_philo *philos, t_setting *settings)
{
	int i;
	pthread_t monitor;

	i = 0;
	pthread_mutex_init
	philos->start_time = get_current_time();
	while (i < settings->philo_num)
	{
		if (pthread_create(&philos[i], NULL, &action, (&philos[0])))
			error_print("pthread_create failed");
		i++;
	}
	i = 0;
	while (i < settings->philo_num)
	{
		if (pthread_join(&philos[i], NULL))
			error_print("pthread_join failed");
		i++;
	}
}