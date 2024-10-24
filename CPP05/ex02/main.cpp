#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(){
	try{
		Bureaucrat a;
		std::cout << a << std::endl;
		Bureaucrat b = Bureaucrat("A+", 8);
		Bureaucrat c = b;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		c.decrementGrade();
		c.decrementGrade();
		c.decrementGrade();
		c.decrementGrade();
		a.decrementGrade();
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << a << std::endl;
		Bureaucrat	francois = Bureaucrat("François", 1);
		francois.incrementGrade();
		std::cout << francois << std::endl;
		std::cout << std::endl;
		AForm* paper =  new PresidentialPardonForm("Michel");
		std::cout << "-----------------------------------" << std::endl;
		std::cout << paper->getTarget() << std::endl;
		std::cout << paper->getName() << std::endl;
		std::cout << *paper << std::endl ; 
		std::cout << "-----------------------------------" << std::endl;
		paper->beSigned(b);
		AForm* 	rob = new RobotomyRequestForm("forward");
		francois.executeForm(*(AForm*)rob);
		a.signForm(*rob);
		AForm*	tree = new ShrubberyCreationForm("home");
		c.signForm(*(AForm*)tree);
		std::cout << "-----------------------------------" << std::endl;
		francois.executeForm(*(AForm*)paper);
		a.executeForm(*(AForm*)rob);
		b.signForm(*(AForm*)rob);
		c.executeForm(*(AForm*)rob);
		francois.executeForm(*(AForm*)tree);
		std::cout << "-----------------------------------" << std::endl;
		paper->beSigned(c);
		PresidentialPardonForm toto("aa");
		francois.signForm(toto);
		francois.executeForm(toto);
		delete tree;
		delete rob;
		delete  paper;
	}
	catch (const std::exception &e){
		std::cerr << e.what() <<std::endl;
	}
	return 0;
}
