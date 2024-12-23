#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat") {
	std::cout << "Cat constructor called" << std::endl;
	this->_brain = new Brain();
	if (!this->_brain)
		std::cout << "Failed to allocate memory for brain" << std::endl;
}

Cat::~Cat(void) {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
}
