#include "Base.hpp"
#include <typeinfo>

Base * Base::generate(void){
	switch(rand() % 3)
	{
		case 0:
			std::cout << "A is contructed" << std::endl;
			return new A();
		case 1:
			std::cout << "B is contructed" << std::endl;
			return new B();
		default:
			std::cout << "C is contructed" << std::endl;
			return new C();
	}
}

void	Base::identify(Base* p){
	if (p == NULL){
		std::cout << "NULL" << std::endl;
		return;
	}
	A*	a = dynamic_cast<A*>(p);
	// if (a == NULL)
		// std::cout << "A conversion is wrong" << std::endl;
	if (p == a)
		std::cout << "A" << std::endl;
	B*	b = dynamic_cast<B*>(p);
	// if (b == NULL)
		// std::cout << "B conversion is wrong" << std::endl;
	if (p == b)
		std::cout << "B" << std::endl;
	C* c = dynamic_cast<C*>(p);
	// if (c == NULL)
		// std::cout << "C conversion is wrong" << std::endl;
	if (p == c)
		std::cout << "C" << std::endl;
}

void Base::identify(Base& p){
	try{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &bc) {
		// std::cout << "Error conversion for A : " << bc.what() << std::endl;
	}
	try{
		B& b = dynamic_cast<B &>(p);
		(void)b;
		std::cout << "B" << std::endl;
	}
	catch (std::bad_cast &bc) {
		// std::cout << "Error conversion for B : " << bc.what() << std::endl;
	}
	try{
		C& c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
	}
	catch (std::bad_cast &bc) {
		// std::cout << "Error conversion for C : " << bc.what() << std::endl;
	}
}
