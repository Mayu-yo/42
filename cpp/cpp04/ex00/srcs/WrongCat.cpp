#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs) {
	_type = rhs._type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs) {
	WrongAnimal::operator=(rhs);
	if (this != &rhs)
		_type = rhs._type;
	std::cout << "WrongCat assignation operator called" << std::endl;
	return *this;
}

void WrongCat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
}