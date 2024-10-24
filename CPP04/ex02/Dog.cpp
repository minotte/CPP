#include "Dog.hpp"

Dog::Dog(){
	AAnimal::_type = "dog";
	this->_brain = new Brain();
	// std::cout << "Dog construtor with type called" << std::endl;
	_brain->setIdea(0, "EAT");
	_brain->setIdea(1, "sleep");
	_brain->setIdea(2, "play");
	_brain->setIdea(3, "EAT his shit");
	_brain->setIdea(4, "WOAF");
	
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
	std::cout << "\033[0;32m" <<   " bark : woof woof woof woof woof!!!!!!!\033[0m" << std::endl;
}

Brain*	Dog::getBrain() const{
	return this->_brain;
}
