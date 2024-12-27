#include "Dog.hpp"

Dog::Dog(void) : Animal("Dog") {
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void) {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(std::string type) : Animal(type) {
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog &rhs) {
	// *this = rhs;
	_type = rhs._type;
	std::cout << "Dog copy constructor called" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Woof" << std::endl;
}