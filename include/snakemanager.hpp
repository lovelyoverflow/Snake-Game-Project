#ifndef __SNAKE_MANAGER_H_
#define __SNAKE_MANAGER_H_

#include "util.hpp"

class SnakeManager
{
private:
	Snake snake;
	Display display;
	Util util;
private:
	void Print_Tail(Point nextTail);
public:
	SnakeManager();
	void Init();
	void Game();
	void Resume();
	void GetStar(Point before);
};

#endif