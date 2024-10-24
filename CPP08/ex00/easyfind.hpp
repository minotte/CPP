#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <exception>
#include <iostream>
#include <iterator>
#include <algorithm>

#define RED		"\033[38;5;1m"
#define NC		"\033[0m"

template< typename T >
typename T::const_iterator easyfind(T &container, int nb){
		return (std::find(container.begin(), container.end(), nb));
}

#endif
