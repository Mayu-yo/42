#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>

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

		bool operator>( Fixed const & rhs ) const;
		bool operator<( Fixed const & rhs ) const;
		bool operator>=( Fixed const & rhs ) const;
		bool operator<=( Fixed const & rhs ) const;
		bool operator==( Fixed const & rhs ) const;
		bool operator!=( Fixed const & rhs ) const;

		Fixed operator+( Fixed const & rhs ) const;
		Fixed operator-( Fixed const & rhs ) const;
		Fixed operator*( Fixed const & rhs ) const;
		Fixed operator/( Fixed const & rhs ) const;

		Fixed operator++( void );//前置
		Fixed operator++( int );//後置
		Fixed operator--( void );//前置
		Fixed operator--( int );//後置
		
		static Fixed & max(Fixed & a, Fixed & b);
		static Fixed const & max(Fixed const & a, Fixed const & b);
		static Fixed & min(Fixed & a, Fixed & b);
		static Fixed const & min(Fixed const & a, Fixed const & b);
		
	private:
		int _raw;
		static const int _bits = 8;
};

std::ostream & operator<<(std::ostream & o, Fixed const & rhs);


#endif
