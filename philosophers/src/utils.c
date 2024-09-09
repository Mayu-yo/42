#include "../philo.h"

void    error_print(char *str, t_setting *settings, t_philo *philos)
{
	if (settings || philos)
		ft_exit(philos, settings);
	printf("%s\n", str);
	exit(1);
}


void ft_exit(t_philo *philo, t_setting *settings)
{
	int i;

	i = 0;
	pthread_mutex_destroy(settings->print);
		// error_print("pthread_mutex_destroy failed", settings, philo);
	while (i < settings->philo_num)
	{
		pthread_mutex_destroy(&settings->fork[i]);
			// error_print("pthread_mutex_destroy failed", settings, philo);
		i++;
	}
	free_all(philo, settings);
}

void free_all(t_philo *philos, t_setting *settings)
{
	if (settings->fork)
		free(settings->fork);
	if (settings->print)
		free(settings->print);
	if (settings)
		free(settings);
	if (philos)
		free(philos);
}

void    check_args(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				error_print("Error: Wrong argument", NULL, NULL);
			j++;
		}
		i++;
	}
}

void input_check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		error_print("Error: Wrong argument", NULL, NULL);
	check_args(argc, argv);
}

int print_message(t_setting *settings, t_philo *philo, char *str)
{
	usleep(1);
	if (philo->settings->dead_flag == true)
		return (1);
	pthread_mutex_lock(settings->print);
	printf("%d %d ", get_current_time() - philo->start_time, philo->id);
	printf("%s\n", str);
	pthread_mutex_unlock(settings->print);
	return (0);
}

static int	skip_space(const char *str)
{
	int	i;

	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	num;
	int		minus;

	minus = 1;
	i = skip_space(str);
	num = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			minus *= -1;
		i++;
	}
	while (str[i] == '0')
		i++;
	while ('0' <= str[i] && str[i] <= '9')
	{
		if (num > ((LONG_MAX - (str[i] - '0')) / 10) && minus == 1)
			return ((int)(LONG_MAX));
		if (num - (1 / 10) > (LONG_MAX - (str[i] - '0')) / 10 && minus == -1)
			return ((int)(LONG_MIN));
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * minus);
}

int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
