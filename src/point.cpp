#include "point.hpp"

Point::Point(int X, int Y)
	:x(X), y(Y)
{}

bool Point::operator==(const Point& pos)
{
	if (x == pos.x && y == pos.y)
		return true;

	return false;
}

bool Point::operator!=(const Point& pos)
{
	return !(*this == pos);
}

void Point::operator=(const Point& pos)
{
	x = pos.x;
	y = pos.y;
}