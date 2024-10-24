#include <string>
#include <iostream>

int	main()
{
	std::string sentence = "HI THIS IS BRAIN";
	std::string	*stringPTR = &sentence;
	std::string & stringREF = sentence;

/* print the address */ 
	std::cout << "The memory address of the string variable is : " << &sentence << std::endl;
	std::cout << "The memory address held by stringPTR is : " << stringPTR << std::endl;
	std::cout << "The memory address held by stringREF is : " << &stringREF << std::endl;
/*     print value */
	std::cout << "The value of the string variable is : " << sentence << std::endl;
	std::cout << "The value pointed to by stringPTR is : " << *stringPTR << std::endl;
	std::cout << "The value pointed to by stringREF is : " << stringREF << std::endl;


	return (0);
}
