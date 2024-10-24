#include "Fixed.hpp"
#include <ostream>

Fixed::Fixed(): _fixedPoint(0){
	return;
}

Fixed::Fixed(int nb): _fixedPoint(nb<<_fractionalBit){
	return;
}

Fixed::Fixed(float nb){
	this->_fixedPoint = nb * (1<<_fractionalBit);
	return;
}

Fixed::Fixed(Fixed const &src){
	*this = src;
	return;
}

Fixed & Fixed::operator=( Fixed const &src ){
	this->_fixedPoint = src._fixedPoint;	
	return (*this);
}

Fixed::~Fixed(){
	return;
}

Fixed Fixed::operator+(Fixed const &src) const{
	Fixed	result;
	result._fixedPoint  = this->_fixedPoint + src._fixedPoint;
	return result;
}

Fixed Fixed::operator-(Fixed const &src) const{
	Fixed	result;
	result._fixedPoint  = this->_fixedPoint - src._fixedPoint;
	return result;
}

Fixed Fixed::operator*(Fixed const &src) const{
	Fixed tmp;
	long	fixedTmp;
	
	fixedTmp = this->_fixedPoint;
	tmp.setRawBit((fixedTmp * src._fixedPoint) >> _fractionalBit);

	// tmp = tmp<<tmp._fractionalBit;
	return tmp;
}

Fixed Fixed::operator/(Fixed const &src) const{
	Fixed	tmp;
	long	fixedTmp;

	// tmp = this->toFloat() / src.toFloat();
	fixedTmp = this->_fixedPoint << _fractionalBit;
	tmp.setRawBit(fixedTmp / src._fixedPoint);
	return tmp;
}

			/* comparison operators */

bool Fixed::operator>(Fixed const &src) const{
	return (this->_fixedPoint > src._fixedPoint);
}

bool Fixed::operator<(Fixed const &src) const{
	return (this->_fixedPoint < src._fixedPoint);
}

bool Fixed::operator==(Fixed const &src) const{
	return	(this->_fixedPoint == src._fixedPoint);
}

bool Fixed::operator!=(Fixed const &src) const{
	return	(this->_fixedPoint != src._fixedPoint);
}

bool Fixed::operator>=(Fixed const &src) const{
	return	(this->_fixedPoint >= src._fixedPoint);
}

bool Fixed::operator<=(Fixed const &src) const{
	return	(this->_fixedPoint <= src._fixedPoint);
}

float Fixed::toFloat( void ) const{
	return ((double)this->_fixedPoint / (1<<this->_fractionalBit));
}

int Fixed::toInt( void ) const{
	return (this->_fixedPoint>>this->_fractionalBit);
}

std::ostream &	operator<<( std::ostream & out, Fixed const & in ){
	out << in.toFloat(); 
	return (out);
}

/*                min                        */

Fixed & Fixed::min(Fixed &a, Fixed &b){
	if (a._fixedPoint < b._fixedPoint)
		return (a);
	else
		return (b);
}

Fixed const & Fixed::min(Fixed const &a, Fixed const &b){
	if (a._fixedPoint < b._fixedPoint)
		return (a);
	else
		return (b);
}

/*					max							*/

Fixed & Fixed::max(Fixed &a, Fixed &b){
	if (a._fixedPoint > b._fixedPoint)
		return (a);
	else
		return (b);
}

Fixed const & Fixed::max(Fixed const &a, Fixed const &b){
	if (a._fixedPoint > b._fixedPoint)
		return (a);
	else
		return (b);
}


/*			incrementation/ decrementation			*/

Fixed & Fixed::operator++(){
/*	int inc = 1<<8;
	
	
	for (int i = 0; i < this->_fractionalBit; i++)
		inc /= 2;
	this->_fixedPoint += inc;*/
	this->_fixedPoint++;
	return *this;
}

Fixed	Fixed::operator++(int){
	Fixed	nb= *this;
	++(*this);
	return nb;
}

Fixed & Fixed::operator--(){
	// int dec = 1<<8;
// 
	// for (int i = 0; i < this->_fractionalBit; i++)
		// dec /= 2;
	this->_fixedPoint--;
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed	nb= *this;
	--(*this);
	return nb;
}

void Fixed::setRawBit( int fix ){
	this->_fixedPoint = fix;
}

int	Fixed::getRawBit ( void ){
	return (this->_fixedPoint);
}
