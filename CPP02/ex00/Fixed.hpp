#ifndef FIXED_H
#define FIXED_H

#include <iostream>

class Fixed{
	public:
		Fixed();						//Canonical
		Fixed( int const n );
		Fixed(Fixed const & src);		//Canonical Copy constructor
		~Fixed();

		Fixed &	operator=(Fixed const & src); //Canonical Copy assignment operator

		int getRawBits( void ) const;
		void setRawBits( int const raw );
	private:
		int	_fixedPoint;
		static int const	_raw;
};

#endif
