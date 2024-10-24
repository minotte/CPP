#include "Brain.hpp"

Brain::Brain(){
		// std::cout << "Brain constructor called" << std::endl;
		for (int i = 0; i < IDEAS; i++)
			this->_ideas[i] = "????????????????????????????????";
	return;
}

Brain::Brain(Brain const &src){
	*this = src;
	return;
}

Brain	& Brain::operator=(Brain const &src){
	for (int i = 0; i < IDEAS; i++)
		this->_ideas[i] = src._ideas[i];
	return *this;
}

Brain::~Brain(){
	// std::cout << "Brain destructor called" << std::endl;
	return;
}

void		Brain::setIdea(int i, std::string idea){
	this->_ideas[i] = idea;
}

std::string	Brain::getIdea(int i) const{
	return _ideas[i];
}

