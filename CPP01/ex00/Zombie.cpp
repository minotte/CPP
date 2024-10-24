#include "Zombie.hpp"

Zombie::Zombie ( std::string name ): _name(name){
	announce();
	return;
}

Zombie::~Zombie ( void ){
	std::cout << "Zombie " << this->_name << " is dead" << std::endl;
	return;
}

void Zombie::announce( void ){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
