#include "Sed.hpp"

Sed::Sed(std::string fileName, std::string strToReplace, std::string strReplaceBy) : _fileName(fileName), _strToReplace(strToReplace), _strReplaceBy(strReplaceBy)
{
	std::cout << "Constructor called" << std::endl;
	std::cout << "--------------------------------------------" << std::endl << std::endl;
}

Sed::~Sed( void )
{
	std::cout << std::endl << "--------------------------------------------" << std::endl;
	std::cout << "Destructor called" << std::endl;
}

std::string	Sed::changeStr(std::string txt){
	int	i = 0;

	while (txt.npos != txt.find(this->_strToReplace, i)){
		i = txt.find(this->_strToReplace, i);
		txt.erase(i, this->_strToReplace.length());
		txt.insert(i, this->_strReplaceBy);
		i += this->_strReplaceBy.length();
	}
	return (txt);
} 

void	Sed::ftSed(){
	std::fstream	ifile;
	char			c;
	std::string		txt = "";
	std::fstream	ofile;

	ifile.open(this->_fileName.c_str());
	if (!ifile.is_open()){
		std::cerr << this->_fileName << " can't be open" << std::endl;
		return;
	}
	while (ifile.get(c))
		txt += c;
	if (txt.empty()){
		std::cerr << "empty file" << std::endl;
		return;
	}
	if (!this->_strToReplace.empty())
		txt = Sed::changeStr(txt);

	/* --------- open and create the new file with the changement -------*/
	ofile.open(this->_fileName.append(".replace").c_str(), std::fstream::in | std::fstream::out | std::fstream::trunc );

	// if (!ofile.is_()){
		// std::cerr << this->_fileName << " can't be open" << std::endl;
		// return;
	// }
// 
	ofile << txt;
	std::cout << "Operation Done:" << std::endl << this->_fileName << " is created." << std::endl;
}
