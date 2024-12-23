#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	this->_name = "default";
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	std::cout << "FragTrap constructor called." << std::endl;
}

FragTrap::FragTrap(const FragTrap &rhs)
{
	*this = rhs;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs)
{
	ClapTrap::operator=(rhs);
	std::cout << "FragTrap assignation operator called" << std::endl;
	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap destructor called." << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->_name << " requests a high five!" << std::endl;
}
