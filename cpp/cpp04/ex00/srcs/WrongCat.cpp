#include "WrongCat.hpp"

WrongCat::WrongCat(void) : WrongAnimal("WrongCat") {
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat::WrongCat(std::string type) : WrongAnimal(type) {
	std::cout << "WrongCat constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &rhs) {
	// *this = rhs;
	_type = rhs._type;
	std::cout << "WrongCat copy constructor called" << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
}