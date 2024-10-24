#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

#define	IDEAS  100

class Brain
{
	 public:
		Brain();
		Brain(Brain const &src);
		Brain	& operator=(Brain const &src);
		~Brain();
		void		setIdea(int i, std::string idea);
		std::string	getIdea(int i) const;
	 private:
		std::string _ideas[IDEAS];		
};

#endif
