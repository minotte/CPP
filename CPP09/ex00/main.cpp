/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 14:47:55 by nminotte          #+#    #+#             */
/*   Updated: 2024/03/21 10:13:35 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "BitcoinExchange.hpp"
#include <regex.h>
#include <exception>
#include <iostream>

int	doRegex(char const *str, char const *expression){
	regex_t	regex;
	if( regcomp(&regex, expression, REG_EXTENDED)){
		regfree(&regex);
		return (1);
	}
	if (!regexec(&regex, str, 0, NULL, 0)){
		regfree(&regex);
		return 0;
	} 
	regfree(&regex);
	return 1;
}

int	main(int argc, char **argv){
	if (argc != 2){
		std::cerr << "you need write an input file" << std::endl;
		return 1;
	}
	BitcoinExchange bitcoinval(argv[1]);

	return 0;
}
