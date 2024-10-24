#include "Bureaucrat.hpp"
#include <cstdio>
#include <exception>

int	main(){
	{
	try{
		Bureaucrat a;
		std::cout << a << std::endl;
		Bureaucrat b = Bureaucrat("A+", 8);
		Bureaucrat c = b;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		c.decrement();
		c.decrement();
		c.decrement();
		c.decrement();
		a.decrement();
		std::cout << "-------------------" << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;
		std::cout << a << std::endl;
		// Bureaucrat	hello = Bureaucrat(NULL, 0);
		Bureaucrat	francois = Bureaucrat("François", 1);
		francois.increment();
		std::cout << francois << std::endl;
		// std::cout << hello << std::endl;
		Bureaucrat d("ffffffff", 151);
	}
	catch (const std::exception &e){
		std::cerr << RED << e.what() << NC <<std::endl;
	}
	}
	{
		Bureaucrat *A = new Bureaucrat();
		Bureaucrat B = *A;
		delete A;
		std::cout << B ;
	} 
	return 0;
}
