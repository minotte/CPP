#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "ICharacter.hpp"
#include <string>
#include <iostream>

class ICharacter;
class AMateria{
	public:
 		AMateria();
   		virtual ~AMateria();
  		AMateria(std::string const & type);
		AMateria(AMateria const &src);
		AMateria const &operator=(AMateria const &src);

		std::string const & getType() const;

  		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter  & target);
  protected:
  		std::string _type;
};

#endif
