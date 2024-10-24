#include "HumanB.hpp"
#include "Weapon.hpp"

HumanB::HumanB( std::string name): _name(name){
	this->_weaponName = NULL;
	return;
}

HumanB::~HumanB( void ){
	return ;
}

void	HumanB::attack(void)
{
	if(this->_weaponName == NULL)
		std::cout << this->_name << " attacks with their fist." <<  std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weaponName->getType() <<  std::endl;

}

void	HumanB::setWeapon(Weapon &newWeapon){
	this->_weaponName = &newWeapon;	
}
