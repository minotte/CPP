#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character: public ICharacter {
	public:
		Character();
		Character(std::string name);
		Character(Character const &src);
		Character &operator=(Character const &src);
		~Character();
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter const & target);
		AMateria* getTmp(void);
	private:
		std::string	_name;
		AMateria*	_inventory[4];
		AMateria*	_tmp;
};

#endif
