#include "../includes/Brain.hpp"

Brain::Brain(void) {
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain &rhs) {
	// *this = rhs;
	for (int i = 0; i < 100; i++) {
		ideas[i] = rhs.ideas[i];
	}
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain &Brain::operator=(Brain const &rhs) {
	for (int i = 0; i < 100; i++) {
		ideas[i] = rhs.ideas[i];
	}
	std::cout << "Brain assignation operator called" << std::endl;
	return *this;
}

Brain::~Brain() {
	std::cout << "Brain destructor called" << std::endl;
}