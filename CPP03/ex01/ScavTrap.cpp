#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << "StravTrap  default constructor called" << std::endl;
	this->_attackDamage = 20;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	return;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	std::cout << "StravTrap constructor called" << std::endl;
	this->_attackDamage = 20;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	return;
}

ScavTrap::ScavTrap(ScavTrap const &src): ClapTrap(src._name){
	*this = src;
	std::cout << "ScavTrap copy constructor is called." << std::endl;
	return;
}

ScavTrap	& ScavTrap::operator=(ScavTrap const &src){
	this->_attackDamage = src._attackDamage;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;	
	this->_name = src._name;
	return *this;
}

ScavTrap::~ScavTrap(){
	return;
}

void	ScavTrap::attack(const std::string &target){
	if (this->_energyPoints == 0){
		std::cout << this->_name << "don't have enought energy!!!" << std::endl; 
	}
	else if (this->_hitPoints > 0){
		this->_energyPoints = this->_energyPoints  - 1;
		std::cout << this->_name << " attacks " << target << " , causing " << this->_attackDamage << " points of damage!" << std::endl;
		std::cout << this->_name <<  " have " << this->_hitPoints << " point of health and " << this->_energyPoints << " of energy. let's go!" << std::endl;
	}
}

void ScavTrap::guardGate(){
	std::cout << "\"Gate keeper mode\" activate !!!" << std::endl; 
}
