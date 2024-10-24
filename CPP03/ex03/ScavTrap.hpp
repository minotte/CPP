#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap :virtual public ClapTrap
{
	 public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &src);
		ScavTrap& operator=(ScavTrap const &src);
		~ScavTrap();
		void	guardGate();
		void	attack(const std::string& target);
		int	getEnergy(void) const;
		int	getHit(void) const;
		int	getDamage(void) const;
	 private:
		static int const	_nEnergy = 50;
		static int const	_nHit = 100;
		static int const	_nDamage = 20;
};

#endif
