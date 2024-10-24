#ifndef AFORM_HPP
#define AFORM_HPP 

#include "Bureaucrat.hpp"
#include <exception>
#include <iostream>
#include <string>

class Bureaucrat;
class AForm{
	public:
		/*              Constructor/Destructor                    */
		AForm();
		AForm(std::string const name, int const gradeToSign, int const gradeToExec);
		AForm(AForm const & src);
		AForm & operator=(AForm const & src);
		virtual ~AForm();

		/*						Function							*/
		void	beSigned(Bureaucrat const & bureaucrat);
		virtual void execute(Bureaucrat const & executor) const = 0;
   
		/*             Getter                    */
		std::string const	getName() const;
		bool	getSignature() const;
		int		getGradeToSign() const;
		int		getGradeToExec() const;
		std::string	getTarget() const;
		void	setTarget(std::string target);
		void	setSignature(bool signature);
		/*                    Exception                    */
		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
		class NeedToBeSign : public std::exception {
			public:
				virtual const char* what() const throw(){ return ("the document need to be sign"); };
		};
	private:
		std::string const	_name;
		bool				_signature;
		int const			_gradeToSign;
		int const			_gradeToExec;
		std::string			_target;
};

std::ostream & operator<<( std::ostream &out, AForm const & in); 

#endif
