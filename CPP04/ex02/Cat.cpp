#include "Cat.hpp"
#include "AAnimal.hpp"
#include "Brain.hpp"

Cat::Cat(){
	AAnimal::_type = "Cat";
	_brain = new Brain();
	_brain->setIdea(0, "EAT");
	_brain->setIdea(1, "sleep");
	_brain->setIdea(2, "play");
	_brain->setIdea(3, "EAT");
	_brain->setIdea(4, "sleep");
	_brain->setIdea(5, "play");
	_brain->setIdea(6, "play");
	_brain->setIdea(7, "play");
	_brain->setIdea(8, "sleep");
	_brain->setIdea(9, "sleep");
	_brain->setIdea(10, "sleep");
	_brain->setIdea(11, "sleep");
	_brain->setIdea(12, "sleep");
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
	std::cout << "\033[0;31m" <<  " not bark : miaou!\033[0m" << std::endl;
}

Brain*	Cat::getBrain()const{
	return this->_brain;
}
