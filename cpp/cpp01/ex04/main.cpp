#include "Sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cerr << "Usage: ./replace filename s1 s2" << std::endl;
		return 1;
	}
	if (av[2][0] == '\0' || av[3][0] == '\0')
	{
		std::cerr << "Error: s1 and s2 must not be empty" << std::endl;
		return 1;
	}
	Sed sed(av[1], av[2], av[3]);
	if (sed.replace())
		return 1;
	return 0;
}
