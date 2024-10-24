#include "Point.hpp"
#include "Fixed.hpp"

Point::Point() : _x(0), _y(0){
	std::cout  << "Default constructor Point called"<< std::endl;
	return ;
}

Point::Point(float const x, float const y){
	std::cout  << "Constructor Point called"<< std::endl;
	Fixed a(x);
	this->_x = a.getRawBit();
	Fixed b(y);
	this->_y = b.getRawBit();

	return ;
}

Point::Point(Point const &src){
	*this = src;
	std::cout << "Copy constructor Point called" << std::endl;
	return ;
}

Point & Point::operator=(const Point &src){
	this->setX(src.getX());
	this->setY(src.getY());
	std::cout << "Copy Point assignement operator called" << std::endl; 
	return *this;
}

Point::~Point(){
	std::cout  << "Destructor Point called"<< std::endl;
	return ;
}


void	Point::setX(int const x){
	this->_x = x;
}

int		Point::getX(void) const{
	return (this->_x);
}

void	Point::setY(int const y){
	this->_y = y;
}

int		Point::getY(void) const{
	return (this->_y);
}
