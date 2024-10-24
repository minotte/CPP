#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <string>
#include <iostream>

class HumanB{
	 public:
		HumanB(std::string name);
		~HumanB();
		void	attack(void);
		void	setWeapon(Weapon &newWeapon);
	 private:
		Weapon	*_weaponName;	
		std::string	_name;
};

#endif
