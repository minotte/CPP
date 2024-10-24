#include "Bureaucrat.hpp"
#include <exception>

/************************ Constructor ********************************/

Bureaucrat::Bureaucrat() : _name("John Doe"), _grade(150){
	std::cout << GREY << "Bureaucrat constructor default" << NC << std::endl;

}

Bureaucrat::Bureaucrat(std::string const & name, int grade):_name(name), _grade(grade){
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	std::cout << GREY << "Bureaucrat constructor"<< NC << std::endl;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()){
	std::cout << GREY << "Bureaucrat copy constructor" << NC << std::endl;
	*this = src;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &src){
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

/***************************** function **********************/

void	Bureaucrat::increment(){
	try{
		if (this->_grade > 1)
			this->_grade--;
		else
			throw Bureaucrat::GradeTooHighException();
	} catch (const std::exception & e){
		std::cerr << RED << this->getName() << " can't have a promotion because " << e.what() << NC<< std::endl; 
	}
}

void	Bureaucrat::decrement(){
	try{
		if (this->_grade < 150)
			this->_grade++;
		else
			throw Bureaucrat::GradeTooLowException();
	}
	catch (const std::exception & e){
		std::cerr << RED << this->getName() << " can't have a demotion because " << e.what() << NC << std::endl; 
	}

}


std::ostream &	operator<<( std::ostream & out, Bureaucrat const & in ){
	out << in.getName() << ", bureaucrat grade " << in.getGrade() << "." << std::endl;
	return out;
}

const char* Bureaucrat::GradeTooHighException::what(void) const throw(){
	return ("The grade is too hight!!!");
}

const char* Bureaucrat::GradeTooLowException::what(void) const throw(){
	return ("The grade is too low!!!");
}
