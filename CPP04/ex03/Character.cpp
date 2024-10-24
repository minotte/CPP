#include "Character.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iterator>

Character::Character():_name("John Doe"){
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
	this->_tmp = 0;
}

Character::Character(std::string name):_name(name){
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
	this->_tmp = 0;
}

Character::~Character(){
	for(int i = 0; i < 4; i++){
		if (this->_inventory[i]){
			delete this->_inventory[i];
		}
	}
		if (this->_tmp){
			delete this->_tmp;
		}
}

Character::Character(Character const &src){
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = 0;
	this->_tmp = 0;
	*this = src;
}

Character &Character::operator=(Character const &src){
	this->_name = src._name;
	for (int i = 0; i < 4; i++){
		if (this->_inventory[i])
			delete this->_inventory[i];
		this->_inventory[i] = NULL;
		if (src._inventory[i]){
			this->_inventory[i] = src._inventory[i]->clone();
		}
	}
	this->_tmp = 0;
	return *this;
}

std::string const & Character::getName() const{
	return (this->_name);
}

void Character::equip(AMateria* m){
	int i = 0;
	if (!m)
	{
		std::cout << this->_name << " cant equip nothing" << std::endl;
		return ;
 	}
	while (i < 4){
		if (this->_inventory[i] == 0){
			this->_inventory[i] = m->clone();
			std::cout << this->_name << " equip " << m->getType() << " at " << i << "."<< std::endl;
			break;
 		}
		i++;
	}
	if (i == 4){
		std::cout << this->_name << " can't have more equipement, he is full, pls unequip one before" << std::endl; 
	}
}

void Character::unequip(int idx){
	if (idx < 0 || idx > 3){
		std::cout << idx << " can't exist " << this->_name << " have just 4 items and their index are between 0 and 3." << std::endl;
		return ;
	}
	else if (!(this->_inventory[idx]))
	{
		std::cout << "it's already empty" << std::endl;
	}
	else{

		if (this->_tmp)
			delete this->_tmp;
		_tmp = this->_inventory[idx];
		this->_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target){
	if (idx < 0 || idx > 3){
		std::cout << idx << " can't exist " << this->_name << " have just 4 items" << std::endl;
		return ;
	}
	else if (!(this->_inventory[idx]))
	{
		std::cout << idx << " is nothing so " << this->_name << " try to yell and nothing append" << std::endl;
	}
	else{
		std::cout << this->getName();
		this->_inventory[idx]->use(target);
	}
}

AMateria* Character::getTmp(void){
	return (this->_tmp);
}
