#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap a("a");
	ClapTrap b("b");
	
	std::cout << " --- a's turn --- " << std::endl;
	a.attack("b");
	b.takeDamage(5);//attack初期値0だけどとりあえずダメージ
	std::cout << " --- b's turn --- " << std::endl;
	b.beRepaired(3);
	b.attack("a");
	a.takeDamage(10);
	std::cout << " --- if a is dead --- " << std::endl;
	b.beRepaired(3);
	b.attack("a");
	a.takeDamage(5);
	std::cout << " --- if a is out of energy --- " << std::endl;
	for (int i = 0; i < 7; i++)
		b.attack("a");
	std::cout << " ------ " << std::endl;

	return 0;
}