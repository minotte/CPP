/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:34:40 by nminotte          #+#    #+#             */
/*   Updated: 2024/03/21 16:45:27 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PmergeMe.hpp"
#include <cstdlib>
#include <string>
#include <vector>
#include <deque>
#include <time.h>

void	print( int value ){
	std::cout << " " << value;
}

int	parsing(int argc, char **argv){
	std::string	arg;
	std::vector<int>	vect;
	std::deque<int>		deq;

	for (int i = 1; i < argc; i++){
		arg = argv[i];
		for (size_t j = 0; j < arg.size(); j++ ){
			if (!std::isdigit(arg[j])){
				std::cout << "Error: you need write just digit." << std::endl;
				return 1;
			}
		}
		int	nb = std::atoi(argv[i]);
		if (nb < 0 || nb > 2147483647){
			std::cout << "Error: int max" << std::endl;
			return 1;
		}
		vect.push_back(nb);
		deq.push_back(nb);
	}
	std::cout << "Before:";
	for_each(vect.begin(), vect.end(), print);
	
	// time

	std::cout << std::endl;
	clock_t c_start = clock();	
	
	sorting_vector(vect);
	
	clock_t c_stop = clock();
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << ((float)c_stop - c_start)/(CLOCKS_PER_SEC) << " s" << std::endl;
	c_start = clock();
	
	// deque
	sorting_deque(deq);
	
	c_stop = clock();
	std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque  : " <<  ((float)c_stop - c_start)/(CLOCKS_PER_SEC)  << " s" << std::endl;
	return 0;
}

int	main(int argc, char **argv){
	
	if (argc == 1){
		std::cout << "Error: you need write at least one argument." << std::endl;
		return 1;
	}
	int ret = 0;
	ret = parsing(argc, argv);
	return ret;
}
