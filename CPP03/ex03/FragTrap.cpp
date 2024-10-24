#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap(){
	std::cout << "FragTrap Constructor default called" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return;
}

FragTrap::FragTrap(std::string name): ClapTrap(name){
	std::cout << "FragTrap Constructor called" << std::endl;  
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
	return;
}

FragTrap::FragTrap(FragTrap const &src){
	std::cout << "FragTrap copy constructor" << std::endl;
	*this = src;
	return;
}

FragTrap&	FragTrap::operator=(FragTrap const &src){
	std::cout << "FragTrap copy operator called" << std::endl;
	this->_name = src._name;
	this->_hitPoints = src._hitPoints;
	this->_energyPoints = src._energyPoints;
	this->_attackDamage = src._attackDamage;
	return (*this);
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap destructor called" << std::endl;
	return;
}

void FragTrap::highFivesGuys(void){
	std::cout << "Gime a HIGH FIVE, bro!!!!" << std::endl;
}

int FragTrap::getEnergy(void) const{
	return this->_nEnergy;
}

int	FragTrap::getHit(void) const{
	return this->_nHit;
}
int	FragTrap::getDamage(void) const{
	return this->_nDamage;
}
