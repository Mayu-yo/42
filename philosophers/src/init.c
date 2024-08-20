#include "../philo.h"

void *init(int argc, char **argv, t_setting *settings, t_philo *philos)
{
	alloc(philos, settings);
	init_data(argc, argv, settings);
	init_philo(philos, settings);
	init_fork(settings);
}

void alloc(t_philo *philos, t_setting *settings)
{
	settings = malloc(sizeof(t_setting));
	if (!settings)
		error_print("malloc error");
	settings->fork = malloc(sizeof(pthread_mutex_t) * settings->philo_num + 1);
	if (!settings->fork)
	{
		free(settings);
		error_print("malloc error");
	}
	philos = malloc(sizeof(t_philo) * settings->philo_num);
	if (philos)
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

void init_philo(t_philo *philos, t_setting *settings)
{
	int i;

	i = 0;
	while (i < settings->philo_num)
	{
		philos[i].id = i;
		philos[i].last_meal = 0;
		philos[i].start_time = 0;
		philos[i].dead = 0;
		philos[i].time_to_die = settings->time_to_die;
		philos[i].l_fork = i;
		philos[i].r_fork = i + 1;
		i++;
	}
}

void init_fork(t_setting *settings)
{
	int i;

	i = 1;
	pthread_mutex_init(settings->fork, NULL);
	// settings->philos[i].l_fork = &settings->fork[settings->philo_num - 1];
	// settings->philos[i].r_fork = &settings->fork[0];
	while (i > 0 && i < settings->philo_num)
	{
		pthread_mutex_init(settings->fork, NULL);
		// settings->philos[i].l_fork = &settings->fork[i - 1];
		// settings->philos[i].r_fork = &settings->fork[i];
		i++;
	}
}
