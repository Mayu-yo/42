#include <signal.h>
// #include "./printf/ft_printf.h"
#include <stdio.h>
#include <unistd.h>

void signal_handler(int signal_number)
{
	static int	bit;
	static int	i;

	if (signal_number == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
		bit = 0;
		i = 0;
	}
}


int main() {
	int pid;

	pid = getpid();
	printf("%d\n", pid);
	while (1) {
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
		pause();
	}

    return 0;
}
