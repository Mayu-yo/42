#include "../philo.h"

void *init(int argc, char **argv, t_setting *settings, t_philo *philos)
{
	// settings = malloc(sizeof(t_setting));
	// if (!settings)
	// 	error_print("malloc error");
	init_data(argc, argv, settings);
	alloc(philos, settings);
	init_fork(settings);
	init_philo(philos, settings);
	return ((void *)0);
}

void alloc(t_philo *philos, t_setting *settings)
{
	settings->fork = malloc(sizeof(pthread_mutex_t) * settings->philo_num + 1);
	if (!settings->fork)
	{
		free(settings);
		error_print("malloc error");
	}
	// philos = malloc(sizeof(t_philo) * settings->philo_num);
	settings->philos = malloc(sizeof(t_philo) * settings->philo_num);
	if (!settings->philos)
	{
		free(settings->fork);
		free(settings);
		error_print("malloc error");
	}
}

void init_data(int argc, char **argv, t_setting *settings)
{
	settings->philo_num = ft_atoi(argv[1]);
	settings->time_to_die = ft_atoi(argv[2]);
	settings->time_to_eat = ft_atoi(argv[3]);
	settings->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		settings->must_eat_times = ft_atoi(argv[5]);
	else
		settings->must_eat_times = -1;
}

void init_fork(t_setting *settings)
{
	int i;

	i = 1;
	pthread_mutex_init(settings->fork, NULL);
	while (i > 0 && i < settings->philo_num)
	{
		pthread_mutex_init(settings->fork, NULL);
		i++;
	}
}

void init_philo(t_philo *philos, t_setting *settings)
{
	int i;

	i = 0;
	philos->settings = settings;
	while (i < settings->philo_num)
	{
		philos[i].id = i;
		philos[i].thread = malloc(sizeof(pthread_t));
		// philos[i].settings = settings;
		philos[i].last_meal = 0;
		philos[i].start_time = 0;
		philos[i].dead = 0;
		philos[i].time_to_die = settings->time_to_die;
		philos[i].l_fork = &settings->fork[i - 1];
		philos[i].r_fork = &settings->fork[i];
		i++;
	}
}
