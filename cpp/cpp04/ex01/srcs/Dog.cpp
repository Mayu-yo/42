#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	this->_brain = new Brain();
	if (!this->_brain)
		std::cout << "Failed to allocate memory for brain" << std::endl;
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void) {
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Woof" << std::endl;
}