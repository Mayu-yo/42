#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <math.h>

class Fixed
{
	public:
		Fixed( void );
		Fixed( int const raw );
		Fixed( float const raw );
		Fixed( Fixed const & src );
		Fixed & operator=( Fixed const & rhs );
		~Fixed( void );
		int getRawBits( void ) const;
		int setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
	private:
		int _raw;
		static const int _bits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);

#endif
