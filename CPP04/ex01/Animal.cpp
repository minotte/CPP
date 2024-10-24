#include "Animal.hpp"

Animal::Animal(): _type("animal"){
	// std::cout << "Animal construtor called" << std::endl;
	return;
}

Animal::Animal(std::string type): _type(type){
		// std::cout << "Animal construtor with tupe called" << std::endl;
	return;
}

Animal::Animal(Animal const &src){
	*this = src;
	// std::cout << "Animal copy construtor called" << std::endl;
}

Animal & Animal::operator=(Animal const &src)
{
	this->_type = src._type;
	return *this;
}

Animal::~Animal(){
	// std::cout << "Animal destrutor called" << std::endl;
	return;
}

void	Animal::setType(std::string type){
	this->_type = type;	
}

std::string	Animal::getType(void) const{
	return (this->_type);
}

void Animal::makeSound() const{
	std::cout <<  getType() << " sound of the animal !!!!     Grrrrrrrrrrrrrrr" << std::endl;
}
