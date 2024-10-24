#ifndef FORM_HPP
#define FORM_HPP 

#include "Bureaucrat.hpp"
#include <exception>
#include <ostream>

#define NC		" \033[0m"
#define GREY 	"\033[38;5;8m"
#define RED		"\033[38;5;1m"

class Bureaucrat;
class Form{
	 public:
		Form();
		Form(std::string const name, int const gradeToSign, int const gradeToExec);
		Form(Form const & src);
		Form & operator=(Form const & src);
		~Form();
		 void	beSigned(Bureaucrat& bureaucrat);
		 std::string const	getName() const;
		 bool	getSignature() const;
		 int	getGradeToSign() const;
		 int	getGradeToExec() const;
		 class GradeTooHighException : public std::exception {
		 	 public:
				 virtual const char* what() const throw();
		 };
		 class GradeTooLowException : public std::exception {
		 	 public:
				 virtual const char* what() const throw();
		 };
	 private:
		std::string const	_name;
		bool				_signature;
		int const			_gradeToSign;
		int const			_gradeToExec;
};

std::ostream& operator<<( std::ostream &out, Form const & in); 

#endif
