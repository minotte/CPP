#include "Sed.hpp"

int	main(int argc, char **argv){

	if (argc != 4){
		std::cerr << "pls, try again. And put after the program name  \"filename\" \"what change\" \"to an other thing\"" << std::endl;
		return (1);
	}
	Sed	changeTxt(argv[1], argv[2], argv[3]);
	changeTxt.ftSed();
	return (0);
}
