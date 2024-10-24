#include "Form.hpp"
#include "iostream"

Form::Form() : _name("unknow"), _signature(false), _gradeToSign(150), _gradeToExec(150){
	std::cout << GREY <<  "Form constructor default" <<  NC << std::endl;
}

Form::Form(std::string const name, int const gradeToSign, int const gradeToExec): _name(name), _signature(0), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec){
	if(gradeToSign < 1 || gradeToExec < 1)
		throw Form::GradeTooHighException();
	else if (gradeToSign > 150 || gradeToExec > 150)
		throw Form::GradeTooLowException();
	else
		std::cout << GREY  << "Form constructor" << NC << std::endl;
}

Form::Form(Form const & src): _name(src._name), _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec){
	std::cout << GREY  << "Form copy constructor" << NC << std::endl;
	*this = src;
}

Form & Form::operator=(Form const & src){
	this->_signature = src._signature;
	return *this;
}

Form::~Form(){
	std::cout << GREY  << "Form destructor" << NC << std::endl;
}

std::ostream & operator<<( std::ostream &out, Form const & in){
	out << "name form : " << in.getName() << std::endl ;
	out << "signature : " << in.getSignature() << std::endl ;
	out << "grade to sign the form : " <<  in.getGradeToSign() << std::endl ;
	out << "grade to execute the form : " << in.getGradeToExec() << std::endl ;
	return out;
}

/*************       GETTER               ************/

std::string const	Form::getName() const{
	return this->_name;
}

bool	Form::getSignature() const{
	return this->_signature;
}

int Form::getGradeToSign() const{
	return this->_gradeToSign;
}

int	Form::getGradeToExec() const{
	return this->_gradeToExec;
}

/********************** Function        *****************/

void	Form::beSigned(Bureaucrat& bureaucrat){
	try{
		if (bureaucrat.getGrade() > this->getGradeToSign())
			throw Form::GradeTooLowException();
		this->_signature = true;
	}
	catch (const std::exception &e){
		std::cerr << RED << "Error : " << e.what() << NC << std::endl;
	}
}

const char* Form::GradeTooHighException::what() const throw(){
	return ("Form is too hight.");
}

const char* Form::GradeTooLowException::what() const throw(){
	return ("Form is too low.");
}
