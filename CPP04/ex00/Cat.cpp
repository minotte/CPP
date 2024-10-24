#include "Cat.hpp"

Cat::Cat() : Animal(){
	Animal::_type = "Cat";
	std::cout << "Cat construtor with type called" << std::endl;
	return;
}

Cat::Cat(Cat const &src){
	*this = src;
	std::cout << "Cat copy construtor called" << std::endl;
}

Cat & Cat::operator=(Cat const &src)
{
	this->_type = src._type;
	return *this;
}

Cat::~Cat(){
	std::cout << "Cat destrutor called" << std::endl;
	return;
}

void Cat::makeSound() const{
	std::cout << Animal::getType() <<  " not bark : miaou!" << std::endl;
}
