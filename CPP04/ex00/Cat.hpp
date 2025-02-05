#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class	Cat : public Animal{
	public:
		Cat();
		Cat(Cat const &src);
		Cat  & operator=(Cat const &src);
		~Cat();
		virtual void makeSound() const;
};

#endif
