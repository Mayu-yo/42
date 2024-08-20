#include "philo.h"

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
	init(argc, argv, settings, philos);
	
	return (0);
}