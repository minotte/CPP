#include "Harl.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2){
		std::cerr << "wrong argument" << std::endl;
		return (1);
	}
	Harl msg;
	msg.complain(argv[1]);
	return (0);
}
