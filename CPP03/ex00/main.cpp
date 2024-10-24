#include "ClapTrap.hpp"

int	main(void){
	{
		ClapTrap	Clap;
	
		Clap.attack("");
		Clap.attack("The chicken");
		std::cout << std::endl;
		Clap.takeDamage(-3);
		Clap.takeDamage(1);
		Clap.beRepaired(5);
		Clap.takeDamage(10);
		Clap.attack("The chicken");
		Clap.attack("The chicken");
		Clap.takeDamage(10);
		Clap.attack("The chicken");
		Clap.beRepaired(5);
	}
	std::cout << std::endl << "----------------------------" << std::endl << std::endl;
	{
		ClapTrap	Clap("IT");
	
		Clap.attack("");
		Clap.attack("The child");
		std::cout << std::endl;
		Clap.takeDamage(3);
		Clap.beRepaired(5);
		Clap.takeDamage(1);
		Clap.beRepaired(5);
		Clap.takeDamage(10);
		Clap.beRepaired(5);
		Clap.attack("The child");
		Clap.attack("The child");
		Clap.takeDamage(10);
		Clap.beRepaired(5);
		Clap.attack("The child");
		Clap.beRepaired(5);
		Clap.attack("The child");
		Clap.attack("The child");
		Clap.takeDamage(10);
		Clap.takeDamage(10);
		Clap.attack("The child");
		Clap.attack("The child");
		Clap.takeDamage(10);
		Clap.attack("The child");
		Clap.takeDamage(10);
	}
	return 0;
}
