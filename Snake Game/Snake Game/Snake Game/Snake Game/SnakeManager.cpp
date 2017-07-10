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
	display.Print_Score(snake);
}

void SnakeManager::Game()
{
	int key;
	int delay = 100;

	while (1)
	{
		if (_kbhit())
		{
			key = _getch();
			
			if (key == 224)
				key = _getch();
			else
				continue;

			snake.Set_Direction(key);
		}

		Point before = snake.EraseTail();
		snake.Move();
		display.Print_Snake(snake);

		if (snake.head() == snake.GetStarPos())
		{
			if (snake.GetBody()->size() % 10 == 0 && delay > 10)
				delay -= 10;

			GetStar(before);
			display.Print_Score(snake);
		}



		Sleep(delay);
	}
}

void SnakeManager::Print_Tail(Point nextTail)
{
	Point curPos = util.CursorUtil_Get();

	snake.GetBody()->push_back(nextTail);

	util.CursorUtil_Set(nextTail.x, nextTail.y);
	std::cout << "¢Ã";

	util.CursorUtil_Set(curPos.x, curPos.y);
}

void SnakeManager::GetStar(Point before)
{
	Print_Tail(before);

	snake.SetStarPos();
	display.Print_Food(snake.GetStarPos());
}