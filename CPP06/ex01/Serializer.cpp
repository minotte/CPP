#include "Serializer.hpp"

Serializer::Serializer(){
	std::cout << "Serializer Constructor called" <<std::endl;
	return;
}

Serializer::~Serializer(){
	std::cout << "Serializer Destructor called" <<std::endl;
	return;
}

Serializer::Serializer(const Serializer &copy){
	std::cout << "Serializer copy Constructor called" <<std::endl;
	*this = copy;
}

Serializer & Serializer::operator=(const Serializer &copy){
	(void)&copy ;
	return (*this);
}

uintptr_t Serializer::serialize(Data* ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw){
	return (reinterpret_cast<Data*>(raw));

}
