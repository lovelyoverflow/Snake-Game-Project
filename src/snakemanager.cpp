#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include "display.hpp"
#include "snake.hpp"
#include "constant.hpp"
#include "snakemanager.hpp"
#include "util.hpp"

SnakeManager::SnakeManager()
{
	snake.Init();
};

void SnakeManager::Init()
{
	snake.Init();
	util.CursorUtil_Hide();

	// system("title Snake");
	// system("mode con cols=150 lines=40");
	// system("cls");

	display.Print_Title();
	getch();
	erase();
	refresh();

	display.Print_Wall();
	display.Print_Snake(snake);
	snake.SetStarPos();
	snake.SetPoisonPos();

	display.Print_Food(snake.GetStarPos());
	display.Print_Poison(snake.GetPoisonPos());
	display.Print_Score(snake);
}

void SnakeManager::Game()
{
	Util util;
	int key;
	int delay = 100000;

	while (true)
	{
		// std::cout << " ASD " << std::endl;
		if (util.kbhit())
		{
			// std::cout << key << std::endl;
			key = getch();
			// std::cout << key << std::endl;

			if (DOWN_KEY_CODE <= key && key <= RIGHT_KEY_CODE)
				snake.Set_Direction(key);
			else if (key == PAUSE_KEY_CODE)
			{
				while (!util.kbhit())
				{
					display.Print_Pause();
					usleep(400000);
					display.Erase_Pause();
					usleep(300000);
				}

				continue;
			}
			else
				continue;
		}

		Point before = snake.EraseTail();

		if (snake.Is_Collistion() == true || snake.Is_Bitten() == true)
		{
			int key;
			// system("cls");

			display.Print_GameOver();

			key = getch();

			while (key != RESUME && key != EXIT)
			{
				display.Print_GameOver();
				key = getch();
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
		// std::cout << " ASD " << std::endl;

		if (snake.head() == snake.GetStarPos())
		{
			snake.GetScore() += snake.GetLevel() * 10;

			if (snake.GetScore() % 100 == 0 && delay > 10)
			{
				// delay = 100 - snake.GetLevel() * 10;
				// snake.GetLevel()++;
				
			}

			GetStar(before);
			display.Print_Score(snake);
		}

		else if(snake.head() == snake.GetPoisonPos())
			GetPoison(before);

		refresh();
		usleep(delay);
	}
}

void SnakeManager::Resume()
{

}

void SnakeManager::Print_Tail(Point nextTail)
{
	Point curPos = util.CursorUtil_Get();

	snake.GetBody().push_back(nextTail);

	// util.CursorUtil_Set(nextTail.x, nextTail.y);
	// std::cout << "��";
	util.SetColorText(SNAKE);
	util.CursorUtil_Print(nextTail.x, nextTail.y, "  ");

	util.CursorUtil_Set(curPos.x, curPos.y);
}

void SnakeManager::GetStar(Point before)
{
	Print_Tail(before);

	snake.SetStarPos();
	display.Print_Food(snake.GetStarPos());
}

void SnakeManager::GetPoison(Point before)
{
	snake.EraseTail();

	snake.SetPoisonPos();
	display.Print_Poison(snake.GetPoisonPos());
}