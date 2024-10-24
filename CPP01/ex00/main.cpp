#include "Zombie.hpp"

int	main()
{
	Zombie	George("georrrrrge");

	Zombie*	Arg = newZombie("Arrrrrg");
	Zombie*	Mickael = newZombie("houch");
	randomChump("Brian");
	Arg->announce();
	delete Arg;
	delete Mickael;
	return (0);
}
