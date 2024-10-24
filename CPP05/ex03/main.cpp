#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(){
	try{
		{
			std::cout << "-----------------------------------" << std::endl;
			Intern	randomNewbie;
			AForm *form = randomNewbie.makeForm("presidential request", "Kenny");
			Bureaucrat *bur  = new Bureaucrat("William", 2);
			bur->signForm(*form);
			bur->executeForm(*form);
			delete bur;
			delete form;
		}
	}
	catch (const std::exception &e){
		std::cerr << e.what() <<std::endl;

	}
	try{
		std::cout << "-----------------------------------" << std::endl;
		Intern someRandomIntern;
		AForm* rrf;
		AForm* rrf2;
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		Bureaucrat bibi("bibi", 56);
		bibi.executeForm(*rrf);
		delete rrf;
		rrf2 = someRandomIntern.makeForm("robot", "Bender");
		bibi.executeForm(*rrf2);
		bibi.signForm(*rrf2);
		delete rrf2;
	}
	catch (const std::exception &e){
		std::cerr << e.what() <<std::endl;
	}

	return 0;
}
