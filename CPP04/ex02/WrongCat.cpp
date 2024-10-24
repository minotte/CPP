#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
	WrongAnimal::_type = "WrongCat";
		std::cout << "WrongCat construtor with type called" << std::endl;
	return;
}

WrongCat::WrongCat(WrongCat const &src){
	*this = src;
	std::cout << "WrongCat copy construtor called" << std::endl;
}

WrongCat & WrongCat::operator=(WrongCat const &src)
{
	this->_type = src._type;
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "WrongCat destrutor called" << std::endl;
	return;
}

void WrongCat::makeSound() const{
	std::cout << WrongAnimal::getType() <<  " Biaou!" << std::endl;
}
