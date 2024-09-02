#include "philo.h"

// void test(t_philo *philo, t_setting *settings)
// {
// 	philo->start_time = get_current_time();
// 	action(philo);
// }

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

	
	input_check(argc, argv);
	settings = init_data(argc, argv);
	init_mutex(settings);
	philos = init_philo(settings);
	// test(philos, settings);
	thread_init(philos, settings);
	thread_destroy(philos, settings);

	return (0);
}