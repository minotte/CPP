#include "AMateria.hpp"

AMateria::AMateria(){
	// std::cout << "AMateria constructor called" << std::endl;
	return;
}

AMateria::AMateria(std::string const & type):_type(type){
	// std::cout << "AMateria with argument constructor called" << std::endl;
	return;
}

AMateria::AMateria(AMateria const &src){
	*this = src;
}

AMateria const & AMateria::operator=(AMateria const &src){
	this->_type = src._type;
	return *this;
}

AMateria::~AMateria(){
	// std::cout << "AMateria destructor called" << std::endl;
	return;
}

std::string const & AMateria::getType() const{
	return (_type);
}

void AMateria::use(ICharacter& target){
	std::cout << target.getName() << " do nothing!!!" << std::endl;
}
