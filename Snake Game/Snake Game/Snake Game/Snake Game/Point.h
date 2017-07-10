#ifndef __POINT_H_
#define __POINT_H_

class Point
{
public:
	int x;
	int y;
public:
	Point(int X, int Y);
	Point();

	bool operator==(Point pos);
	void operator=(Point& pos);
};

#endif