#include "ScalarConverter.hpp"
#include <string>

int	main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "The program needs just one argument!" << std::endl;
		return 1;
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
