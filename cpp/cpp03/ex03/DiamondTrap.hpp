#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string _name;

public:
	DiamondTrap(void);
	DiamondTrap(std::string name);
	DiamondTrap(const DiamondTrap &rhs);
	DiamondTrap &operator=(DiamondTrap const &rhs);
	~DiamondTrap(void);

	void whoAmI(void);
	using ScavTrap::attack;
};

#endif