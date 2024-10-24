#include "iter.hpp"
#include <iostream>
#include <string>

template < typename T >
void	print(T str){
	std::cout << str << std::endl;
}

int main(){
	std::string test[] = {"Ceci est un test !!", " bonjour ", "Salut"};
	int const i[6] ={8,9,8,1,2,0};

	::iter(i, 6, print< const int>);
	::iter(test, 3, print<std::string>); 
	return 0;
}
