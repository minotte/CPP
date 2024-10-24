#ifndef FIXED_H
#define FIXED_H

#include <iostream>
#include <ostream>

class Fixed{
	public:
		Fixed();
		Fixed(int nb);
		Fixed(float nb);
		Fixed(Fixed const &src);
		Fixed & operator=(Fixed const &src);
		~Fixed();
		
		/*	arithmetic operator	*/
		Fixed operator+(Fixed const &src) const;
		Fixed operator-(Fixed const &src) const;
		Fixed operator*(Fixed const &src) const;
		Fixed operator/(Fixed const &src) const;
		/*	comparison operator */
		bool operator==(Fixed const &src) const;
		bool operator!=(Fixed const &src) const;
		bool operator>=(Fixed const &src) const;
		bool operator<=(Fixed const &src) const;
		bool operator>(Fixed const &src) const;
		bool operator<(Fixed const &src) const;
		/*  min and max	*/
		static Fixed & min(Fixed &a, Fixed &b);
		static Fixed const & min(Fixed const &a, Fixed const &b);
		static Fixed & max(Fixed &a, Fixed &b);
		static Fixed const & max(Fixed const &a, Fixed const &b);
		/*	increment and decrement	*/
		Fixed & operator++(); // Prefix incrementation
		Fixed	operator++(int); // Postfix incrementation
		Fixed & operator--(); // Prefix decrementation
		Fixed	operator--(int); // Postfix decrementation

		void	setRawBit( int fix ); 
		int		getRawBit( void ); 
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int	_fixedPoint;
		static int const _fractionalBit = 8;

};

std::ostream& operator<<( std::ostream &out, Fixed const &in );

#endif
