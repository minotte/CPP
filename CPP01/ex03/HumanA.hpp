#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <iostream>
#include <string>
#include "Weapon.hpp"

class HumanA{
	 public:
		HumanA(std::string name, Weapon& weapName);
		~HumanA();
		void	attack(void);
	 private:
		std::string		_nameA;
		Weapon&	_wName;	
};

#endif
