#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name )
{
	if (N <= 0 )
		return NULL;
	Zombie* zombies = new Zombie[N];
	for(int i = 0; i < N; i++){
		zombies[i].setName(name);
		std::cout << name << ": ";
		zombies[i].announce();
	}
	return zombies;
}
