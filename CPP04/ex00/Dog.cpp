#include "Dog.hpp"

Dog::Dog(){
	Animal::_type = "Dog";
	std::cout << "Dog construtor with type called" << std::endl;
	return;
}

Dog::Dog(Dog const &src){
	*this = src;
	std::cout << "Dog copy construtor called" << std::endl;
}

Dog & Dog::operator=(Dog const &src)
{
	this->_type = src._type;
	return *this;
}

Dog::~Dog(){
	std::cout << "Dog destrutor called" << std::endl;
	return;
}

void Dog::makeSound() const {
	std::cout << Animal::getType() <<  " bark : woof woof woof woof woof!!!!!!!" << std::endl;
}
