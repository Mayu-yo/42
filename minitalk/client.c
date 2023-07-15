//引数で　PID と　文字列　受け取る
//
#include "libft/libft.h"
#include <signal.h>

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


int main(int argc, char **argv) {
	int i;
	int pid;
	int result;

	i = 0;
	if (argc != 3)
		return (0);
	pid = atoi(argv[1]);//zisakukannsunikaeru!
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\n');
    return 0;
}
