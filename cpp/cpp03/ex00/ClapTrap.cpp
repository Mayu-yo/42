#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	this->_name = "default";
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " is born" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
{
	this->_name = name;
	this->_hitPoints = 10;
	this->_energyPoints = 10;
	this->_attackDamage = 0;
	std::cout << "ClapTrap " << this->_name << " is born" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &rhs)
{
	*this = rhs;
	std::cout << "copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hitPoints = rhs._hitPoints;
	this->_energyPoints = rhs._energyPoints;
	this->_attackDamage = rhs._attackDamage;
	return *this;
}

void ClapTrap::attack(const std::string& target)
{
	if (this->_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
	if (this->_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
		return ;
	}
	_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << " causing " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << this->_name << " is dead" << std::endl;
		return ;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is already dead!" << std::endl;
		return ;
	}
	if (_energyPoints == 0)
	{
		std::cout << "ClapTrap " << this->_name << " is out of energy!" << std::endl;
		return ;
	}
	_hitPoints += amount;
	_energyPoints -= 1;
	std::cout << "ClapTrap " << this->_name << " is repaired for " << amount << " points of damage!" << std::endl;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap destructor called" << std::endl;
}