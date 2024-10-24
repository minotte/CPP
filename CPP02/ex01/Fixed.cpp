#include "Fixed.hpp"
#include <math.h>

//Default Constructor
Fixed::Fixed(): _fixedPoint(0<<this->_fractionalBit){
	std::cout << "Default Constructor called" << std::endl;
	return;
}

/* parametric Constructor */
Fixed::Fixed( int const n ): _fixedPoint(n<<this->_fractionalBit) {
	std::cout << "Int Constructor called" << std::endl;
	return;

}

Fixed::Fixed( float const n ) {
	this->_fixedPoint = roundf(n * (1<<this->_fractionalBit));
	std::cout << "Float Constructor called"  <<std::endl;
	return;

}

Fixed::Fixed(Fixed const &src){
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
	return;
}

Fixed & Fixed::operator=(Fixed const &src){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPoint = src._fixedPoint;
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl; 
	return;
}

float Fixed::toFloat( void ) const{
	return ((double)this->_fixedPoint / (1<<this->_fractionalBit));
}

int Fixed::toInt( void ) const{
	return (this->_fixedPoint>>this->_fractionalBit);
}

int Fixed::getRawBits( void ) const{
	return (this->_fixedPoint);
}

void Fixed::setRawBits( int const raw ){
	this->_fixedPoint = raw;
}

std::ostream &	operator<<( std::ostream & out, Fixed const & in ){
	out << in.toFloat(); 
	return (out);
}
