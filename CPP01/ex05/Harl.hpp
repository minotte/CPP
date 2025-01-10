#ifndef HARL_H
# define HARL_H

#include <iostream>
#include <string>
#include <map>

class Harl{
	
	public:
		Harl( void );
		~Harl( void );
		void complain( std::string level );


	private:
		std::string _level[4];
		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void other( void );
};

#endif
