#include "Point.hpp"

static Fixed crossProduct(Point const a, Point const b, Point const p)
{
	return (b.getX() - a.getX()) * (p.getY() - a.getY())
		- (b.getY() - a.getY()) * (p.getX() - a.getX());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed d1 = crossProduct(a, b, point);
	Fixed d2 = crossProduct(b, c, point);
	Fixed d3 = crossProduct(c, a, point);

	Fixed zero(0);

	if (d1 == zero || d2 == zero || d3 == zero)
		return false;

	bool hasNeg = (d1 < zero) || (d2 < zero) || (d3 < zero);
	bool hasPos = (d1 > zero) || (d2 > zero) || (d3 > zero);

	return !(hasNeg && hasPos);
}
