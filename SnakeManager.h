#ifndef __SNAKE_MANAGER_H_
#define __SNAKE_MANAGER_H_

#include "Snake.h"
#include "Display.h"
#include "Point.h"
#include "Util.h"

class SnakeManager
{
private:
	Snake snake;
	Display display;
	Util util;
private:
	void Print_Tail(Point nextTail);		// 꼬리를 그리는 함수
public:
	SnakeManager();
	void Init();							// 타이틀, 맵을 그리고 스네이크 멤버 변수를 초기화
	void Game();							// 게임 루프
	void Resume();
	void GetStar(Point before);				// 별을 먹었을 때 길이 증가
};

#endif