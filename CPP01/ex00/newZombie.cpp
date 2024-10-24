#include "Zombie.hpp"

Zombie* newZombie (std::string name){
	Zombie*	Arg = new Zombie(name);
	return (Arg);
}
