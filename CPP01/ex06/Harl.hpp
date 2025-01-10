#ifndef HARL_H
# define HARL_H

#include <iostream>
#include <string>


class	Harl{
	public:
		Harl(void);
		~Harl(void);
		void switchCase(std::string instruction);
	private:
};

 enum info {
	 DEBUG,
	 INFO,
	 WARNING,
	 ERROR,
 };

#endif
