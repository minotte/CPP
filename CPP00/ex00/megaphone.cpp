#include <iostream>
#include <locale>

int	main(int argc, char **argv){
	int			i;
	int			j;
	std::locale	loc;

	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else{
		i = 1;
    	while ( i <= argc){
			j = 0;
			while (argv[i] && argv[i][j]){
				std::cout << std::toupper(argv[i][j], loc);
				j++;
			}
			i++;
			if ( i + 1 <= argc )
				std::cout << " ";
		}
	}
	std::cout << std::endl;
	return (0);
}


