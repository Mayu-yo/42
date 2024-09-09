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
		if (pthread_join(philos[i].thread, NULL))
			error_print("pthread_join failed");
		if (pthread_join(philos[i].dead_thread, NULL))
			error_print("pthread_join failed");
		i++;
	}
	if (pthread_mutex_destroy(settings->print))
		error_print("pthread_mutex_destroy failed 1");
	i = 0;
	while (i < settings->philo_num)
	{
		if (pthread_mutex_destroy(&settings->fork[i]))
			// error_print("pthread_mutex_destroy failed 2");
			printf("pthread_mutex_destroy failed id: %d\n", i);
		i++;
	}
	free(settings->fork);
	free(settings->print);
	free(settings);
	free(philos);
}