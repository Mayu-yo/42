#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>

// int main()
// {
// 	int i = 0;
// 	int ret = 0;
// 	char str = 'a';

// 	for (i = 0; i < 8; i++)
// 	{
// 		ret = (str & (0x01 << i));
// 		if (ret != 0)
// 			printf("1");
// 		else
// 			printf("0");
// 	}
	
// }

// volatile sig_atomic_t g_char = 0;

// void signal_handler(int signum, siginfo_t *info,void *dummy)
// {
// 	write(STDOUT_FILENO, "SIGUSR1\n", 8);
// 	g_char = 1;
// 	while (g_char == 1)
// 		;
// 	write(STDOUT_FILENO, "handler1 end\n", 13);
// }

void signal_handler2(int signum, siginfo_t *info,void *dummy)
{
	write(STDOUT_FILENO, "SIGUSR2\n", 8);
	g_char = 0;
	write(STDOUT_FILENO, "handler2 end\n", 13);
}

int main() {
	struct sigaction act1;
	struct sigaction act2;

	printf("%d\n", getpid());
	memset(&act1, 0, sizeof(sigaction));
	memset(&act2, 0, sizeof(sigaction));
	act1.sa_sigaction = signal_handler;
	act2.sa_sigaction = signal_handler2;
	act1.sa_flags = SA_SIGINFO;
	act2.sa_flags = SA_SIGINFO;
	sigaddset(&act1.sa_mask, SIGUSR2);
	sigaddset(&act1.sa_mask, SIGUSR2);
	sigaction(SIGUSR1, &act1, NULL);
	sigaction(SIGUSR2, &act2, NULL);
	while (1)
		pause();
}

