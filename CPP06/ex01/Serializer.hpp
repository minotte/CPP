#ifndef Serializer_HPP
#define Serializer_HPP

#include <iostream>
#include <stdint.h>

struct Data
{
	int	forTheTest;	
};

class Serializer
{
	 public:
		~Serializer();
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);
	 private:
		Serializer();
		Serializer(Serializer const & src);
		Serializer &operator=(Serializer const & src);
};

#endif
