#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>
#include <iostream>
#include <fstream>
#include <exception> 
#include <stdlib.h> 

#define RED		"\033[38;5;1m"
#define NC	"\033[0m"

class BitcoinExchange{
	 public:
		BitcoinExchange(char *argv);
		BitcoinExchange(BitcoinExchange const &src);
		BitcoinExchange &operator=(BitcoinExchange const &src);
		~BitcoinExchange();
	 private:
		BitcoinExchange();
		std::map<std::string, float> _bitcoinTab;
		bool	parsingCsv(std::string str);
		int	parsingInput(std::string str);
		void	print(std::string str);
};
int	doRegex(char const *str, char const *expression);

#endif
