#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <cstdio>
#include <string>
#include <iostream>

void	print_start(void)
{
	std::cout << "--------------Welcome--------------" << std::endl << std::endl;
	std::cout << "I am your old phone book" << std::endl;
	std::cout << "What do you want do" << std::endl;
	std::cout << "To add user write \"ADD\"" << std::endl;
	std::cout << "To find a contact write \"SEARCH\"" << std::endl;
	std::cout << "To quit enter \"EXIT\"" << std::endl << std::endl;
	std::cout << "-----------------------------------" << std::endl << std::endl;
	std::cout << "> ";
}

void	print_instruction(void)
{
	std::cout << std::endl;
	std::cout << "-----------------------------------" << std::endl;
	std::cout << "To add user write \"ADD\"" << std::endl;
	std::cout << "To find a contact write \"SEARCH\"" << std::endl;
	std::cout << "To quit enter \"EXIT\"" << std::endl << std::endl;
}

int	 main( void ){
	PhoneBook	instance_book;
	std::string instruction;	

	print_start();
	while (std::getline(std::cin, instruction)){
		if ( instruction.compare("ADD") == 0 )
			instance_book.add();
		else if ( instruction.compare("SEARCH") == 0 )
			instance_book.search();
		else if ( instruction.compare("EXIT") == 0 ){
			instance_book.close();
			break ;
		}
		else
			print_instruction();
		std::cout << "> ";
	}
	return (0);
}
