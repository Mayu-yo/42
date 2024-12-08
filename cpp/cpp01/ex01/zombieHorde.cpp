#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name ) {
	Zombie *zombies = new Zombie[N];
	if (!zombies) {
		std::cerr << "Error: could not allocate memory" << std::endl;
		return NULL;
	}
	for (int i = 0; i < N; i++) {
		zombies[i].setName(name + std::to_string(i));
	}
	return zombies;
}