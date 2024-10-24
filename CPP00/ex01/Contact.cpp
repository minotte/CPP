#include "Contact.hpp"

Contact::Contact( void ){
	// std::cout << "Contact constructor called" << std::endl;
	return;
}

Contact::~Contact( void ){
	// std::cout << "contact destructor called" << std::endl;
	return;
}

/* -----------  SETTER --------------*/

void	Contact::setFirstName( std::string const name ){
	this->_firstName = name;
}

void	Contact::setLastName( std::string const lname ){
	this->_lastName = lname;
}

void	Contact::setNickname( const std::string nname ){
	this->_nickname = nname;
}

void	Contact::setPhoneNumber( std::string const phnumber ){
	this->_phoneNumber = phnumber;
}

void	Contact::setDarkestSecret( std::string const secret ){
	this->_darkestSecret = secret;
}

/* -----------  GETTER --------------*/

std::string	Contact::getFirstName( void ) const
{
	return (this->_firstName);
}

std::string	Contact::getLastName( void ) const
{
	return (this->_lastName);
}

std::string	Contact::getNickname( void ) const
{
	return (this->_nickname);
}
std::string	Contact::getPhoneNumber( void ) const
{
	return (this->_phoneNumber);
}
std::string	Contact::getDarkestSecret( void ) const
{
	return (this->_darkestSecret);
}


/* ---------------------------------------------------- */

std::string	Contact::tenChar( std::string str  )
{
	int len;

	len = str.length();
	if (len > 10)
	{
		str = str.substr(0, 10);
		str[9] = '.';		
	}
	else
		str.replace(0, 0, 10 - len,' ');
	return (str);
}
