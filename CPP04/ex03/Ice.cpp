#include "Ice.hpp"
#include "AMateria.hpp"

Ice::Ice(): AMateria("ice"){}

Ice::~Ice() {}

Ice::Ice(Ice const &src){
	*this = src;
}

Ice & Ice::operator=(Ice const &src){
	this->_type = src._type;
	return *this;
}

void Ice::use(ICharacter& target){
	std::cout << " * shoot an ice bolt an " << target.getName() << " *" << std::endl; 
}

AMateria* Ice::clone() const{
	AMateria* dup = new Ice;
	return dup;
}
