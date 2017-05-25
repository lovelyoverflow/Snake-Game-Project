#include "Common.h"
#include "Display.h"
#include "Snake.h"
#include "Constant.h"
#include "SnakeManager.h"
#include <conio.h>

SnakeManager::SnakeManager()
{
	snake.Init();
};

void SnakeManager::Init()
{
	snake.Init();
	util.CursorUtil_Hide();

	display.Print_Wall();
	display.Print_Snake(snake);
	snake.SetStarPos();
	display.Print_Food(snake.GetStarPos());
}

void SnakeManager::Game()
{
	int key;

	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			
			if (key == 224)
				key = _getch();

			snake.Set_Direction(key);
		}

		snake.Move();
		display.Print_Snake(snake);

		if (snake.head() == snake.GetStarPos())
			GetStar();

		Sleep(100);
	}
}

void SnakeManager::Print_Tail(Point nextTail)
{
	Point curPos = util.CursorUtil_Get();

	snake.GetBody()->push_back(nextTail);

	util.CursorUtil_Set(nextTail.x, nextTail.y);
	std::cout << "¡Ý";

	util.CursorUtil_Set(curPos.x, curPos.y);
}

void SnakeManager::GetStar()
{
	Point tailPos = snake.tail();

	switch (snake.GetDirection())
	{
	case KeyCode::LEFT_KEY_CODE:
		Print_Tail(Point(tailPos.x + 2, tailPos.y));
		break;
	case KeyCode::RIGHT_KEY_CODE:
		Print_Tail(Point(tailPos.x - 2, tailPos.y));
		break;
	case KeyCode::UP_KEY_CODE:
		Print_Tail(Point(tailPos.x, tailPos.y + 1));
		break;
	case KeyCode::DOWN_KEY_CODE:
		Print_Tail(Point(tailPos.x, tailPos.y - 1));
		break;
	}

	snake.SetStarPos();
	display.Print_Food(snake.GetStarPos());
}