#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <regex.h>
#include <limits>
#include <cstdlib> //strtod

enum e_type {
    NONE,
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    STR
};

class ScalarConverter
{
	public:
		~ScalarConverter();
		static void	convert(char *arg);
		static int	wichType(char *arg);
		static int	match(char const *str, char const *expression);
		static bool	limInt(double nbr);
		static void	printable(int c);
		static void	caseStr(std::string param);
	private:
		ScalarConverter();
		ScalarConverter (const ScalarConverter &copy);
		ScalarConverter &operator=(const ScalarConverter&);

};

#endif
