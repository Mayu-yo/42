#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {
	ClapTrap a;
	ClapTrap b("b");
	ScavTrap c;
	ScavTrap d("d");

	a.attack("b");	
	b.takeDamage(5);
	b.beRepaired(3);
	b.attack("a");
	a.takeDamage(5);
	b.attack("a");
	a.takeDamage(5);
	c.attack("d");
	d.takeDamage(5);
	d.attack("c");
	c.takeDamage(5);
	d.guardGate();
	c.attack("d");
	d.takeDamage(5);
	c.guardGate();

	return 0;
}