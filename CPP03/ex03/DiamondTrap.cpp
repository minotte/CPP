#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

DiamondTrap::DiamondTrap(){
	DiamondTrap::_name = ClapTrap::_name;
	ClapTrap::_name += "_clap_name";
	DiamondTrap::_attackDamage = FragTrap::getDamage();
	DiamondTrap::_energyPoints = ScavTrap::getEnergy();
	DiamondTrap::_hitPoints = FragTrap::getHit();
	std::cout << "DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name){
	ClapTrap::_name = name + "_clap_name";
	this->_name = name ;
	DiamondTrap::_attackDamage = FragTrap::getDamage();
	DiamondTrap::_energyPoints = ScavTrap::getEnergy();
	DiamondTrap::_hitPoints = FragTrap::getHit();
	std::cout << "DiamondTrap Constructor called" << std::endl;
}
	
DiamondTrap::DiamondTrap(DiamondTrap const &src){
	*this = src;
	return;
}

DiamondTrap& DiamondTrap::operator=(DiamondTrap const &src){
	this->_name = src._name;
	ClapTrap::_name = src._name;
	this->_energyPoints = src._energyPoints;
	this->_hitPoints = src._hitPoints;
	this->_attackDamage = src._attackDamage;
	return *this;
}

DiamondTrap::~DiamondTrap(){
	std::cout << "DiamondTrap Destructor" << std::endl;
	return;
}

void DiamondTrap::whoAmI(){
	std::cout << "Diamond name " << _name << " or " << ClapTrap::_name << " ?" << std::endl;
}

void	DiamondTrap::attack(const std::string &target){
	ScavTrap::attack(target);
}
