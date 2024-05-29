#include "point.hpp"

Point::Point(int X, int Y)
	:x(X), y(Y)
{}

bool Point::operator==(Point pos)
{
	if (x == pos.x && y == pos.y)
		return true;

	return false;
}

void Point::operator=(Point& pos)
{
	x = pos.x;
	y = pos.y;
}