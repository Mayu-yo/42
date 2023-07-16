#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>

void send_char(int pid, char str) {
	int i;
	int result;

	i = 0;
	while (i < 8)
	{
		if ((str & (0x01 << i)) != 0)
		{
			result = kill(pid, SIGUSR1);
			if (result == -1)
				exit (0);
		}
		else
		{
			result = kill(pid, SIGUSR2);
			if (result == -1)
				exit (0);
		}
		usleep(50);
		i++;
	}
}

// static int	skip_space(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
// 		i++;
// 	return (i);
// }
int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}

int	ft_atoi_pid(const char *str)
{
	int		i;
	long	num;

	i = 0;
	num = 0;
	while (str[i])
	{
		if(!ft_isdigit(str[i]))
			return (-1);
		num = num * 10 + str[i] - '0';
		if (num > ((INT_MAX - (str[i] - '0')) / 10))
			return (-1);
		i++;
	}
	return (num);
}


int main(int argc, char **argv) {
	int i;
	int pid;
	int result;

	i = 0;
	if (argc != 3)
	{
		printf("Usase: ./client [PID] [message]");
		return (0);
	}
	pid = ft_atoi_pid(argv[1]);
	if(pid == -1)
	{
		printf("Usase: ./client [PID] [message]");
		return (0);
	}
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\n');
    return 0;
}
