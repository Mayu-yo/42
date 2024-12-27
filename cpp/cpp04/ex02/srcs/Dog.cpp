#include "Dog.hpp"

Dog::Dog(void) : AAnimal("Dog") {
	this->_brain = new Brain();
	if (!this->_brain)
		std::cout << "Failed to allocate memory for brain" << std::endl;
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(std::string type) : AAnimal(type) {
	this->_brain = new Brain();
	if (!this->_brain)
		std::cout << "Failed to allocate memory for brain" << std::endl;
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &rhs) : AAnimal(rhs) {
	this->_brain = new Brain(*rhs._brain);
	if (!this->_brain)
		std::cout << "Failed to allocate memory for brain" << std::endl;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &rhs) {
	if (this != &rhs) {
		AAnimal::operator=(rhs);
		delete this->_brain;
		this->_brain = new Brain(*rhs._brain);
		if (!this->_brain)
			std::cout << "Failed to allocate memory for brain" << std::endl;
	}
	std::cout << "Dog assignation operator called" << std::endl;
	return *this;
}

Dog::~Dog(void) {
	delete this->_brain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Woof" << std::endl;
}