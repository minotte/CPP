#ifndef INTERN_HPP
#define INTERN_HPP

#include <exception>
#include <iostream>
#include <string>
#include "AForm.hpp"

class Intern
{
	 public:
		 /********Constructor / destructor*********/
		Intern();
		Intern(Intern const &src);
		Intern &operator=(Intern const &src);
		~Intern();
		/************* function ************/
		AForm	*Presidential(std::string target);
		AForm	*Robotomy(std::string target);
		AForm	*Shrubbery(std::string target);
		AForm	*makeForm(std::string name, std::string target);
		/************* exception ***********/
		class noCreated: public std::exception{
			public:
				virtual const char * what() const throw(){ return ("the intern don't create "); }
		};
		class noNull: public std::exception{
			public:
				virtual const char * what() const throw(){ return("Error : can't use NULL form"); }
		};
};

#endif
