#include "AAnimal.hpp"

AAnimal::AAnimal(void) {
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(std::string type) {
	_type = type;
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal &rhs) {
	_type = rhs._type;
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs) {
	if (this != &rhs)
		_type = rhs._type;
	std::cout << "AAnimal assignation operator called" << std::endl;
	return *this;
}

AAnimal::~AAnimal() {
	std::cout << "AAnimal destructor called" << std::endl;
}

void AAnimal::makeSound(void) const {
	std::cout << "Animal sound" << std::endl;
}

std::string AAnimal::getType(void) const {
	return _type;
}