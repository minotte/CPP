/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/27 18:34:35 by nminotte          #+#    #+#             */
/*   Updated: 2024/03/21 17:05:38 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

const char* divide::what(void) const throw(){
	return ("you can't divide by 0");
}

std::stack<double>	caculation(std::stack<double> stackRPN, int flag){
	int tmp = stackRPN.top();
	stackRPN.pop();
	switch (flag) {
		case 0:
			stackRPN.top() += tmp;
			return stackRPN;
		case 1:
			stackRPN.top() -= tmp;
			return stackRPN;
		case 2:
			stackRPN.top() *= tmp;
			return stackRPN;
		case 3:
			if (tmp == 0){
				throw divide() ;
			}
			stackRPN.top() /= tmp;
			return stackRPN;
	}
	return stackRPN;
}

void	RPN(std::string arg){
	std::stack<double> stackRPN;

	for (int i = 0; arg[i]; i++){
		if (i % 2 == 0 && std::isdigit(arg[i])){
			stackRPN.push(arg[i] - 48);
		}
		else if (i % 2 == 0 && arg[i] == '+'){
			if (stackRPN.size() > 1){
				stackRPN = caculation(stackRPN, 0);
			}
			else{
				std::cerr << "Error: not enough number" << std::endl;
				return;
			}
		}
		else if (i % 2 == 0 && arg[i] == '-'){
			if (stackRPN.size() > 1){
				stackRPN = caculation(stackRPN, 1);
			}
			else{
				std::cerr << "Error: not enough number" << std::endl;
				return;
			}
		}

		else if (i % 2 == 0 && arg[i] == '*'){
			if (stackRPN.size() > 1){
				stackRPN = caculation(stackRPN, 2);
			}
			else{
				std::cerr << "Error: not enough number" << std::endl;
				return;
			}
		}

		else if (i % 2 == 0 && arg[i] == '/'){
			if (stackRPN.size() > 1){
				stackRPN = caculation(stackRPN, 3);
			}
			else{
				std::cerr << "Error: not enough number" << std::endl;
				return;
			}
		}

		else if (i % 2 == 1 && arg[i] == ' '){
		}
		else{
			std::cerr << "Error" << std::endl;
			return;
		}
	}
	if (stackRPN.size() != 1){
		std::cerr << "Error, there is still some number in the stack" << std::endl;
		return;
	}
	std::cout << stackRPN.top() << std::endl;
}
