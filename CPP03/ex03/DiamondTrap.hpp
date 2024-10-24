#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, FragTrap{
	private:
		std::string	_name;
	public:
		DiamondTrap();
		DiamondTrap(std::string n);
		DiamondTrap(DiamondTrap const &src);
		DiamondTrap& operator=(DiamondTrap const &src);
		~DiamondTrap();
		void whoAmI();
		void attack(const std::string& target);
};

#endif
