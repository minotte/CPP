#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void){
	{
		ClapTrap	Clap;
		ScavTrap	Scav("yoyoyoyooyoyyoyoyo");
		ScavTrap	S = Scav;
		FragTrap	Frag;
		FragTrap	F("go");
		FragTrap	Fr = F;
	
		F.attack("the trash");
		Scav.attack("Clap");
		Clap.attack("");
		Clap.attack("The chicken");
		std::cout << std::endl;
		Clap.takeDamage(3);
		F.takeDamage(12);
		F.beRepaired(5);
		F.takeDamage(12);
		F.highFivesGuys();
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
		Fr.beRepaired(10);
	}

	return 0;
}
