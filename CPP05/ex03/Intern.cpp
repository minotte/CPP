#include "Intern.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <exception>

Intern::Intern(){
	std::cout << GREY << "intern Constructor" << NC << std::endl;
}

Intern::Intern(Intern const &src){
	*this = src;
	std::cout << GREY << "intern copy Constructor" << NC << std::endl;
}

Intern &Intern::operator=(Intern const &src){
	(void) src;
	return (*this);
}
Intern::~Intern(){
	std::cout << GREY << "intern destructor" << NC << std::endl;
}

AForm	*Intern::Presidential(std::string target){
	AForm *form = new PresidentialPardonForm(target);
	return (form);
}		

AForm	*Intern::Robotomy(std::string target){
	AForm *form = new RobotomyRequestForm(target);
	return (form);
}		


AForm	*Intern::Shrubbery(std::string target){
	AForm *form = new ShrubberyCreationForm(target);
	return (form);
}


AForm	*Intern::makeForm(std::string name, std::string target){
	std::string	form[3] = {"presidential request", "robotomy request", "shrubbery request"};
	AForm *(Intern::*ptrFonct[3])(std::string target) = { &Intern::Presidential, &Intern::Robotomy, &Intern::Shrubbery};
	try{
		for (int i = 0; i < 3; i++){
			if(!name.compare(form[i])){
				std::cout << "Intern creates" << name << std::endl;
				return (this->*ptrFonct[i])(target);
			}
		}
		throw Intern::noCreated();
	}
	catch (const std::exception &e)	{
		std::cerr  << RED << e.what() << name << NC <<std::endl;
		throw Intern::noNull();
	}
}
