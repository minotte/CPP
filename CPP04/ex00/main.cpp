#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	std::cout << std::endl;
	

	const WrongAnimal* W = new WrongCat();
	const WrongAnimal* WC = new WrongAnimal();
	std::cout << W->getType() << " " << std::endl;
	std::cout << WC->getType() << " " << std::endl;
	W->makeSound();
	WC->makeSound();

	delete meta;
	delete j;
	delete i;
	delete W;
	delete WC;
	return 0;
}
