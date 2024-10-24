#include "Span.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>

int main()
{
	{
		try{
			Span sp = Span(5);
			sp.addNumber(6);
			sp.addNumber(3);
			sp.addNumber(17);
			sp.addNumber(9);
			sp.addNumber(11);
			std::cout << sp.getTab(3) << std::endl;
			Span spa = sp;
			std::cout << "test of the copy : "<< sp.getTab(3) << std::endl;
			std::cout << "Shortest span : " << sp.shortestSpan() << std::endl;
			std::cout << "Longest span : " << sp.longestSpan() << std::endl;
			sp.addNumber(11);
		}
		catch(const std::out_of_range &e){
			std::cerr << RED << e.what() << NC << std::endl;
		}
	}
	{
		try{
			Span sp(1);
			sp.addRangeNumber(8, 6);
			std::cout << sp.shortestSpan() << std::endl;
			std::cout << sp.longestSpan() << std::endl;
		}
		catch(const std::out_of_range &e){
			std::cerr << RED << e.what() << NC << std::endl;
		}
	}
	{
		try{
			Span sp(31);
			
			sp.addRangeNumber(1, 6);
			sp.addRangeNumber(8, 9);
			sp.addNumber(50);
			sp.addRangeNumber(3, 11);
			std::cout << "Shortest Span : " <<  sp.shortestSpan() << std::endl;
			std::cout << "Longest Span : " << sp.longestSpan() << std::endl;
		}
		catch(const std::out_of_range &e){
			std::cerr << RED << e.what() << NC << std::endl;
		}
	}
	return 0;
}
