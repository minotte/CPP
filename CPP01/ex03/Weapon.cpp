#include "Weapon.hpp"

Weapon::Weapon( std::string const wType ) : _type(wType){ 
	std::cout << "Constructor weapon is create." << std::endl;
//	setType (wType);
	return;
}

Weapon::~Weapon(){
	std::cout << "Destruction of weapon" << std::endl;
	return;
}

/* ################### GETTER ################# */

std::string const &	Weapon::getType( void ) const{
	return (this->_type);
}

/* ################### SETTER ################# */

void	Weapon::setType(std::string newType){
	this->_type = newType;
}
