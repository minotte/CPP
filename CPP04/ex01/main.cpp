#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *animal[100];
	for(int i= 0; i < 100; i++){
		if (i % 2 == 0){
			animal[i] = new Dog();
			std::cout << ((Dog*)animal[i])->getBrain()->getIdea(i + 1) << std::endl;
		}
		else{
			const Cat* cat =  new Cat();
			animal[i] = cat;
			std::cout << cat->getBrain()->getIdea(i) << std::endl;
		}
		animal[i]->makeSound();
	}
	
	for(int i= 0; i < 100; i++){
		delete animal[i];
	}
	Dog dog = Dog();
	{
		Dog	tmp = dog;
		std::cout << tmp.getBrain() << std::endl; 
	}
	std::cout << dog.getBrain() << std::endl;
	
	return 0;
}
