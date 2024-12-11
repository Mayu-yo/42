#include "Zombie.hpp"

Zombie *newZombie(std::string name) {
	Zombie *zombie;

	zombie = new Zombie(name);
	if (!zombie) {
		std::cerr << "Error: could not allocate memory" << std::endl;
		return NULL;
	}
	return zombie;
}