#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0){
	std::cout << "Default Constructor called" << std::endl;
	return;
}

Fixed::Fixed(int const n) : _fixedPoint(n){
	std::cout << "Parametric Constructor called" << std::endl;
	return;
}

Fixed::Fixed(Fixed const & src){
	std::cout << "Copy Constructor called" << std::endl;
	*this = src;
	return;
}

Fixed &	Fixed::operator=(Fixed const & src){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_fixedPoint = src.getRawBits(); 
	return(*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
	return;
}

int Fixed::getRawBits( void ) const{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_fixedPoint);
}

void Fixed::setRawBits( int const raw ){
	_fixedPoint = raw;
}

int const	Fixed::_raw = 8;
