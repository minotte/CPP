#include "RobotomyRequestForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <time.h>
#include <stdlib.h>

RobotomyRequestForm::RobotomyRequestForm(): AForm("RobotomyRequestForm", 72, 45){
	this->setTarget("null");
	std::cout << GREY << "RobotomyRequestForm Constructor" << NC << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target): AForm("RobotomyRequestForm", 72, 45){
	this->setTarget(target);
	std::cout << GREY  << "RobotomyRequestForm Constructor" << NC<< std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src): AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()) {
	*this = src;
	std::cout << GREY  << "RobotomyRequestForm copy Constructor" << NC<< std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const & src){
	this->setSignature(src.getSignature());
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << GREY  << "RobotomyRequestForm Destructor" << NC<< std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const{
	try{
		if(!this->getSignature())
			throw AForm::NeedToBeSign();
		if (executor.getGrade() > this->getGradeToExec())
			throw Bureaucrat::GradeTooLowException();
		srand (time(NULL));
		int randomValue = rand() % 10;
		std::cout << "\abip bip bip\a" << std::endl;
		if (randomValue % 2 == 0)
			std::cout << this->getTarget() << " has been robotomized" << std::endl;
		else
			std::cerr << RED << "Failled: " <<this->getTarget() << " hasn't been robotomized" << NC << std::endl;
	}
	catch (const std::exception &e){
		std::cerr << RED << "ERROR: " << e.what() << NC << std::endl;
	}
}
