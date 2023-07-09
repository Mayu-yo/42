// #include "push_swap.h"
#include "../libft/libft.h"
#include <stdio.h>

int ft_doublequoted_arguments(int argc, char **argv)
{
	char **str;

	str = NULL;
	if (argv[1][0] == '"' && argv[1][ft_strlen(argv[1]) - 1] == '"')
	{
		str = ft_split(argv[1], '"');
		str = ft_split(str[0], ' ');
	}
	return (0);
}

int main (int argc, char **argv)
{
	argc = 2;
	argv[0] = "./push_swap";
	argv[1] = "\"0 3 5 2\"";
	ft_doublequoted_arguments(argc, argv);
	return (0);
}