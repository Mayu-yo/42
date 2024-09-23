#include "philo.h"

// 食べる回数が決まってる時

// 一人の時
// 終了処理
// leakないか確認
// 死なない
// 死亡監視

int main (int argc, char **argv)
{
	t_setting 		*settings;
	t_philo			*philos;

	/* ----------------- vscode debug ------------------ */																	
	argc = 6;
	argv[1] = "5";
	argv[2] = "800";
	argv[3] = "200";
	argv[4] = "200";
	argv[5] = "7";
	/* ------------------------------------------------- */

	
	if (input_check(argc, argv))
		return (1);
	settings = init_data(argc, argv);
	if (init_mutex(settings))
		return (1);
	philos = init_philo(settings);
	if (!philos)
		return (1);
	if (thread_init(philos, settings))
		return (1);
	ft_exit(philos, settings);

	return (0);
}

__attribute__((destructor)) static void destructor()
{
	system("leaks -q philo");
}
