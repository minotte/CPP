#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iostream>

#define NC		" \033[0m"
#define RED		"\033[38;5;1m"

class Span{
	private:
		int	_size;
		std::vector<int> _tab ;
	public:
		Span();
		Span(unsigned int N);
		Span( Span const &src );
		Span &operator=(Span const &src);
		~Span();
		int		getTab(int i) const;
		void	setTab(int i, int nb);
		void	addNumber(int i);
		void	addRangeNumber(int size, int nb);
		int		shortestSpan();
		int		longestSpan();
};


#endif
