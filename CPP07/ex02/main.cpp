#include "Array.hpp"
#include <iostream>
#include <string>

int	main(){
	{
		try{
			Array< int > b;
			Array< int >  a( 10 );
			Array<std::string> str(2);
			std::cout << "size  of a : " << a.size() << std::endl;
			std::cout << "size  of b : " << b.size() << std::endl;
			a[2] = 55;
			str[0] = "Hello" ; 
			str[1] = "How are you?";
			for (int i = 0; i < 2; i++)
				std::cout << str[i] << std::endl;
			str[0] = "Hi";
			std::cout << "size  of str: " << str.size() << std::endl;
			for (int i = 0; i < 3; i++)
				std::cout << str[i] << std::endl;
			return 0;
		}
		catch( const std::exception &e ) {
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}
	std::cout << "----------------------------------------" << std::endl;
	{
		try{
			Array< double > d(3);
			d[0] = 100.0;
			d[1] = 0.5;
		
			std::cout << "double [1] : " << d[1] <<std::endl;  
			d[3] = 9;
			return 0;
		}
		catch( const std::exception &e ) {
			std::cerr << "Error : " << e.what() << std::endl;
		}
	}
}
