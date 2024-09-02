#include "../philo.h"

void    error_print(char *str)
{
	printf("%s\n", str);
	exit(1);
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
				error_print("Error: Wrong argument");
			j++;
		}
		i++;
	}
}

void input_check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		error_print("Error: Wrong argument");
	check_args(argc, argv);
}

void print_message(t_setting *settings, t_philo *philo, char *str)
{
	usleep(100);
	pthread_mutex_lock(settings->print);
	printf("%d %d ", get_current_time() - philo->start_time, philo->id);
	printf("%s\n", str);
	pthread_mutex_unlock(settings->print);
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
