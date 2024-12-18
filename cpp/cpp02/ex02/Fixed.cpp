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
	std::cout << "Copy assignment operator called" << std::endl;
	this->_raw = rhs.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return this->_raw;
}

int Fixed::setRawBits(int const raw)
{
	// std::cout << "setRawBits member function called" << std::endl;
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

/* Comparison operators */

bool Fixed::operator>(Fixed const &rhs) const
{
	return this->_raw > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const &rhs) const
{
	return this->_raw < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const
{
	return this->_raw >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const
{
	return this->_raw <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const
{
	return this->_raw == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const &rhs) const
{
	return this->_raw != rhs.getRawBits();
}

/* Arithmethic operators */

Fixed Fixed::operator+(Fixed const &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

/* Increment/Decrement operators */

//前置インクリメント
Fixed Fixed::operator++(void)
{
	this->_raw++;
	return *this;
}

//後置インクリメント
Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	operator++();
	return tmp;
}

//前置デクリメント
Fixed Fixed::operator--(void)
{
	this->_raw--;
	return *this;
}

//後置デクリメント
Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	operator--();
	return tmp;
}

/* Static member functions */

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

Fixed const &Fixed::max(Fixed const &a, Fixed const &b)
{
	return a > b ? a : b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

Fixed const &Fixed::min(Fixed const &a, Fixed const &b)
{
	return a < b ? a : b;
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs)
{
	o << rhs.toFloat();
	return o;
}

