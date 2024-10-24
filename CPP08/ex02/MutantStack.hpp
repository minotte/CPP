#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T>{
	 public:
		MutantStack(): std::stack<T>(){};
		MutantStack(MutantStack const &src) { *this = src; };
		MutantStack operator=(MutantStack const &){
			return *this; };
		~MutantStack(){};
		typedef typename std::deque< T >::iterator iterator;
		typedef typename std::deque< T >::iterator itc;
		iterator begin(){
			return (this->c.begin());	
		};
		iterator end(){
			return (this->c.end());
		};
};

#endif
