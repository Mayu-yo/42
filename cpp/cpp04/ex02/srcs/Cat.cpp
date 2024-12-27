#include "Cat.hpp"

Cat::Cat(void) : AAnimal("Cat") {
	std::cout << "Cat constructor called" << std::endl;
	this->_brain = new Brain();
	if (!this->_brain)
		std::cout << "Failed to allocate memory for brain" << std::endl;
}

Cat::Cat(std::string type) : AAnimal(type) {
	std::cout << "Cat constructor called" << std::endl;
	this->_brain = new Brain();
	if (!this->_brain)
		std::cout << "Failed to allocate memory for brain" << std::endl;
}

Cat::~Cat(void) {
	delete this->_brain;
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &rhs) : AAnimal(rhs) {
	this->_brain = new Brain(*rhs._brain);
	if (!this->_brain)
		std::cout << "Failed to allocate memory for brain" << std::endl;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &rhs) {
	if (this != &rhs) {
		AAnimal::operator=(rhs);
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
		if (!this->_brain)
			std::cout << "Failed to allocate memory for brain" << std::endl;
	}
	std::cout << "Cat assignation operator called" << std::endl;
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
}
