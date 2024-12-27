#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog &rhs) {
	_type = rhs._type;
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs) {
	Animal::operator=(rhs);
	if (this != &rhs)
		_type = rhs._type;
	std::cout << "Dog assignation operator called" << std::endl;
	return *this;
}

void Dog::makeSound(void) const {
	std::cout << "Woof" << std::endl;
}