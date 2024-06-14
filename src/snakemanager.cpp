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

	display.Init_Wall();
	display.Print_Wall();
	display.Print_Snake(snake);
	snake.SetStarPos();
	snake.SetPoisonPos();
	snake.SetPortalPos();

	display.Print_Food(snake.GetStarPos());
	display.Print_Poison(snake.GetPoisonPos());
	display.Print_Score(snake);
	display.Print_Portal(snake.GetPortalPos());
}

void SnakeManager::Game()
{
	Util util;
	int key;
	int delay = 100000;

	while (true)
	{
		if (util.kbhit()) // 만약 키보드 눌렸다면
		{
			key = getch(); // 그 키 값이 무엇인지

			if (DOWN_KEY_CODE <= key && key <= RIGHT_KEY_CODE) // 방향키라면
				snake.Set_Direction(key);
			else if (key == PAUSE_KEY_CODE) // 일시 정지라면, 근데 안만듦
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

		snake.Move(); // 현재 방향으로 이동 중인 스네이크 리스트 head 원소 변경
		display.Print_Snake(snake); // 스네이크 리스트에 있는 좌표들에 출력
		display.Print_Portal(snake.GetPortalPos()); // 만약 포탈 들어가면 지워지니까 계속 그림

		/*
			포탈은 immune wall 제외하고 랜덤으로
			생성해야되는데 맵마다 따로 그리는 게 귀찮아서 그냥 왼쪽, 위 벽만 그림
		*/
		if(snake.head() == snake.GetPortalPos()[0]) // 위에 있는 포탈 들어갔을 때
		{
			Point nextPortal = snake.GetPortalPos()[1];
			*snake.GetBody().begin() = nextPortal;
			snake.Set_Direction(RIGHT_KEY_CODE);
		}
		else if(snake.head() == snake.GetPortalPos()[1]) // 왼쪽에 있는 포탈 들어갔을 때
		{
			Point nextPortal = snake.GetPortalPos()[0];
			*snake.GetBody().begin() = nextPortal;
			snake.Set_Direction(DOWN_KEY_CODE);
		}

		Point before = snake.EraseTail();
		if (!snake.Is_Portal() && snake.Is_Collistion() == true || snake.Is_Bitten() == true) // 포탈이 아닌 벽이나 내 몸통에 충돌
		{
			int key;
			display.Print_GameOver();

			// std::cout << snake.head() << std::endl;

			key = getch();

			while (key != RESUME && key != EXIT)
			{
				display.Print_GameOver();
				key = getch();
			}

			switch (key)
			{
			case RESUME: // 이거 안만듦
				Resume();
				break;
			case EXIT: // 이것도 안만듦
				display.Print_Ranking();
				snake.SaveScore();
				break;
			}
		}

		
		if (snake.head() == snake.GetStarPos()) // 아이템 먹었을 때
		{
			snake.GetScore() += snake.GetLevel() * 10; // 점수 계산인데 일단 대충 만들었음. 먹은 아이템 * 10

			if (snake.GetScore() % 10 == 0)
			{
				// delay = 100 - snake.GetLevel() * 10;
				// snake.GetLevel()++;
			}

			GetStar(before);
			display.Print_Score(snake);
		}

		else if(snake.head() == snake.GetPoisonPos()) // 독 아이템 먹었을 때
			GetPoison(before);

		display.Print_Portal(snake.GetPortalPos());
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

void SnakeManager::GetPortal(Point before)
{
	// *snake.GetBody().begin() = before;
}