#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <ostream>
#include <string>
#include <exception>

#define NC		" \033[0m"
#define GREY 	"\033[38;5;8m"
#define RED		"\033[38;5;1m"

class AForm;
class Bureaucrat{

	public:

		/* construtor / destructor  */
		Bureaucrat();
		Bureaucrat(std::string const & name, int grade);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat &operator=(Bureaucrat const &src);
		~Bureaucrat();

		/*   setter / getter   */
		std::string const	getName() const;
		int					getGrade() const;

		/* function              */
		void				incrementGrade();
		void				decrementGrade();
		void	signForm(AForm &form );
		void	executeForm(AForm const & form);

		/*           exception                    */
		class	GradeTooHighException : public std::exception{
			public:
				virtual const char* what(void) const throw();
		};
		class	GradeTooLowException : public std::exception{
			public:
				virtual const char* what(void) const throw();
		};

	private:

		std::string const	_name;
		int					_grade;
};

std::ostream & operator<<( std::ostream & out, Bureaucrat const & in );

#endif
