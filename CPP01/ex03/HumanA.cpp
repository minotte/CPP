#include "HumanA.hpp"
#include "Weapon.hpp"

HumanA::HumanA( std::string name, Weapon& weapName):_nameA(name), _wName(weapName){
	return;
}

HumanA::~HumanA( void ){
	return ;
}

void	HumanA::attack(void)
{
	std::string	weapon;

	weapon = this->_wName.getType();
	std::cout << this->_nameA << " attacks with their " << weapon <<  std::endl;
}

