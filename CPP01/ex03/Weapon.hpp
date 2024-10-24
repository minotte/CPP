#ifndef WEAPON_HPP
# define WEAPON_HPP

#include <string>
#include <iostream>

class Weapon
{
	 public:
		Weapon( std::string const wType );
		~Weapon();
		void	setType( std::string newType );
		std::string const & 	getType( void ) const;	
	 private:
		std::string _type;
};

#endif
