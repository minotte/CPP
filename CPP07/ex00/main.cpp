#include "whatever.hpp"
#include <iostream>

int	main(){
	int a = 9;
	int v = 95;

	std::cout << "max of " << a << " and " << v << " is :";
	std::cout << ::max<int>(a, v) << std::endl; //explicite
	std::cout << "max of " << a << " and " << v << " is :";
	std::cout << ::max(a, v) << std::endl; //implicite

	{
		int a = 2;
		int b = 3;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::string c = "chaine1";
		std::string d = "chaine2";
		::swap(c, d);
		std::cout << "c = " << c << ", d = " << d << std::endl;
		std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
		std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	}
	{
		std::string a = "Hello, how are you?";
		std::string b = "I don't know what to say";
		std::cout << "before swap a : " << a << std::endl;
		std::cout << "before swap b : " << b << std::endl;
		::swap( a, b );
		std::cout << "a = " << a << ", b = " << b << std::endl;
		std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
		std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
		std::cout << "a = " << a << ", b = " << b << std::endl;
	}
	return 0;
}
