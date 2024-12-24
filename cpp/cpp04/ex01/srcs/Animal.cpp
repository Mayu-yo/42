#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(std::string type) {
	_type = type;
	std::cout << "Animal constructor called" << std::endl;
}

Animal::Animal(const Animal &rhs) {
	*this = rhs;
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs) {
	_type = rhs._type;
	std::cout << "Animal assignation operator called" << std::endl;
	return *this;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

void Animal::makeSound(void) const {
	std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType(void) const {
	return _type;
}