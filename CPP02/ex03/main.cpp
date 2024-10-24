#include "Point.hpp"
#include "Fixed.hpp"

int	main(void){
	{
		Point	a;
		Point	b(15.8f, 93.5f);
		Point	c(38.0f, 299.1f);
		Point	point(5.2f, 9.9f);
		if (bsp(a, b, c, point))
			std::cout << "\033[0;36mthe point is in the triangle\033[0m" << std::endl;
		else
			std::cout << "\033[0;36mthe point is outside the triangle\033[0m" << std::endl;
	}
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	{
		Point	a(-1.0f, -13.9f);
		Point	b(1.8f, 93.5f);
		Point	c(38.0f, 299.1f);
		Point	point(0, 0);
		if (bsp(a, b, c, point))
			std::cout << "\033[0;36mthe point is in the triangle\033[0m" << std::endl;
		else
			std::cout << "\033[0;36mthe point is outside the triangle\033[0m" << std::endl;
	}
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	{
		Point	a(-7.1f, 2.46f);
		Point	b(2.16f, 5.66f);
		Point	c(2.86,-5.46);
		Point	point(-5.14f, -2.7f);
		if (bsp(a, b, c, point))
			std::cout << "\033[0;36mthe point is in the triangle\033[0m" << std::endl;
		else
			std::cout << "\033[0;36mthe point is outside the triangle\033[0m" << std::endl;
	}
	std::cout << "---------------------------------------------------------------------------" << std::endl;
	{
		Point	a(-7.1f, 2.46f);
		Point	b(2.16f, 5.66f);
		Point	c(2.86,-5.46);
		Point	point(-0.74f, 1.96f);
		if (bsp(a, b, c, point))
			std::cout << "\033[0;36mthe point is in the triangle\033[0m" << std::endl;
		else
			std::cout << "\033[0;36mthe point is outside the triangle\033[0m" << std::endl;
	}
std::cout << "---------------------------------------------------------------------------" << std::endl;
	{
		Point	a(-7.1f, 2.46f);
		Point	b(2.16f, 5.66f);
		Point	c(2.86,-5.46);
		Point	point(-5.57f, 1.24f);
		if (bsp(a, b, c, point))
			std::cout << "\033[0;36mthe point is in the triangle\033[0m" << std::endl;
		else
			std::cout << "\033[0;36mthe point is outside the triangle\033[0m" << std::endl;
	}
	return (0);
}
