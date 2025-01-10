#include "Harl.hpp"

Harl::Harl( void ) {
	this->_level[0] = "DEBUG";
	this->_level[1] = "INFO";
	this->_level[2] = "WARNING";
	this->_level[3] = "ERROR";
 	return;
}

Harl::~Harl(){
	return;
}

void Harl::debug( void ){
	std::cout << "\033[0;33mYou thing there is a problem in the program?\033[0m" << std::endl;
}

void Harl::info( void ){
	std::cout << "\033[4;32mthe best program ever!\033[0m" << std::endl;
}

void Harl::warning( void ){
	std::cout << "\033[5;35mSomething looks wrong!!!\033[0m" << std::endl;
}

void Harl::error( void ){
	for (int i = 0; i < 11; i++)
		std::cout << "\033[1;31mExterminate\033[0m" << std::endl;
}

void Harl::other( void ){
			std::cout << "\033[0;36mDon't understand what you say, but 323030313A2061207370616365206F64797373657920697320626F72696E672E0A\033[0m" << std::endl;
}

void Harl::complain(std::string level){
	int i;
	void (Harl::*ptrFonct[5])() = { &Harl::debug, &Harl::info, &Harl::warning, &Harl::error, &Harl::other}; //pointeur on fonction
	for (i = 0; i < 4; i++){
		if (!level.compare(this->_level[i]))
			break;
	}
	(this->*(ptrFonct[i]))();
}
