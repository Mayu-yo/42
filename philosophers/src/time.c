#include "../philo.h"

int	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		error_print("gettimeofday error");
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int	ft_usleep(int milliseconds)
{
	int	start;

	start = get_current_time();
	while ((get_current_time() - start) < milliseconds)
		usleep(500);
	return (0);
}