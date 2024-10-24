#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point{
	public:
		Point();
		Point(float const x, float const y);
		Point(Point const &src);
		Point & operator=(Point const &src);
		~Point();
		void	setX(int const x);
		int		getX(void) const;
		void	setY(int const y);
		int		getY(void) const;
	private:
		int	_x;
		int	_y;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
