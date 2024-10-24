#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat() : Animal(){
	Animal::_type = "Cat";
	_brain = new Brain();
	// std::cout << "Cat construtor with type called" << std::endl;
	return;
}

Cat::Cat(Cat const &src){
	*this = src;
	std::cout << "Cat copy construtor called" << std::endl;
}

Cat & Cat::operator=(Cat const &src)
{
	this->_brain = new  Brain(*src._brain);
	return *this;
}

Cat::~Cat(){
	// std::cout << "Cat destrutor called" << std::endl;
	delete _brain;
	return;
}

void Cat::makeSound() const{
	std::cout << "\033[0;31m" << Animal::getType() <<  " not bark : miaou!\033[0m" << std::endl;
}

Brain*	Cat::getBrain()const{
	return this->_brain;
}
