#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5){
	this->setTarget("No body");
	std::cout << GREY << "PresidentialPardonForm Constructor" << NC << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5){
	this->setTarget(target);
	std::cout << GREY << "PresidentialPardonForm Constructor" << NC << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): AForm(src.getName(), src.getGradeToSign(), src.getGradeToExec()){
	std::cout << GREY << "PresidentialPardonForm copy Constructor" << NC << std::endl;
	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const & src){
	this->setSignature(src.getSignature());
	this->setTarget(src.getTarget());
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << GREY << "PresidentialPardonForm Destructor" << NC << std::endl;
}

void  PresidentialPardonForm::execute(Bureaucrat const & executor) const{
	try{
		if (!this->getSignature())
			throw AForm::NeedToBeSign();
		if (executor.getGrade() > this->getGradeToExec())
			throw Bureaucrat::GradeTooLowException();
		std::cout <<"\033[38;5;2m" << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << NC << std::endl;
	}

	catch (const std::exception &e){
		std::cerr << RED << executor.getName() << " can't execute " << NC << this->getName() << " because " << e.what();
	}
}
