#ifndef ITER_HPP
#define ITER_HPP

template< typename T, typename R >
void	iter(T* array, unsigned int length, R & funct){

	for (unsigned int i = 0; i < length; i++)
		funct(array[i]);
}

#endif
