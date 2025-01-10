#include "Harl.hpp"
#include <string>

Harl::Harl(){

}

Harl::~Harl(){
	return;
}

void Harl::switchCase(std::string instruction){
	int	i;
	std::string	level[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (i = 0; i < 4; i++){
		if(!instruction.compare(level[i]))
			break;
	}
	switch (i) {
		case DEBUG:
			std::cout << "\033[0;33m{ DEBUG }\033[0m" << std::endl;
			std::cout << "\033[0;33mYou thing there is a problem in the program?\033[0m" << std::endl;

		case INFO:
			std::cout << "\033[0;33m{ INFO }\033[0m" << std::endl;
			std::cout << "\033[4;32mthe best program ever!\033[0m" << std::endl;

		case WARNING:
			std::cout << "\033[0;33m{ WARNING }\033[0m" << std::endl;
			std::cout << "\033[5;35mWarning ! Warning!!!!\033[0m" << std::endl << "Something is wrong!!!" << std::endl;

		case ERROR:
			std::cout << "\033[0;33m{ ERROR }\033[0m" << std::endl;
			for (int i = 0; i < 11; i++)
				std::cout << "\033[1;31mExterminate\033[0m" << std::endl;
			break;

		default:
			std::cout << "\033[0;36mDon't understand what you say, but 323030313A2061207370616365206F64797373657920697320626F72696E672E0A\033[0m" << std::endl;
			break;
	}
}
