#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main(void){
	{
		ClapTrap	Clap;
		ScavTrap	Scav("yoyoyoyooyoyyoyoyo");
		ScavTrap	S = Scav;
	
		Scav.attack("Clap");
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
		Scav.takeDamage(10);
		Clap.beRepaired(5);
		Scav.guardGate();
		Scav.attack("Clap");
	}

	return 0;
}
