#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): _type("wrong animal"){

}

WrongAnimal::WrongAnimal(std::string type): _type(type){

}

WrongAnimal::WrongAnimal(WrongAnimal const &src){
	*this = src;
}

WrongAnimal & WrongAnimal::operator=(WrongAnimal const &src){
	this->_type = src._type;
	return *this;
}

WrongAnimal::~WrongAnimal(){
	
}

void	WrongAnimal::makeSound() const{
	std::cout <<  getType() << " wrong Sound : Brrrrrrr!!!" << std::endl;
}

void	WrongAnimal::setType(std::string type){
	this->_type = type;	
}

std::string	WrongAnimal::getType(void) const{
	return (this->_type);
}
