#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <cmath>

class Fixed{
	public:
		Fixed( void );				//Default Constructor
		Fixed (int const nb);
		Fixed (float const nb);
		Fixed(Fixed const & src);
		~Fixed(void);
		Fixed & operator=(Fixed const &src);
		float	toFloat( void ) const;
		int		toInt( void ) const;

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
	private:
		int		_fixedPoint;
		static int const _fractionalBit = 8;
};

std::ostream &	operator<<( std::ostream & out, Fixed const & in );

#endif
