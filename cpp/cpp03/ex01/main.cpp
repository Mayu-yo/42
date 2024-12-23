#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	ClapTrap a("a");
	ClapTrap b("b");
	ScavTrap c("c");
	ScavTrap d("d");

	std::cout << " --- a's turn --- " << std::endl;
	a.attack("b");	
	b.takeDamage(5);
	std::cout << " --- b's turn --- " << std::endl;
	b.beRepaired(3);
	b.attack("a");
	a.takeDamage(5);
	std::cout << " --- c's turn --- " << std::endl;
	c.attack("d");
	d.takeDamage(5);
	std::cout << " --- d's turn --- " << std::endl;
	d.attack("c");
	c.takeDamage(5);
	d.guardGate();
	std::cout << " ------ " << std::endl;

	return 0;
}