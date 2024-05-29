#include "Common.h"
#include "Display.h"
#include "Snake.h"
#include "Constant.h"
#include "SnakeManager.h"

SnakeManager::SnakeManager()
{
	snake.Init();
};

void SnakeManager::Init()
{	
	snake.Init();
	util.CursorUtil_Hide();

	system("title Snake");
	system("mode con cols=150 lines=40");
	system("cls");

	display.Print_Title();
	_getch();
	system("cls");

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
			else if (key == PAUSE_KEY_CODE)
			{
				while (!_kbhit())
				{
					display.Print_Pause();
					Sleep(400);
					display.Erase_Pause();
					Sleep(300);
				}

				continue;
			}
			else
				continue;

			snake.Set_Direction(key);
		}

		Point before = snake.EraseTail();


		if (snake.Is_Collistion() == true || snake.Is_Bitten() == true)
		{
			int key;
			system("cls");

			display.Print_GameOver();

			key = _getch();

			while (key != RESUME && key != EXIT)
			{
				display.Print_GameOver();
				key = _getch();
			}

			switch (key)
			{
			case RESUME:
				Resume();
				break;
			case EXIT:
				display.Print_Ranking();
				snake.SaveScore();
				break;
			}
		}

		snake.Move();
		display.Print_Snake(snake);

		if (snake.head() == snake.GetStarPos())
		{
			snake.GetScore() += snake.GetLevel() * 10;

			if (snake.GetScore() % 100 == 0 && delay > 10)
			{
				delay = 100 - snake.GetLevel() * 10;
				snake.GetLevel()++;
				
			}

			GetStar(before);
			display.Print_Score(snake);
		}

		Sleep(delay);
	}
}

void SnakeManager::Resume()
{
	system("cls");
	Init();

	while (1)
		Game();
}

void SnakeManager::Print_Tail(Point nextTail)
{
	Point curPos = util.CursorUtil_Get();

	snake.GetBody()->push_back(nextTail);

	util.CursorUtil_Set(nextTail.x, nextTail.y);
	std::cout << "��";

	util.CursorUtil_Set(curPos.x, curPos.y);
}

void SnakeManager::GetStar(Point before)
{
	Print_Tail(before);

	snake.SetStarPos();
	display.Print_Food(snake.GetStarPos());
}