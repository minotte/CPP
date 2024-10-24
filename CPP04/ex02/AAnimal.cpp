#include "AAnimal.hpp"

AAnimal::AAnimal(): _type("animal"){
	// std::cout << "Animal construtor called" << std::endl;
	return;
}

AAnimal::AAnimal(AAnimal const &src){
	*this = src;
	// std::cout << "Animal copy construtor called" << std::endl;
}

AAnimal & AAnimal::operator=(AAnimal const &src)
{
	this->_type = src._type;
	return *this;
}

AAnimal::~AAnimal(){
	// std::cout << "Animal destrutor called" << std::endl;
	return;
}
 
void	AAnimal::setType(std::string type){
	this->_type = type;	
}

std::string	AAnimal::getType(void) const{
	return (this->_type);
}

void AAnimal::makeSound() const{
	// std::cout <<  getType() << " sound of the animal !!!!     Grrrrrrrrrrrrrrr" << std::endl;
}
