#include "Serializer.hpp"
#include <ios>

int	main()
{
	Data	data;

	data.forTheTest = 42;
	std::cout << "data value : " << data.forTheTest << " and the adress : " << &data << std::endl;
	uintptr_t	ptr = Serializer::serialize(&data);
	std::cout << "ptr value : " << std::hex << ptr  << std::dec  << std::endl;
	Data* d = Serializer::deserialize(ptr);
	std::cout << "d value : " << d->forTheTest << " and the adress : " << d << std::endl;
	d->forTheTest = 95;
	std::cout << "data value : " << data.forTheTest << " and the adress : " << &data << std::endl;
}
