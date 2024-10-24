#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const AAnimal *animal[100];
	for(int i= 0; i < 100; i++){
		if (i % 2 == 0){
			animal[i] = new Dog();
			for (int j = 0; j < 6; j++)
				std::cout << animal[i]->getType() << " : " << ((Dog*)animal[i])->getBrain()->getIdea(j) << std::endl;
		}
		else{
			const Cat* cat =  new Cat();
			animal[i] = cat;
			for (int j = 0; j < 10; j++)
				std::cout << cat->getType() << " : " << cat->getBrain()->getIdea(j) << std::endl;
		}
		std::cout << animal[i]->getType() << " : "  ;
		animal[i]->makeSound();
	}
		
	for(int i= 0; i < 100; i++){
		if (i % 2 == 0){
			delete ((Dog*)animal[i]);
		}
		else{
			delete ((Cat*)animal[i]);
		}
	}
	return 0;
}
