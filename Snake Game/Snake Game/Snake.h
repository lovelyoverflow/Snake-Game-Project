#ifndef __SNAKE_H_
#define __SNAKE_H_

#include <list>
#include "Point.h"

#define START_SNAKE_POS_X	20
#define START_SNAKE_POS_Y	5

class Snake
{
private:
	std::list<Point> body;
	Point starPos;
	int direction;
private:
	void Move_UP();
	void Move_Down();
	void Move_Left();
	void Move_Right();
public:
	Snake();

	void Init();
	void Set_Direction(int key);
	void Move();
	bool Is_Bitten();
	bool Is_Collistion();
	int GetDirection();
	void SetStarPos();
	Point GetStarPos();
	std::list<Point>* GetBody();

	Point head();
	Point tail();
};

#endif