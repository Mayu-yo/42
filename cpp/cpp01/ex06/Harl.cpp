#include "Harl.hpp"

Harl::Harl(void)
{
}

Harl::~Harl(void)
{
}

void Harl::complain(std::string level)
{
	int level_num;
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*funcs[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (level_num = 0; level_num < 4; level_num++)
	{
		if (level == levels[level_num])
			break;
	}
	switch (level_num)
	{
	case 0:
		(this->*funcs[0])();
	case 1:
		(this->*funcs[1])();
	case 2:
		(this->*funcs[2])();
	case 3:
		(this->*funcs[3])();
		break;
	
	default:
		std::cerr << "Error: unknown level" << std::endl;
		break;
	}
}

void Harl::debug(void)
{
	std::cout << "[Debug]" << std::endl;
	std::cout << "This is a debug message" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[Info]" << std::endl;
	std::cout << "This is an info message" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[Warning]" << std::endl;
	std::cout << "This is a warning message" << std::endl;
}

void Harl::error(void)
{
	std::cout << "[Error]" << std::endl;
	std::cout << "This is an error message" << std::endl;
}


