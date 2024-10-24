#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal{
	public:
		WrongAnimal();
		WrongAnimal(std::string type);
		WrongAnimal(WrongAnimal const &src);
		WrongAnimal &operator=(WrongAnimal const &src);
		~WrongAnimal();
		void makeSound()const;
		void	setType(std::string type); 
		std::string	getType(void) const; 
	protected:
		std::string	_type;
};

#endif
