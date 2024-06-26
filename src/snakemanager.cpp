#include <iostream>
#include <unistd.h>
#include <ncurses.h>
#include <algorithm>
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
	snake.GetStageLevel() = 1;
	display.Load_Wall(snake.GetStageLevel());
	util.CursorUtil_Hide();
	start = std::chrono::high_resolution_clock::now();
	item_flag = true;
	item_time = std::chrono::high_resolution_clock::now();
	is_over = false;

	display.Print_Title();
	getch();
	erase();
	refresh();

	display.Print_Wall();
	display.Print_Snake(snake);
	snake.SetStarPos();
	snake.SetPoisonPos();
	snake.SetPortalPos();
	snake.SetItemPos();

	display.Print_Food(snake.GetStarPos());
	display.Print_Poison(snake.GetPoisonPos());
	display.Print_Item(snake.GetItemPos());
	display.Print_Score(snake);
	display.Print_Portal(snake.GetPortalPos());
}

void SnakeManager::Game()
{
	Util util;
	int key;
	int delay = 100000; // 게임 속도 조절, 노란색 아이템 먹으면 감소하면서 속도 빨라짐

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

		display.Print_Portal(snake.GetPortalPos()); // 만약 포탈 들어가면 지워지니까 계속 그림

		if(snake.head() == snake.GetPortalPos()[0]) // 첫 번째 포탈 들어갔을 때
		{
			Point nextPortal = snake.GetPortalPos()[1];
			snake.GetGate()++;
			*snake.GetBody().begin() = nextPortal;

			if(nextPortal.x == 0)
				snake.Set_Direction(RIGHT_KEY_CODE);
			else if(nextPortal.x == (GBOARD_WIDTH + START_MAP_X / 2 + 1) * 2)
				snake.Set_Direction(LEFT_KEY_CODE);	
			else if(nextPortal.y == 0)
				snake.Set_Direction(DOWN_KEY_CODE);
			else if(nextPortal.y == GBOARD_HEIGHT + START_MAP_Y + 1)
				snake.Set_Direction(UP_KEY_CODE);
		}
		else if(snake.head() == snake.GetPortalPos()[1]) // 두 번째 포탈 들어갔을 때
		{
			Point nextPortal = snake.GetPortalPos()[0];
			snake.GetGate()++;
			*snake.GetBody().begin() = nextPortal;

			if(nextPortal.x == 0)
				snake.Set_Direction(RIGHT_KEY_CODE);
			else if(nextPortal.x == (GBOARD_WIDTH + START_MAP_X / 2 + 1) * 2)
				snake.Set_Direction(LEFT_KEY_CODE);
			else if(nextPortal.y == 0)
				snake.Set_Direction(DOWN_KEY_CODE);
			else if(nextPortal.y == GBOARD_HEIGHT + START_MAP_Y + 1)
				snake.Set_Direction(UP_KEY_CODE);
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

		snake.Move(); // 현재 방향으로 이동 중인 스네이크 리스트 head 원소 변경
		display.Print_Snake(snake); // 스네이크 리스트에 있는 좌표들에 출력
		
		if (snake.head() == snake.GetStarPos()) // 아이템 먹었을 때
		{
			start = std::chrono::high_resolution_clock::now();
			snake.GetScore() += snake.GetLevel() * 10; // 점수 계산인데 일단 대충 만들었음. 먹은 아이템 * 10
			snake.GetGrowth()++;
			if (snake.GetGrowth() % 5 == 0)
			{
				if(snake.GetStageLevel() < 4)
					snake.GetStageLevel()++;
				display.Load_Wall(snake.GetStageLevel());
				clear();
				snake.SetPortalPos();
				display.Print_Portal(snake.GetPortalPos());
				display.Print_Wall();
				display.Print_Food(snake.GetStarPos());
				display.Print_Poison(snake.GetPoisonPos());
				display.Print_Item(snake.GetItemPos());
				display.Print_Score(snake);
				refresh();
			}

			GetStar(before);
		}

		else if(snake.head() == snake.GetPoisonPos()) // 독 아이템 먹었을 때
		{
			GetPoison(before);
			snake.GetPoison()++;

			if(snake.GetBody().size() < 3)
			{
				display.Print_GameOver();
				
				while (true)
				{
					display.Print_GameOver();
					getch();
				}
			}
		}

		else if(snake.head() == snake.GetItemPos()) // 속도 빨라지는 아이템 먹었을 때
		{
			delay -= 5000;
			snake.GetSpeed()++;	// 속도 출력용 변수
			snake.SetItemPos();
			display.Print_Item(snake.GetItemPos());
		}

		// ================ 5초 마다 아이템 다시 그리기 =================== //
		auto end = std::chrono::high_resolution_clock::now();
		std::chrono::duration<double> duration = end - start;

		/*
			item_flag 변수 존재 이유
			5초에서 6초로 가는 1초 사이에 while문이 계속 실행돼서 아이템을 계속 다시 그림
			뭔 소린지 이해 안가거나 궁금하면 if문에서 item_flag 지우고 실행해보기
		*/
		if(static_cast<int>(duration.count()) > 0 && static_cast<int>(duration.count()) % 5 == 0 && item_flag)
		{
			item_time = std::chrono::high_resolution_clock::now();
			display.Erase_Food(snake.GetStarPos());
			snake.SetStarPos();
			display.Print_Food(snake.GetStarPos());
			item_flag = false;
		}

		auto item_duration = item_time - std::chrono::high_resolution_clock::now();
		if(static_cast<int>(item_duration.count()) > 1) // 1초 지나야 다시 아이템 그릴 수 있도록 item_flag = true
			item_flag = true;

		display.Print_Portal(snake.GetPortalPos());
		display.Print_Score(snake);
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

	util.SetColorText(SNAKE);
	util.CursorUtil_Print(nextTail.x, nextTail.y, "  ");

	util.CursorUtil_Set(curPos.x, curPos.y);
}

void SnakeManager::GetStar(Point before)
{
	Print_Tail(before);

	snake.SetStarPos();
	display.Print_Food(snake.GetStarPos());
	snake.GetLevel() = std::max(snake.GetLevel(), static_cast<int>(snake.GetBody().size()));
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