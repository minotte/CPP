#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class	Animal{
	public:
		Animal();
		Animal(std::string type);
		Animal(Animal const &src);
		Animal & operator=(Animal const &src);
		virtual ~Animal();
		void	setType(std::string type); 
		std::string	getType(void) const; 
		virtual void makeSound() const;
		// virtual Brain*	getBrain( ) const= 0 ;

	protected:
		std::string	_type;
};

#endif
