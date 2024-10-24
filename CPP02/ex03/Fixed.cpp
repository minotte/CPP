#include "Fixed.hpp"

Fixed::Fixed(): _fixedPoint(0){	
	std::cout  << "Default constructor Fixed called"<< std::endl;
	return;
}

Fixed::Fixed(int nb): _fixedPoint(nb<<_fractionalBit){
	std::cout << "Int Constructor Fixed called" << std::endl;
	return;
}

Fixed::Fixed(float nb){
	this->_fixedPoint = nb * (1<<_fractionalBit);
	std::cout << "Float Constructor Fixed called"  <<std::endl;
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
	std::cout << "Destructor Fixed called" << std::endl;
	return;
}

		/* comparison operators */

bool	Fixed::operator<(Fixed const &src)const{
	return (this->_fixedPoint < src._fixedPoint);
}

bool	Fixed::operator>(Fixed const &src) const{
	return (this->_fixedPoint > src._fixedPoint);
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

			/* operation operator */

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

Fixed	Fixed::operator*(const Fixed &src) const{
	Fixed	tmp;
	long	valueTmp;

	valueTmp = this->_fixedPoint;
	tmp.setRawBit((valueTmp * src._fixedPoint) >> _fractionalBit);
	return tmp;
}

Fixed	Fixed::operator/(const Fixed &src) const{
	Fixed	tmp;
	long	fixedTmp;

	fixedTmp = this->_fixedPoint << _fractionalBit;
	tmp.setRawBit(fixedTmp / src._fixedPoint);
	return tmp;
}


	/*        min and max         */

Fixed const & Fixed::min(Fixed &a, Fixed &b)
{
	if (a.getRawBit() < b.getRawBit())
		return a;
	else
		return b;
}

Fixed const & Fixed::min(Fixed const &a, Fixed const &b){
	if (a._fixedPoint < b._fixedPoint)
		return a;
	else
		return b;
}

Fixed const & Fixed::max(Fixed &a, Fixed &b){
	if (a.getRawBit() < b.getRawBit())
		return b;
	else
		return a;
}

Fixed const & Fixed::max(Fixed const &a, Fixed const &b){
	if (a._fixedPoint < b._fixedPoint)
		return b;
	else
		return a;
}

	/*  incrementation & decrement */

Fixed & Fixed::operator++(){
	this->_fixedPoint++;
	return *this;
}

Fixed	Fixed::operator++(int){
	Fixed	tmp = *this;

	++(*this);
	return (tmp);
}

Fixed & Fixed::operator--(){
	this->_fixedPoint--;
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed	tmp = *this;

	--(*this);
	return (tmp);
}

void	Fixed::setRawBit( int fix ){
	this->_fixedPoint = fix;
}

int	Fixed::getRawBit(){
	return (this->_fixedPoint);
}

float	Fixed::toFloat( void ) const{
	return ((double)this->_fixedPoint / (1 << this->_fractionalBit));
}

int	Fixed::toInt( void ) const {
	return ( this->_fixedPoint>>this->_fractionalBit );
}

std::ostream & operator<<( std::ostream & out, Fixed const & in ){
	out << in.toFloat(); 
	return (out);
}
