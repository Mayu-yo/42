#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void signal_handler(int signal, siginfo_t *info, void *context) {
    static int	bit;
	static int	i;

	if (signal == SIGUSR1)
		i |= (0x01 << bit);
	bit++;
	if (bit == 8)
	{
		printf("%c", i);
		if(kill(info->si_pid, SIGUSR1) == -1)
		{
			printf("error\n");
			exit(1);
		}
		bit = 0;
		i = 0;
	}
}

int main() {
	struct sigaction act1;
	// struct sigaction act2;

	printf("%d\n", getpid());
	act1.sa_sigaction = signal_handler;
	// act2.sa_sigaction = signal_handler2;
	sigemptyset(&act1.sa_mask);
	// sigemptyset(&act2.sa_mask);
	act1.sa_flags = SA_SIGINFO;
	// act2.sa_flags = SA_SIGINFO;
	act1.sa_flags = 0;
	// act2.sa_flags = 0;
	sigaddset(&act1.sa_mask, SIGUSR2);
	sigaddset(&act1.sa_mask, SIGUSR1);
	sigaction(SIGUSR1, &act1, NULL);//失敗処理？
	sigaction(SIGUSR2, &act1, NULL);
	while (1)
		pause();
}
