#include "PhoneBook.hpp"


PhoneBook::PhoneBook( void ){
	std::cout << "constructor called" << std::endl;
	this->_index = 7;
	this->_indexMax = -1;
	return;
}

PhoneBook::~PhoneBook( void ){
	std::cout << "destructor called" << std::endl;
	return;
}

void	PhoneBook::add( void ){
	std::string	name;
	std::string	lname;
	std::string	nname;
	std::string	phonenumb;
	std::string	secret;
	std::string	split;


	if (this->_index == 7)  this->_index = 0;
	else
		this->_index++;
	std::cout << "You will enter a new contact enter information, pls" << std::endl;
	std::cout << "First name : ";
	std::getline(std::cin, name);
	std::cout << "Last name : ";
	std::getline(std::cin, lname);
	std::cout << "nickname : ";
	std::getline(std::cin, nname);
	std::cout << "phone number : ";
	std::getline(std::cin, phonenumb);
	std::cout << "Darkest secret : ";
	std::getline(std::cin, secret);
	if (name  == "" && lname  == "" && nname == "" && phonenumb == "" && secret == "")
	{
		std::cout << "need information to save contact" << std::endl;
		if (this->_index == 0)
			this->_index = 7;
		else
			this->_index--;
	}
	else{
		this->_instanceContact[_index].setFirstName( name );
		this->_instanceContact[_index].setLastName( lname );
		this->_instanceContact[_index].setNickname( nname );
		this->_instanceContact[_index].setPhoneNumber( phonenumb );
		this->_instanceContact[_index].setDarkestSecret( secret );
	}
	if (this->_index > this->_indexMax)
		this->_indexMax += 1;
}

void	PhoneBook::search( void ){
	std::string	index;
	int			i;

	i = 0;
	if(this->_indexMax < 0)
	{
		std::cout << "There is no contact in your phone!!!" << std::endl;
		return;
	}
	std::cout << "|     index|first name| last name|  nickname|" << std::endl; 
	while (i <= this->_indexMax)	{
		std::cout << "|";
		std::cout << "         " << i;
		std::cout << "|";
		std::cout << this->_instanceContact[i].tenChar(this->_instanceContact[i].getFirstName());
		std::cout << "|";
		std::cout << this->_instanceContact[i].tenChar(this->_instanceContact[i].getLastName());
		std::cout << "|";
		std::cout << this->_instanceContact[i].tenChar(this->_instanceContact[i].getNickname());
		std::cout << "|";
		std::cout << std::endl;
		i++;
	}
	std::cout << "You want have more information on one contact? " << std::endl;
	std::cout << "enter his index : ";
	std::getline(std::cin, index);
	std::cout << std::endl;
	if (index.length() == 1 && isdigit(index[0]))
	{
		int i = atoi(index.c_str());
		if (i <= this->_indexMax)
		{
			std::cout << "Fisrt Name : " << this->_instanceContact[i].getFirstName() << std::endl;
			std::cout << "Last Name : " << this->_instanceContact[i].getLastName() << std::endl;
			std::cout << "Nickname : " << this->_instanceContact[i].getNickname() << std::endl;
			std::cout << "Phone number : " << this->_instanceContact[i].getPhoneNumber() << std::endl;
			std::cout << "Darkest Secret :" << this->_instanceContact[i].getDarkestSecret() << std::endl;
		}
	}
}

void	PhoneBook::close( void ){
	std::cout << "You want EXIT" << std::endl;
	std::cout << "Good bye" << std::endl;
}

