#include "../philo.h"

void    error_print(char *str)
{
	printf("%s\n", str);
	exit(1);
}

void    check_args(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (ft_isdigit(argv[i][j]) == 0)
				error_print("Error: Wrong argument");
			j++;
		}
		i++;
	}
}

void input_check(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		error_print("Error: Wrong argument");
	check_args(argc, argv);
}


