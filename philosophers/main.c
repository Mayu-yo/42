#include "philo.h"

// 食べ始められない時は？

// 一人の時
// 食べる回数が決まってる時
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
	argv[2] = "600";
	argv[3] = "200";
	argv[4] = "200";
	argv[5] = "7";
	/* ------------------------------------------------- */

	
	input_check(argc, argv);
	settings = init_data(argc, argv);
	init_mutex(settings);
	philos = init_philo(settings);
	thread_init(philos, settings);
	thread_destroy(philos, settings);

	return (0);
}