/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:34:17 by nminotte          #+#    #+#             */
/*   Updated: 2024/03/21 17:06:00 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "RPN.hpp"

int	main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "Error: the inverted Polish mathematical expression as to be write in one argument." << std::endl;
		return 1;
	}
	try {
		RPN( argv[1] );
	}
	catch (const std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
