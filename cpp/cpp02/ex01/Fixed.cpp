#include "Fixed.hpp"

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_raw = 0;
}

Fixed::Fixed(int const raw)
{
	std::cout << "Int constructor called" << std::endl;
	this->_raw = raw << this->_bits;
}

Fixed::Fixed(float const raw)
{
	std::cout << "Float constructor called" << std::endl;
	this->_raw = roundf(raw * (1 << this->_bits));
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	this->setRawBits(src.getRawBits());
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Assignation operator called" << std::endl;
	this->_raw = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}

int Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_raw = raw;
	return 0;
}

//こっちは切り捨てちゃダメだからスケールで割る
float Fixed::toFloat(void) const
{
	return (float)this->_raw / (1 << this->_bits);
}

//シフトビットで切り捨て
int Fixed::toInt(void) const
{
	return this->_raw >> this->_bits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}

