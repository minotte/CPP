#include "Base.hpp"

int	main(){
	srand((unsigned)time(NULL));
	std::cout << "\033[0;36mbase : ";
	Base *base = Base::generate();
	std::cout << "\033[0m----------------------------" << std::endl;
	std::cout << "\033[4;32mbasBis : ";
	Base *basBis  = Base::generate();
	std::cout << "\033[0m----------------------------" << std::endl;
	std::cout << "bas : ";
	Base *bas = Base::generate();
	std::cout << "\033[0m----------------------------" << std::endl;

	std::cout << "\033[0;36midentify(base) : ";
	Base::identify(base);
	std::cout << "\033[0m----------------------------" << std::endl;
	std::cout << "\033[0;36midentify(*base) : ";
	Base::identify(*base);
	std::cout << "\033[0m----------------------------" << std::endl;
	std::cout << "\033[4;32midentify(basBis) : ";
	Base::identify(basBis);
	std::cout << "\033[0m----------------------------" << std::endl;
	std::cout << "identify(NULL) : ";
	Base::identify(NULL);
	std::cout << "\033[0m----------------------------" << std::endl;
	std::cout << "\033[4;32midentify(*basBis) : ";
	Base::identify(*basBis);
	std::cout << "\033[0m----------------------------" << std::endl;
	std::cout << "identify(bas) : ";
	Base::identify(bas);
	std::cout << "\033[0m----------------------------" << std::endl;
	delete base;
	delete basBis;
	delete bas;
	return 0;
}
