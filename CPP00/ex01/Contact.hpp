#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <string>
#include <iostream>
class Contact
{
	 public:
		Contact( void );
		~Contact( void );
		void	setFirstName( std::string const name );
		void	setLastName( std::string const lname );
		void	setNickname( const std::string nname );
		void	setPhoneNumber( std::string const phnumber );
		void	setDarkestSecret( std::string const secret );
		std::string	getFirstName( void ) const;
		std::string	getLastName( void ) const;
		std::string	getNickname( void ) const;
		std::string	getPhoneNumber( void ) const;
		std::string	getDarkestSecret( void ) const;
		std::string	tenChar( std::string const str );

	 private:
		std::string	_firstName;
		std::string	_lastName;
		std::string	_nickname;
		std::string	_phoneNumber;
		std::string	_darkestSecret;
};

#endif
