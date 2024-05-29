#include "Point.h"

Point::Point(int X, int Y)
	:x(X), y(Y)
{}

Point::Point()
	: x(0), y(0)
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