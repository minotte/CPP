#include "Character.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main()
{
	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Cure());
		ICharacter* me = new Character("me");
		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		delete tmp;
		tmp = src->createMateria("cure");
		me->equip(tmp);
		ICharacter* bob = new Character("bob");
		delete tmp;
		tmp = src->createMateria("cure");
		bob->equip(tmp);
		bob->use(0, *me);
		Character	matt = *(Character*)bob;
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->unequip(1);
		delete tmp;
		tmp = src->createMateria("ice");
		matt.equip(tmp);
		delete tmp;
		tmp = src->createMateria("ice");
		matt.equip(tmp);
		delete tmp;
		tmp = src->createMateria("ice");
		matt.equip(tmp);
		delete tmp;
		tmp = src->createMateria("ice");
		matt.equip(tmp);
		bob->equip(tmp);
		delete tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		me->use(2, *bob);
		matt.use(4, *bob);
		matt.use(3, *bob);
		delete bob;
		delete me;
		delete src;
		delete tmp;
	}
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter *you = new Character("You");

		AMateria *tmp;
		AMateria *tmp1;
		AMateria *tmp2;
		AMateria *tmp3;

		tmp = src->createMateria("ice");
		you->equip(tmp);
		tmp1 = src->createMateria("cure");
		you->equip(tmp1);
		delete tmp;
		tmp = src->createMateria("fire");
		you->equip(tmp);

		Character *georges = new Character();
		tmp2 = src->createMateria("cure");
		georges->equip(tmp2);
		tmp3 = src->createMateria("ice");
		georges->equip(tmp3);
		delete tmp;
		tmp = src->createMateria("earth");
		georges->equip(tmp);

		Character *georges_copy = new Character(*georges);

		ICharacter *bob = new Character("bob");
		you->use(0, *bob);
		you->use(1, *bob);

		you->use(-9, *bob);
		you->use(5, *bob);
		you->unequip(-1);
		you->unequip(96);
		you->unequip(2);
		you->use(1, *georges);
		you->unequip(1);
		you->use(1, *georges);

		georges->use(0, *bob);
		georges->use(1, *bob);
		georges->use(2, *bob);
		georges->use(3, *bob);
		georges->unequip(3);
		tmp = src->createMateria("cure");
		georges_copy->equip(tmp);
		delete tmp;
		tmp = src->createMateria("ice");
		georges_copy->equip(tmp);
		delete tmp;
		tmp = src->createMateria("cure");
		georges_copy->equip(tmp);
		georges_copy->use(0, *bob);
		georges_copy->use(1, *bob);
		georges_copy->use(2, *bob);
		georges_copy->use(3, *bob);
		std::cout << std::endl;

		delete tmp2;
		delete tmp3;
		delete tmp1;
		delete tmp;
		delete bob;
		delete you;
		delete src;
		delete georges;
		delete georges_copy;
	}
	return 0;
}
