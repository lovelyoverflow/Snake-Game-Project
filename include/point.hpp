#ifndef __POINT_H_
#define __POINT_H_

#include <ostream>

class Point
{
public:
	int x;
	int y;
public:
	Point(int X = 0, int Y = 0);

	bool operator==(Point pos);
	void operator=(Point& pos);

	friend std::ostream& operator << (std::ostream& os, const Point& point)
	{
		os << point.x << " " << point.y;
		return os;
	}
};

#endif