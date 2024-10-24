#include "AForm.hpp"
#include "iostream"

AForm::AForm() : _name("unknow"), _signature(false), _gradeToSign(150), _gradeToExec(150), _target("none"){
	std::cout << GREY << "AForm constructor default" << NC << std::endl;
}

AForm::AForm(std::string const name, int const gradeToSign, int const gradeToExec): _name(name), _signature(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _target("none"){
	if(gradeToSign < 1 || gradeToExec < 1)
		throw AForm::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw AForm::GradeTooLowException();
	else
		std::cout << GREY << "AForm constructor" << NC << std::endl;
}

AForm::AForm(AForm const & src): _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec){
	std::cout << GREY << "AForm copy constructor" << NC << std::endl;
	*this = src;
}

AForm & AForm::operator=(AForm const & src){
	this->_signature = src._signature;
	this->_target = src._target;
	return *this;
}

AForm::~AForm(){
	std::cout << GREY << "AForm destructor" << NC << std::endl;
}

std::ostream & operator<<( std::ostream  &out, AForm const & in){
	out << "name form : " << in.getName() << std::endl ;
	out << "target form : " << in.getTarget() << std::endl ;
	out << "signature : " << in.getSignature() << std::endl ;
	out << "grade to sign the form : " <<  in.getGradeToSign() << std::endl ;
	out << "grade to execute the form : " << in.getGradeToExec() << std::endl ;
	return out;
}

/*************       GETTER               ************/

std::string const	AForm::getName() const{
	return this->_name;
}

bool	AForm::getSignature() const{
	return this->_signature;
}

int AForm::getGradeToSign() const{
	return this->_gradeToSign;
}

int	AForm::getGradeToExec() const{
	return this->_gradeToExec;
}

std::string	AForm::getTarget() const{
	return this->_target;
}

void	AForm::setTarget(std::string target){
	this->_target = target;
}

void	AForm::setSignature(bool signature){
	this->_signature = signature;
}

/********************** Function        *****************/

void	AForm::beSigned(Bureaucrat& bureaucrat){
	try{
		if (bureaucrat.getGrade() > this->getGradeToSign())
			throw AForm::GradeTooLowException();
		this->_signature = true;
	}
	catch (const std::exception &e){
		std::cerr << RED << "Error : " << e.what() << NC << std::endl;
	}
}

const char* AForm::GradeTooHighException::what() const throw(){
	return ("AForm is too hight.");
}

const char* AForm::GradeTooLowException::what() const throw(){
	return ("AForm is too low.");
}
