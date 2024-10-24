#include "Zombie.hpp"

int	main()
{
	Zombie*	mickael = zombieHorde(5, "Zumzumbie");

	delete [] mickael;
	
	Zombie*	brainDead = zombieHorde(-1, "Zuumbie");
	delete [] brainDead;

	Zombie*	brian = zombieHorde(0, "Zombie");
	delete [] brian;

	brian = zombieHorde(1000000, "");
	delete [] brian;
	return (0);
}
