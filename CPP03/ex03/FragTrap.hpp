#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap{
	public :
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &src);
		FragTrap& operator=(FragTrap const &src);
		~FragTrap();
		void highFivesGuys(void);
		int	getEnergy(void) const;
		int	getHit(void) const;
		int	getDamage(void) const;
	private:
		static int const	_nEnergy = 100;
		static int const	_nHit = 100;
		static int const	_nDamage = 30;
};

#endif
