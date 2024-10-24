#include "Point.hpp"
#include "Fixed.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point){
	int v1 = (c.getX() - point.getX())*(a.getY() - point.getY()) - (c.getY() -point.getY())*(a.getX() - point.getX());
	int v2 = (a.getX() - point.getX())*(b.getY() - point.getY()) - (a.getY() -point.getY())*(b.getX() - point.getX()) ;
	int v3 =(b.getX() - point.getX())*(c.getY() - point.getY()) - (b.getY() -point.getY())*(c.getX() - point.getX()) ;
	if ((v1 < 0 && v2 < 0 && v3 < 0) || (v1 > 0 && v2 > 0 && v3 > 0))
		return true;
	else
		return false;
}
