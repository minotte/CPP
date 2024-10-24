#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("John Doe"), _grade(150){
	std::cout << GREY << "Bureaucrat constructor default" << NC << std::endl;
}

Bureaucrat::Bureaucrat(std::string const & name, int grade): _name(name), _grade(grade){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << GREY << "Bureaucrat constructor" << NC << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name){
	std::cout << GREY << "Bureaucrat copy constructor" << NC << std::endl;
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &src){
	this->_grade = src._grade;
	return *this;
}

Bureaucrat::~Bureaucrat(){
	std::cout << GREY << "Bureaucrat Destructor" << NC << std::endl;
}

/************************* GETTER  ***************************/

std::string const	Bureaucrat::getName() const{
	return this->_name;
}

int					Bureaucrat::getGrade() const{
	return this->_grade;
}

/*********************** Function *****************************/

void	Bureaucrat::incrementGrade(){
	try{
		if (this->_grade > 1)
			this->_grade--;
		else
			throw Bureaucrat::GradeTooHighException();
	}
		catch (const std::exception & e){
		std::cerr << RED << this->getName() << " can't have a promotion because " << e.what() << NC << std::endl; 
	}
}


void	Bureaucrat::decrementGrade(){
	try{
		if ( this->_grade < 150 )
			this->_grade++;
		else
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const std::exception & e){
		std::cerr << this->getName() << " can't have a demotion because " << e.what() << std::endl; 
	}
}
 
void	Bureaucrat::signForm(AForm& form){
	if (form.getSignature() == 1)
		std::cerr << RED << "It's already sign!!!" << NC << std::endl;
	else if (this->_grade <= form.getGradeToSign()){
		form.beSigned(*this);
		std::cout << this->getName() <<  " could signed " << form.getName() << std::endl;
	}
	else
		std::cout << RED << this->getName() <<  " couldn't signed " << form.getName() << " to sign it, the grade need to be at " << form.getGradeToSign() << " grade or higher, and " << this->getName() << " is just " << this->getGrade() << NC << std::endl;
}

void	Bureaucrat::executeForm(AForm const & form){
	try{
		if (!form.getSignature())
			throw AForm::NeedToBeSign();
		if (form.getGradeToExec() < this->_grade)
			throw Bureaucrat::GradeTooLowException();
		form.execute(*this);
	}
	catch (const std::exception &e){
		std::cerr << RED << this->getName() << " can't execute because " << e.what() << NC << std::endl;
	}
}

/**************************************************************/

std::ostream & operator<<( std::ostream & out, Bureaucrat const & in ){
	out << in.getName() << ", bureaucrat grade " << in.getGrade() << "." << std::endl;
	return out;
}

/************************* Exception **************************/

const char* Bureaucrat::GradeTooHighException::what() const throw(){
		return ("his grade is too hight!!!");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw(){
	return ("his grade is too low!!!");
}
