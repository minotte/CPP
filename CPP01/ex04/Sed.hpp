#ifndef SED_HPP
# define SED_HPP

#include <iostream>
#include <string>
#include <fstream>

class Sed
{
	public:
		Sed(std::string  fileName, std::string strToReplace, std::string strReplaceBy);
		~Sed( void );
		std::string	changeStr(std::string txt);
		void	ftSed();
	private:
		std::string 	_fileName;
		std::string _strToReplace;
		std::string	_strReplaceBy;
};

#endif
