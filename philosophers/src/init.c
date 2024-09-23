#include "../philo.h"

t_setting *init_data(int argc, char **argv)
{
	t_setting *settings;

	settings = (t_setting *)malloc(sizeof(t_setting));
	if (!settings)
		return (NULL);
	settings->philo_num = ft_atoi(argv[1]);
	settings->time_to_die = ft_atoi(argv[2]);
	settings->time_to_eat = ft_atoi(argv[3]);
	settings->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		settings->must_eat_times = ft_atoi(argv[5]);
	else
		settings->must_eat_times = -1;
	settings->dead_flag = false;
	return (settings);
}

int init_mutex(t_setting *settings)
{
	int i;

	i = 0;
	settings->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * settings->philo_num);
	if (!settings->fork)
		return (error_exit("malloc failed", settings, NULL));
	while (i < settings->philo_num)
	{
		pthread_mutex_init(&settings->fork[i], NULL);
		i++;
	}
	settings->print = malloc(sizeof(pthread_mutex_t));
	if (!settings->print)
		return (error_exit("malloc failed", settings, NULL));
	pthread_mutex_init(settings->print, NULL);
	return (0);
}

t_philo *init_philo(t_setting *settings)
{
	int i;
	t_philo *philos;

	i = 0;
	philos = (t_philo *)malloc(sizeof(t_philo) * settings->philo_num);
	if (!philos)
	{
		free_all(philos, settings);
		return (NULL);
	}
	while (i < settings->philo_num)
	{
		philos[i].id = i;
		philos[i].settings = settings;
		philos[i].last_meal = get_current_time();
		philos[i].start_time = 0;
		philos[i].time_to_die = settings->time_to_die;
		// philos[i].eat_count = 0;
		philos[i].l_fork = &settings->fork[i];
		if (i == settings->philo_num - 1)
			philos[i].r_fork = &settings->fork[0];
		else
			philos[i].r_fork = &settings->fork[i + 1];
		i++;
	}
	return (philos);
}
