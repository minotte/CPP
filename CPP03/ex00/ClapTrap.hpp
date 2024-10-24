#ifndef CLAPTRAP_H
#define CLAPTRAP_H

#include <string>
#include <iostream>

class ClapTrap{
	public:
		ClapTrap();
		ClapTrap(std::string Name);
		ClapTrap(ClapTrap  const &src);
		ClapTrap	& operator=(ClapTrap const &src);
		~ClapTrap();
		/*******set     and  get*******************/
		void		setName(std::string str);
		std::string	getName(void);
		void		setHit(int hit);
		int			getHit(void);
		void		setEnergy(int energy);
		int			getEnergy(void);
		void		setAttack(int attack);
		int			getAttack(void);
		/***********************************************/
		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		private:
			std::string	_name;
			int			_hitPoints;
			int			_energyPoints;
			int			_attackDamage;
};

#endif
