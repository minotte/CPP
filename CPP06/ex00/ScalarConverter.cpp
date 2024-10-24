#include "ScalarConverter.hpp"
#include <regex.h>

ScalarConverter::ScalarConverter(){
	std::cout << "ScalarConverter Constructor called" <<std::endl;
	return;
}

ScalarConverter::~ScalarConverter(){
	std::cout << "ScalarConverter Destructor called" <<std::endl;
	return;
}

ScalarConverter::ScalarConverter(const ScalarConverter &copy){
	std::cout << "ScalarConverter copy Constructor called" <<std::endl;
	*this = copy;
}

ScalarConverter & ScalarConverter::operator=(const ScalarConverter &copy){
	(void)copy;
	return (*this);
}

int	ScalarConverter::match(char const *str, char const *expression){
	regex_t	regex;
	if( regcomp(&regex, expression, REG_EXTENDED)){
		regfree(&regex);
		return (1);
	}
	if (!regexec(&regex, str, 0, NULL, 0)){
		regfree(&regex);
		return 0;
	} 
	regfree(&regex);
	return 1;
}


int	ScalarConverter::wichType(char *arg){
	char const	*none = "^$";
	char const	*c = "^[[:print:]]\\D$";
	char const	*nb = "^[+-]?[0-9]+$";
	char const	*nbF = "^[+|-]?[0-9]+[.][0-9]+f$";
	char const	*nbD = "^[+|-]?[0-9]+[.][0-9]+$";
	char const	*str = "^[[:print:]]+$";
	char const	*pattern[6] = {none, c, nb, nbF, nbD, str};
	for(int i = 0; i < 6; i++){
		if (!ScalarConverter::match(arg, pattern[i]))
			return i ;
	}
	return (-1);
}

bool	ScalarConverter::limInt(double nbr){
	if (nbr < std::numeric_limits<int>::min()){
		std::cout << "too low";
		return false;
	}
	else if (nbr > std::numeric_limits<int>::max()){
		std::cout << "too hight";
		return false;
	}
	std::cout << static_cast<int>(nbr);
	return true;
}

void	ScalarConverter::printable(int c){
	if (c < 32  || c > 126)
		std::cout << "Non displayable";
	else
		std::cout << static_cast<char>(c);
}

void	ScalarConverter::caseStr(std::string param){
	if (param == "nan" || param == "nanf"){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (param == "inf" || param == "inff" || param == "+inf" || param == "+inff"){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (param == "-inf" || param == "-inff"){
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}

void	ScalarConverter::convert(char *arg){
	bool flag = false;
	switch ( ScalarConverter::wichType(arg)){
		case NONE:
			std::cout << "char : empty" << std::endl << "int : empty" << std::endl << "float : empty" << std::endl << "double : empty" << std::endl;
			break;
		case CHAR:
			std::cout << "char : " << arg << std::endl << "int : " << static_cast<int>(*arg) << std::endl << "float : " <<  static_cast<float>(*arg)  << ".0f" << std::endl << "double  " <<  static_cast<double>(*arg)  << ".0" << std::endl;
			break;
		case INT:
			std::cout << "char : ";
			ScalarConverter::printable(std::strtod(arg, NULL));
			std::cout << std::endl << "int : ";
			flag = ScalarConverter::limInt((std::strtod(arg, NULL)));
			std::cout << std::endl << "float : " << static_cast<float>(std::strtod(arg, NULL));
			if (flag == true)
				 std::cout << ".0";
			std::cout << "f" << std::endl << "double  " <<  std::strtod(arg, NULL);
			if (flag == true)
				std::cout << ".0";
			std::cout << std::endl;
			break;
		case FLOAT:
			std::cout << "char : ";
			ScalarConverter::printable(static_cast<int>(std::strtod(arg, NULL)));
			std::cout << std::endl  << "int : ";
			ScalarConverter::limInt((std::strtod(arg, NULL)));
			std::cout << std::endl << "float : " <<  static_cast<float>(std::strtod(arg, NULL))  << "f" <<  std::endl << "double  " <<  std::strtod(arg, NULL)  <<  std::endl;
			break;
		case DOUBLE:
			std::cout << "char : ";
			ScalarConverter::printable(static_cast<int>(std::strtod(arg, NULL)));
			std::cout << std::endl  << "int : ";
			ScalarConverter::limInt((std::strtod(arg, NULL)));
			std::cout << std::endl << "float : " <<  static_cast<float>(std::strtod(arg, NULL))  << "f" <<  std::endl << "double  " <<  std::strtod(arg, NULL)  <<  std::endl;
			break;
		case STR:
			ScalarConverter::caseStr((std::string)arg);
			break;
		default:
			std::cout << "char : impossible" << std::endl << "int : impossible" << std::endl << "float : impossible" << std::endl << "double : impossible" << std::endl;
			break;
	}
}
