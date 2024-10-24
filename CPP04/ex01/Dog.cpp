#include "Dog.hpp"

Dog::Dog(): Animal(){
	Animal::_type = "Dog";
	this->_brain = new Brain();
	// std::cout << "Dog construtor with type called" << std::endl;
	return;
}

Dog::Dog(Dog const &src){
	*this = src;
	// std::cout << "Dog copy construtor called" << std::endl;
}

Dog & Dog::operator=(Dog const &src)
{
	this->_type = src._type;
	this->_brain = new Brain(*src._brain);
	return *this;
}

Dog::~Dog(){
	delete this->_brain;
	// std::cout << "Dog destrutor called" << std::endl;
	return;
}

void Dog::makeSound() const {
	std::cout << "\033[0;32m" << Animal::getType() <<  " bark : woof woof woof woof woof!!!!!!!\033[0m" << std::endl;
}

Brain*	Dog::getBrain() const{
	return this->_brain;
}
