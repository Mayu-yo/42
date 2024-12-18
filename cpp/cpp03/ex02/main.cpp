#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
	ClapTrap clapTrap("ClapTrap");
	ScavTrap scavTrap("ScavTrap");
	FragTrap fragTrap("FragTrap");

	std::cout << "- Start -" << std::endl;
	std::cout << "ClapTrap's Turn." << std::endl;
	clapTrap.attack("ScavTrap");
	scavTrap.takeDamage(10);
	scavTrap.beRepaired(5);
	scavTrap.guardGate();
	std::cout << "ScavTrap's Turn." << std::endl;
	scavTrap.attack("FragTrap");
	fragTrap.takeDamage(10);
	fragTrap.beRepaired(5);
	fragTrap.highFivesGuys();
	std::cout << "FragTrap's Turn." << std::endl;
	fragTrap.attack("ClapTrap");
	clapTrap.takeDamage(10);
	clapTrap.beRepaired(5);
	std::cout << "- End -" << std::endl;

	return 0;
}