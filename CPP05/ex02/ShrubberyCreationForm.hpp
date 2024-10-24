#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <exception>
#include <string>
#include <fstream>

class ShrubberyCreationForm : public AForm{
	 public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &src);
		~ShrubberyCreationForm();
		virtual void execute(Bureaucrat const & executor) const;
		class openProb : public std::exception{
			 public:
				 virtual const char* what() const throw() {return ("The document can't open");}
		};
};
#endif
