#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template< typename T >
class Array{
	public:

		Array() : _array(0) , _element(0){};

		Array( unsigned int n ) : _element(n){
			this->_array = new T[n];
		};

		Array(const Array &copy) : _array(0) , _element(0){ *this = copy; };

		Array &operator=(const Array &copy) { 
			if (this->_array && this->size() != copy.size()){
				delete [] _array;
			}
			this->_array = new T[copy.size()];
			this->_element = copy.size();
			return *this;
		};

		~Array(){ delete [] _array; };

		/*        operator*/
		T	&operator[](unsigned int i){
			if ( i < 0 || i >= this->_element )
				throw outRange();
			return this->_array[i];
		};

		/* getter */

		unsigned int size( void ) const{
			return _element;
		};

		/*  class Exception */

		class outRange : public std::exception{
			public:
				virtual const char* what(void) const throw(){ return ("wrong index, it's out of range."); };
		}; 

	private:
		T*	_array;
		unsigned int _element;
};

#endif
