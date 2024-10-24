#include "Fixed.hpp"

int main( void ) {
	Fixed a;
	std::cout << "a : " << a << std::endl;
	Fixed const b( Fixed( 5.12f ) * Fixed( 5 ) );
	std::cout << "b : "<< b << std::endl;
	std::cout <<"++a : " <<  ++a << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout << "a++ : " << a++ << "---------------"  << std::endl;
	std::cout << "a : " << a << std::endl;
	std::cout <<"b : "<< b << std::endl;
	std::cout << "max : " << Fixed::max( a, b ) << std::endl;
	Fixed c(Fixed(40.40f) / Fixed(2.0f));
	std::cout << "/ result: "<< c << std::endl;
	std::cout <<  "max : " << Fixed::max( a, c ) << std::endl;
	std::cout <<  "min : " << Fixed::min( a, c ) << std::endl;
	std::cout << "--c : " << --c << std::endl;
	std::cout << "(c<a) " << (c<a) << std::endl;
	std::cout << "(b>a) " << (b>a) << std::endl;
	std::cout << "(c<=a)  " << (c<=a) << std::endl;
	std::cout << "(c>=a) " << (c>=a) << std::endl;
	std::cout << "(c==a) " << (c==a) << std::endl;
	std::cout << "(c!=a) " << (c!=a) << std::endl;
	std::cout << "a : " << a  << std::endl;
	Fixed e(2.6f);
	std::cout << "e : " << e << std::endl;
	std::cout << "b : " <<  b << std::endl;
	std::cout << "e + b : " << (e + b )<< std::endl;
	std::cout << "b - e : "<< b - e << std::endl;
	Fixed const d( Fixed( 105.12f ) / Fixed( 5 ) );
	std::cout << "d : "<<  d << std::endl;
	std::cout << "a - d : " <<  a - d << std::endl;

return 0;
}
