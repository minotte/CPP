#include "BitcoinExchange.hpp"


BitcoinExchange::BitcoinExchange(){
}

BitcoinExchange::BitcoinExchange(char *argv){
	std::ifstream ifs;
	std::ifstream data;
	data.open ("data.csv", std::ifstream::in);
	std::string firstLine;
	std::getline(data, firstLine, '\n');
	if (firstLine != "date,exchange_rate"){
		std::cerr << RED << "The file data.csv need to start by \"date,exchange_rate\"" << NC << std::endl;
		return;
	}
	std::string line;
	int i = 0; 
	while ( std::getline(data, line))
	{
		if (parsingCsv(line) == false){
			std::cerr << "Fail data.csv at line " << i << " : " << line <<std::endl; 
			data.close();
			return;
		}
		this->_bitcoinTab.insert(std::make_pair(line.substr(0, 10), std::strtod(line.substr(11).c_str(), NULL)));
		i++;
	}
	data.close();

	ifs.open (argv, std::ifstream::in);
	if (ifs.is_open() == false){
		std::cerr << "Error: at the openning of " << argv << std::endl;
		return;
	}
	getline(ifs, firstLine, '\n');
	if (firstLine != "date | value"){
		std::cerr << RED << "The file need to start by \"date | value\"" << NC << std::endl;
		return;
	}
	while ( std::getline(ifs, line))
		parsingInput(line);
	ifs.close();

}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src){
	*this = src;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &src){
	this->_bitcoinTab = src._bitcoinTab;
	return *this;
}

BitcoinExchange::~BitcoinExchange(){

}

bool	day(std::string y, std::string m, std::string d){
	int day = atoi(d.c_str());
	int year = atoi(y.c_str());
	int month = atoi(m.c_str());

	if (month == 2){
		if (year % 4 == 0 && ( year % 100 != 0 || year % 400 == 0)){
			if (day > 29){
				std::cerr << "Error: bad input => " << y << "-" << m << "-" << d << std::endl;
				return false;
			}
		}
		else if (day > 28){
			std::cerr << "Error: bad input => " << y << "-" << m << "-" << d << std::endl;
			return false;
		}
	}
	else if(month == 1 || month == 3 || month== 5 || month == 7 || month == 8 || month == 10 || month == 12){
		if (day > 31){
			std::cerr << "Error: bad input => " << y << "-" << m << "-" << d << std::endl;
			return false;
		}
	}
	else{
		if (day > 30)
			std::cerr << "Error: bad input => " << y << "-" << m << "-" << d << std::endl;
	}
	return true;
}

bool	month(std::string m){
	int month = atoi(m.c_str());
	if(month > 12){
		std::cerr << "month not valid" << std::endl;
		return false;
	}
	return true;
}

bool	year(std::string y){
	int year = atoi(y.c_str());
	if(year < 2009){
		std::cerr << "year not valid" << std::endl;
		return false;
	}
	return true;
}

bool	BitcoinExchange::parsingCsv(std::string str){
	std::string expression = "^[0-9]{4}-[0-9]{2}-[0-9]{2},([0-9]{0,7})(\\.[0-9]{1,2})?$";
	if (doRegex(str.c_str(), expression.c_str())){
		return false;
	}
	std::string y = str.substr(0, 4);
	std::string m = str.substr(5, 2);
	std::string d = str.substr(8, 2);
	if(!year(y) || !month(m) || !day(y, m, d))
		return false;
	return true;
}

int	BitcoinExchange::parsingInput(std::string str){
	std::string expression = "^[0-9]{4}-[0-9]{2}-[0-9]{2}[ ][|][ ]([-]?[0-9]{0,10})(\\.[0-9]{1,2})?$";
	if (doRegex(str.c_str(), expression.c_str())){
		std::cerr << "Error: bad input => " << str << std::endl;
		return 1;
	}
	std::string y = str.substr(0, 4);
	std::string m = str.substr(5, 2);
	std::string d = str.substr(8, 2);
	if(!year(y) || !month(m) || !day(y, m, d))
		return 1;
	BitcoinExchange::print(str);
	return 0;
}

void	BitcoinExchange::print(std::string str){
	double value = std::strtod(str.substr(13).c_str(), NULL);
	if ( value > 1000.0 ){
		std::cout << "Error: too large a number." << std::endl;
		return;
	}
	else if ( value < 0 ){
		std::cout << "Error: not a positive number." << std::endl;
		return;
	}
	std::string date = str.substr(0, 10); 
	std::map<std::string, float>::iterator it = this->_bitcoinTab.lower_bound(date);
	if (it->first != date){
		if(it == this->_bitcoinTab.begin()){
			std::cout << "The bitcoin didn't exist at this date" <<std::endl;
			return;
		}
		it--;
	}
	std::cout << date << " => " <<  value  << " = " << value  * it->second <<std::endl;
}
