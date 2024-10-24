#include "ClapTrap.hpp"

/*             Constructor                                 */
ClapTrap::ClapTrap(){
	std::cout << "ClapTrap constructor called" << std::endl;
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

/*			Setter and Getter                   */

void		ClapTrap::setName(std::string str){
	this->_name = str;
}
std::string	ClapTrap::getName(void){
	return (this->_name);
}

void		ClapTrap::setHit(int hit){
	this->_hitPoints = hit;
}

int			ClapTrap::getHit(void){
	return (this->_hitPoints);
}

void		ClapTrap::setEnergy(int energy){
	this->_energyPoints = energy;
}

int			ClapTrap::getEnergy(void){
	return (this->_energyPoints);
}
void		ClapTrap::setAttack(int attack){
	this->_attackDamage = attack;
}

int			ClapTrap::getAttack(void){
	return (this->_attackDamage);
}

/*            Function                          */

void ClapTrap::attack(const std::string& target){
	if (getEnergy() == 0){
		std::cout << "No more energy!!!" << std::endl; 
	}
	else if (getHit() > 0){
		setEnergy(getEnergy() - 1);
		std::cout << getName() << " attacks " << target << " , causing " << getAttack() << " points of damage!" << std::endl;
		std::cout << getName() <<  " have " << getHit() << " point of health and " << getEnergy() << " of energy." << std::endl;
	}
	
}

void ClapTrap::takeDamage(unsigned int amount){
/*	if ((int)amount < 0){
		std::cout << "the ennemy is sleepling !" <<std::endl;
		return;
	}*/
	std::cout << "the  ennemy"  << " attacks " << getName() << " , causing " << amount << " points of damage!" << std::endl;
	setHit(getHit() - amount);
	if (getHit() > 0)
		std::cout << getName() << " have " << getHit() << " point of health and " << getEnergy() << " of energy." << std::endl;
	else
		std::cout << getName() << " was weak and " << getName() <<" is  dead" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount){
/*	if ((int)amount < 0){
		setEnergy(getEnergy() - 1);
		std::cout << getName() << "can't repared but lost 1 energie" << std::endl;
		return;
	}*/
	if (getEnergy() > 0 && getHit() > 0){
		setHit(getHit() + amount);
		setEnergy(getEnergy() - 1);
		std::cout << getName() << " have " << getHit() << " point of health and " << getEnergy() << " of energy." << std::endl;
	}
	else
		std::cout << getName() << " can't be repaired" << std::endl;
}
