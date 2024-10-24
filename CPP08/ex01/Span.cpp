#include "Span.hpp"

Span::Span() : _size(0){	
	this->_tab = std::vector<int>(0);
}

Span::Span(unsigned int N) : _size(N){
	this->_tab = std::vector<int>(0);
}

Span::Span( Span const &src ){
	*this = src;
}

Span &Span::operator=(Span const &src){
	if (this != &src){
		this->_size = src._size;
		this->_tab = src._tab;
	}
	return *this;
}

Span::~Span(){

}

int	Span::getTab(int i) const{
	return ( this->_tab[i] );
}

void	Span::addNumber(int i){
	if (this->_tab.size() >= (unsigned)this->_size)
		throw std::out_of_range("Error : out of range!");
	this->_tab.push_back(i);
}

// static void	print(const int& n){
	// std::cout << n << " ";
// }

int	Span::shortestSpan(){
	if (this->_tab.begin() + 1 == this->_tab.end())	
		throw	std::out_of_range("Need more number!" );
	std::sort (this->_tab.begin(), this->_tab.end());
	// std::for_each(this->_tab.begin(), this->_tab.end(), *print);
	int	dif = *(this->_tab.begin() + 1)  - *this->_tab.begin();
	for(std::vector<int>::iterator it =this->_tab.begin(); it < this->_tab.end(); it++)
	{
		if (it + 1 < this->_tab.end() && (*(it + 1) - *it < dif)){
			dif = *(it + 1) - *it;
		}
	}
	return dif;
}

int		Span::longestSpan(){
	if (this->_tab.begin() + 1 == this->_tab.end())	
		throw	std::out_of_range("Need more number!" );
	std::sort (this->_tab.begin(), this->_tab.end());
	// std::for_each(this->_tab.begin(), this->_tab.end(), *print);
	return (*(this->_tab.end() - 1) - *this->_tab.begin());
}

void	Span::addRangeNumber(int size, int nb){
	if (size < 1)
		throw std::out_of_range("ERROR : the first argument need to be up than 0");
	else if ( this->_tab.size() + (unsigned)size >= (unsigned)this->_size )
		throw std::out_of_range("ERROR : the size of the tab is too small for the number you want insert!");
	this->_tab.insert( this->_tab.end(), size, nb );
}
