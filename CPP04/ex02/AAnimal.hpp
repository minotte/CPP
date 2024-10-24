#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class	AAnimal{
	public:
		AAnimal();
		AAnimal(AAnimal const &src);
		AAnimal & operator=(AAnimal const &src);
		virtual ~AAnimal();
		void	setType(std::string type); 
		std::string	getType(void) const; 
		virtual void makeSound() const = 0;

	protected:
		std::string	_type;
};

#endif
