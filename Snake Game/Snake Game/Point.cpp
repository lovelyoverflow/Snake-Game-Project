#include "Point.h"

Point::Point(int X = 0, int Y = 0)
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