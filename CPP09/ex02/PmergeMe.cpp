/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nminotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:34:57 by nminotte          #+#    #+#             */
/*   Updated: 2024/03/22 09:29:08 by nminotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <algorithm>
#include <iterator>
#include <utility>
#include <vector>


void	sorting_vector(std::vector< int > &suite){
	if (suite.begin() + 1 >= suite.end())
		return ;
	std::vector< std::pair<int, int> > paire;
	int	i = 0;
	int odd;
	if (suite.size() % 2 == 1)
		odd = suite[suite.size() - 1] ;
	unsigned int it = 0;
	do{
		paire.push_back(std::make_pair(suite[it] , suite[it + 1]));
		if ( paire[i].first > paire[i].second ){
			std::swap(paire[i].first, paire[i].second);
		}
		i++;
		it = it + 2;
	}while( it + 1 < suite.size() );
	

	bubbleSort_vector(paire, paire.size());

	std::vector<int> biggest = bigSuite_vector( paire );
	
	i = 0;
	std::vector< std::pair<int, int> >::iterator start = paire.begin() + 1;
	std::vector< std::pair<int, int> >::iterator end = start;
	do{
		end = start + jacobsthal_vector(i);
		if (end > paire.end())
			end = paire.end();
		std::reverse( start, end );
		start = end;
		i++;
	} while (end + 1 < paire.end()); 

	std::vector<int>::iterator insert;
	if (suite.size() % 2 == 1)
		paire.push_back( std::make_pair(odd, (paire.end() - 1)->second ));

	for (std::vector< std::pair<int, int> >::iterator it = (paire.begin() + 1); it < paire.end(); it++){
		insert = binarySearch_vector(*it, biggest);
		if (insert > biggest.end())
			biggest.push_back(*insert);
		else
			biggest.insert( insert, it->first );
	}
	std::cout << "After: ";
	for_each(biggest.begin(), biggest.end(), print);
	std::cout << std::endl;

	return ;
}


void bubbleSort_vector(std::vector< std::pair<int, int> > &toSort, int n)
{
	if (n <= 1)
		return;

	for (int i = 0; i < n - 1; i++)
		if (toSort[i].second > toSort[i + 1].second)
			std::swap(toSort[i], toSort[i + 1]);

	bubbleSort_vector(toSort, n - 1);
}

std::vector<int>	bigSuite_vector(std::vector< std::pair<int, int> > toSort){
	std::vector<int> big;
	unsigned int i = 0;

	big.push_back(toSort[i].first);
	for (i = 0; i < toSort.size(); i++)
		big.push_back(toSort[i].second);
	return big;
}

int jacobsthal_vector(int n){
	if (n == 0)
		return 2;
	else if (n == 1)
		return 2;
	else
		return (jacobsthal_vector(n - 1) + 2 * jacobsthal_vector(n - 2));
}

std::vector<int>::iterator binarySearch_vector(std::pair<int, int> element, std::vector<int> &big){
	std::vector<int>::iterator it = std::find(big.begin(), big.end(), element.second);
	std::vector<int>::iterator start = big.begin();
	int m = std::distance( start, it ) / 2;

	if (element.first < *start)
		return start;
	else if ( element.first >= *(big.end() - 1) )
		return big.end();
	
	while ( m > 0 ){
		if ( element.first == *( start + m ) )
			break;
		else if ( element.first < *(start + m) ){
			if ( element.first > *(start + m - 1) )
				return (start + m);
			it = start + m;
			m = std::distance( start, it ) / 2;
		}
		else{
			if ( element.first < *(start + m + 1) )
				return (start + m + 1);
			start = start + m;
			m = std::distance( start, it ) / 2; 
		}
	}
	return (start + m + 1);
}

/* DEQUE   */


void	sorting_deque(std::deque< int > &suite){
	if (suite.begin() + 1 >= suite.end())
		return ;
	std::deque< std::pair<int, int> > paire;
	int	i = 0;
	int odd;
	
	if (suite.size() % 2 == 1)
		odd = suite[suite.size() - 1] ;

	unsigned int it = 0;
	do{
		paire.push_back(std::make_pair(suite[it] , suite[it + 1]));
		if ( paire[i].first > paire[i].second ){
			std::swap(paire[i].first, paire[i].second);
		}
		i++;
		it = it + 2;
	}while( it + 1 < suite.size() );

	bubbleSort_deque(paire, paire.size());

	std::deque<int> biggest = bigSuite_deque( paire );
	
	i = 0;
	std::deque< std::pair<int, int> >::iterator start = paire.begin() + 1;
	std::deque< std::pair<int, int> >::iterator end = start;
	do{
		end = start + jacobsthal_deque(i);
		if (end > paire.end())
			end = paire.end();
		std::reverse( start, end );
		start = end;
		i++;
	} while (end + 1 < paire.end()); 

	std::deque<int>::iterator insert;
	if (suite.size() % 2 == 1)
		paire.push_back( std::make_pair(odd, (paire.end() - 1)->second ));

	for (std::deque< std::pair<int, int> >::iterator it = (paire.begin() + 1); it < paire.end(); it++){
		insert = binarySearch_deque(*it, biggest);
		if (insert > biggest.end())
			biggest.push_back(*insert);
		else
			biggest.insert( insert, it->first );
	}

	return ;
}

void bubbleSort_deque(std::deque< std::pair<int, int> > &toSort, int n)
{
	if (n <= 1)
		return;

	for (int i = 0; i < n - 1; i++)
		if (toSort[i].second > toSort[i + 1].second)
			std::swap(toSort[i], toSort[i + 1]);

	bubbleSort_deque(toSort, n - 1);
}

std::deque<int>	bigSuite_deque(std::deque< std::pair<int, int> > toSort){
	std::deque<int> big;
	unsigned int i = 0;

	big.push_back(toSort[i].first);
	for (i = 0; i < toSort.size(); i++)
		big.push_back(toSort[i].second);
	return big;
}

int jacobsthal_deque(int n){
	if (n == 0 || n == 1)
		return 2;
	else
		return (jacobsthal_deque(n - 1) + 2 * jacobsthal_deque(n - 2));
}

std::deque<int>::iterator binarySearch_deque(std::pair<int, int> element, std::deque<int> &big){
	std::deque<int>::iterator it = std::find(big.begin(), big.end(), element.second);
	std::deque<int>::iterator start = big.begin();
	int m = std::distance( start, it ) / 2;

	if (element.first < *start)
		return start;
	
	else if ( element.first > *(big.end() - 1) )
		return big.end();
	
	while ( m > 0 ){
		if ( element.first == *( start + m ) )
			break;
		else if ( element.first < *(start + m) ){
			if ( element.first > *(start + m - 1) )
				return (start + m);
			it = start + m;
			m = std::distance( start, it ) / 2;
		}
		else{
			if ( element.first < *(start + m + 1) )
				return (start + m + 1);
			start = start + m;
			m = std::distance( start, it ) / 2; 
		}
	}
	return (start + m );
}
