#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap a;
	ClapTrap b("b");
	
	a.attack("b");
	b.takeDamage(5);
	b.beRepaired(3);
	b.attack("a");
	a.takeDamage(5);
	b.attack("a");
	a.takeDamage(5);
	b.attack("a");
	a.takeDamage(5);

	return 0;
}