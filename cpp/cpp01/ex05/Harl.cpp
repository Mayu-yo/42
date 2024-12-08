#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void Harl::complain(std::string level)
{
	if (level == "DEBUG")
		debug();
	else if (level == "INFO")
		info();
	else if (level == "WARNING")
		warning();
	else if (level == "ERROR")
		error();
	else
		std::cerr << "Error: unknown level" << std::endl;
}

void Harl::debug(void)
{
	std::cout << "Debug" << std::endl;
}

void Harl::info(void)
{
	std::cout << "Info" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "Warning" << std::endl;
}

void Harl::error(void)
{
	std::cout << "Error" << std::endl;
}
