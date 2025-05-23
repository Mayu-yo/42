#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

class Fixed
{
	public:
		Fixed( void );
		Fixed( Fixed const & src );
		Fixed & operator=( Fixed const & rhs );
		~Fixed( void );
		int getRawBits( void ) const;
		int setRawBits( int const raw );
	private:
		int _raw;
		static const int _bits = 8;
};

#endif