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
	void Print_Tail(Point nextTail);		// ������ �׸��� �Լ�
public:
	SnakeManager();
	void Init();							// Ÿ��Ʋ, ���� �׸��� ������ũ ��� ������ �ʱ�ȭ
	void Game();							// ���� ����
	void Resume();
	void GetStar(Point before);				// ���� �Ծ��� �� ���� ����
};

#endif