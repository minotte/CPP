#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

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
		Form fo("A4", 80, 35);
		std::cout << fo << std::endl;
		a.signForm(fo);
		std::cout << fo << std::endl;
		b.signForm(fo);
		std::cout << fo << std::endl;
		Form P;
		std::cout << P << std::endl;
		a.signForm(P);
		std::cout << P << std::endl;
		a.signForm(fo);
		std::cout << fo << std::endl;
		}
	catch (const std::exception &e){
		std::cout << e.what() <<std::endl;
	}
	return 0;
}
