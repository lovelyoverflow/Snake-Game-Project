#ifndef __SNAKE_MANAGER_H_
#define __SNAKE_MANAGER_H_

#include "snake.hpp"
#include "display.hpp"
#include "util.hpp"

class SnakeManager
{
private:
	Snake snake;
	Display display;
	Util util;
	std::chrono::time_point<std::chrono::high_resolution_clock> start;
	std::chrono::time_point<std::chrono::high_resolution_clock> item_time;
	bool item_flag;
private:
	void Print_Tail(Point nextTail);	// nextTail좌표에 꼬리 그리기
public:
	SnakeManager();						// 
	void Init();						// 
	void Game();						// 게임 메인 루프
	void Resume();						// 
	void GetStar(Point before);			// 아이템 먹었을 때
	void GetPoison(Point before);		// 독 아이템 먹었을 때
	void GetPortal(Point before);		// 포탈 들어갔을 때
};

#endif