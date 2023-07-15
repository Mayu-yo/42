//引数で　PID と　文字列　受け取る
//
#include "libft/libft.h"
#include <signal.h>

void send_char(int pid, char str) {
	int i;

	i = 0;
	while (i < 8)
	{
		if ((str & (0x01 << i)) != 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
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
	// result = kill(pid, atoi(argv[2]));
    // if (result == -1)
	// 	return (0);
	while (argv[2][i])
	{
		send_char(pid, argv[2][i]);
		i++;
	}
	send_char(pid, '\n');
    return 0;
}
