/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:34:58 by nminotte          #+#    #+#             */
/*   Updated: 2024/03/21 16:51:28 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <deque>

int jacobsthal_vector(int n);
void	print( int value );
int	parsing(int argc, char **argv);
void bubbleSort_vector(std::vector< std::pair<int, int> > &toSort, int n);
std::vector<int>	bigSuite_vector(std::vector< std::pair<int, int> > toSort);
std::vector<int>::iterator binarySearch_vector(std::pair<int, int> element, std::vector<int> &big);
int jacobsthal_deque(int n);
void bubbleSort_deque(std::deque< std::pair<int, int> > &toSort, int n);
std::deque<int>	bigSuite_deque(std::deque< std::pair<int, int> > toSort);
std::deque<int>::iterator binarySearch_deque(std::pair<int, int> element, std::deque<int> &big);
void	sorting_vector(std::vector< int > &suite);
void	sorting_deque(std::deque< int > &suite);




#endif
