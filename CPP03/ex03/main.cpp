#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"

int	main(void){
	{
		DiamondTrap dia("dia");
		ScavTrap	s("salut");
		DiamondTrap d;

		dia.attack("Clap");
		dia.attack("");
		dia.attack("The chicken");
		std::cout << std::endl;
		dia.beRepaired(5);
		dia.takeDamage(10);
		dia.attack("The chicken");
		dia.attack("The chicken");
		dia.takeDamage(10);
		dia.attack("The chicken");
		dia.takeDamage(10);
		dia.beRepaired(5);
		dia.guardGate();
		dia.attack("Clap");
		dia.whoAmI();
		std::cout << std::endl;

		d.attack("Clap");
		d.attack("");
		d.attack("The chicken");
		d.beRepaired(5);
		d.takeDamage(10);
		d.attack("The chicken");
		d.attack("The chicken");
		d.takeDamage(10);
		d.attack("The chicken");
		d.takeDamage(10);
		d.beRepaired(5);
		d.guardGate();
		d.attack("Clap");
		d.whoAmI();
	}

	return 0;
}
