#include <iostream>
#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main( void )
{
	Point a(0.0f, 0.0f);
	Point b(4.0f, 0.0f);
	Point c(0.0f, 4.0f);

	Point inside(1.0f, 1.0f);
	Point outside(5.0f, 5.0f);
	Point onEdge(2.0f, 0.0f);
	Point atVertex(0.0f, 0.0f);

	std::cout << "Point (1,1) inside triangle: "
		<< (bsp(a, b, c, inside) ? "true" : "false") << std::endl;
	std::cout << "Point (5,5) outside triangle: "
		<< (bsp(a, b, c, outside) ? "true" : "false") << std::endl;
	std::cout << "Point (2,0) on edge: "
		<< (bsp(a, b, c, onEdge) ? "true" : "false") << std::endl;
	std::cout << "Point (0,0) at vertex: "
		<< (bsp(a, b, c, atVertex) ? "true" : "false") << std::endl;

	return 0;
}
