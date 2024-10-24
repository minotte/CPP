#include "Zombie.hpp"

Zombie::Zombie( void )
{
	return;
}

Zombie::Zombie ( std::string name ): _name(name){
	announce();
	return;
}

Zombie::~Zombie ( void ){
	std::cout << this->_name << " is dead" << std::endl;
	return;
}

void Zombie::announce( void ){
		std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName( std::string name ){
	this->_name = name;
}
