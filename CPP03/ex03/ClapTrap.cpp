#include "ClapTrap.hpp"

/*             Constructor                                 */
ClapTrap::ClapTrap(){
	std::cout << "ClapTrap default constructor called" << std::endl;
	this->_name = "Georges";
	this->_energyPoints = 10;
	this->_hitPoints = 10;
	this->_attackDamage = 0;
	return;
}

ClapTrap::ClapTrap(std::string Name) : _name(Name), _hitPoints(10), _energyPoints(10), _attackDamage(0){
	std::cout << "ClapTrap with name constructor called" << std::endl;
	return;
}

ClapTrap::ClapTrap(ClapTrap  const &src){
	*this = src;
	std::cout << "ClapTrap copy constructor called" << std::endl;
	return;
}

ClapTrap	& ClapTrap::operator=(ClapTrap const &src){
	this->_name = src._name;
	this->_energyPoints = src._energyPoints;
	this->_hitPoints = src._hitPoints;
	this->_attackDamage = src._attackDamage;
	std::cout << "ClapTrap operator= called" << std::endl;
	return (*this);
}

ClapTrap::~ClapTrap(){
	std::cout << "ClapTrap destructor called" << std::endl;
	return;
}


/*            Function                          */

void ClapTrap::attack(const std::string& target){
	if (this->_energyPoints == 0){
		std::cout << "No more energy!!!" << std::endl; 
	}
	else if (this->_hitPoints > 0){
		this->_energyPoints--;
		std::cout << this->_name << " attacks " << target << " , causing " << this->_attackDamage << " points of damage!" << std::endl;
		std::cout << this->_name <<  " have " << this->_hitPoints << " point of health and " << this->_energyPoints << " of energy." << std::endl;
	}	
}

void ClapTrap::takeDamage(unsigned int amount){
	/*if ((int)amount < 0){
		std::cout << "nothing happened" << std::endl;
		return;
	}*/
	std::cout << "the  ennemy"  << " attacks " << this->_name << " , causing " << amount << " points of damage!" << std::endl;
	this->_hitPoints -= amount;
	if (this->_hitPoints > 0)
		std::cout << this->_name << " have " << this->_hitPoints << " point of health and " << this->_energyPoints << " of energy." << std::endl;
	else
		std::cout << this->_name << " was weak and " << this->_name <<" is  dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
	/*if ((int)amount < 0){
		this->_energyPoints = this->_energyPoints - 1;
		std::cout << this->_name << "can't repared but lost 1 energie" << std::endl;
		return;
	}*/
	if (this->_energyPoints > 0 && this->_hitPoints > 0){
		this->_hitPoints = this->_hitPoints + amount;
		this->_energyPoints = this->_energyPoints - 1;
		std::cout << this->_name << " have " << this->_hitPoints << " point of health and " << this->_energyPoints << " of energy." << std::endl;
	}
	else
		std::cout << this->_name << " can't be repaired" << std::endl;
}
