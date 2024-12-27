#include "Cat.hpp"

Cat::Cat(void) : Animal("Cat") {
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat(void) {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat &rhs) {
	_type = rhs._type;
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs) {
	Animal::operator=(rhs);
	if (this != &rhs)
		_type = rhs._type;
	std::cout << "Cat assignation operator called" << std::endl;
	return *this;
}

void Cat::makeSound(void) const {
	std::cout << "Meow" << std::endl;
}
