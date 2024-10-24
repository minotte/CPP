#include "easyfind.hpp"
#include <exception>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <vector>
#include <list>
#include <algorithm>

int	main(void){
	{
		try{
			std::vector<int> vect ;

			std::cout << "##################  Vector ################" << std::endl;
			vect.push_back(54);
			vect.push_back(24);
			vect.push_back(42);
			vect.push_back(24);


			for (size_t i = 0; i < vect.size(); i++)
				std::cout << "Vector[" << i << "] :" << vect[i] <<std::endl; 

			std::cout << "-----------   easyfind   ----------" << std::endl;

			std::vector<int>::const_iterator i = ::easyfind(vect, 42);
			if (i == vect.end())
				throw std::out_of_range("Error : out of range");
			std::cout << "We can find : " << *i << std::endl;
			std::cout << &i << std::endl;
			std::vector<int>::const_iterator j = ::easyfind(vect, -82);
			if (j == vect.end())
				throw std::out_of_range("Error : out of range");
			std::cout << *j << std::endl;
		}
		catch(const std::out_of_range &e){
			std::cerr << RED <<  e.what() << NC << std::endl; 
		}
	}
	{
		try{
			std::cout << std::endl << "##################  List ################" << std::endl;
			int	intlst[] = { 4527, 4, 85, 9, 14, 20 };
			std::list<int> lst(intlst, intlst+ 6);
			std::list<int>::const_iterator i = ::easyfind(lst, 9);
			if (i == lst.end())
				throw std::out_of_range("Error : out of range");

			std::cout << "---------------------" << std::endl;
			std::cout << "you can find " << *i << " in the list."  << std::endl;
			std::cout << &i << std::endl;

			std::list<int>::const_iterator j = ::easyfind(lst, 19);
			if (j == lst.end())
				throw std::out_of_range("Error : out of range");
			std::cout << "you can find "  << *j << " in the list."  << std::endl;
		}
		catch (const std::out_of_range &e){
			std::cerr << RED <<  e.what() << NC << std::endl; 
		}
	}
}
