#include <iostream>

#include "constant.hpp"
#include "snake.hpp"
#include "display.hpp"
#include "util.hpp"
#include <cstdlib>
#include <ctime>

Snake::Snake()
{
}

void Snake::Init()
{
	body.clear();
	level = 3;
	score = 0;
	growth = 0;
	poison = 0;
	gate = 0;

	//초기 스네이크 위치 지정
	Point pos[3] = {
		{ START_SNAKE_POS_X, START_SNAKE_POS_Y },
		{ START_SNAKE_POS_X, START_SNAKE_POS_Y + 1 },
		{ START_SNAKE_POS_X, START_SNAKE_POS_Y + 2 }
	};

	body.push_front(pos[0]);
	body.push_back(pos[1]);
	body.push_back(pos[2]);

	direction = KeyCode::RIGHT_KEY_CODE;
}

void Snake::Set_Direction(int key)
{
	/*
		주석 처리한 부분은
		만약 내가 왼쪽으로 가는중인데 오른쪽 방향키 눌렀을 때 방지하는건데
		과제에서는 그 경우에 그냥 게임오버라서 주석처리
	*/

	// if (direction == KeyCode::UP_KEY_CODE && key == KeyCode::DOWN_KEY_CODE)
	// 	return;
	// if (direction == KeyCode::LEFT_KEY_CODE && key == KeyCode::RIGHT_KEY_CODE)
	// 	return;
	// if (direction == KeyCode::RIGHT_KEY_CODE && key == KeyCode::LEFT_KEY_CODE)
	// 	return;
	// if (direction == KeyCode::DOWN_KEY_CODE && key == KeyCode::UP_KEY_CODE)
	// 	return;

	direction = key;
}

void Snake::Move()
{
	switch (direction)
	{
	case KeyCode::LEFT_KEY_CODE:
		Move_Left();
		break;
	case KeyCode::RIGHT_KEY_CODE:
		Move_Right();
		break;
	case KeyCode::UP_KEY_CODE:
		Move_UP();
		break;
	case KeyCode::DOWN_KEY_CODE:
		Move_Down();
		break;
	case PAUSE_KEY_CODE:
		Display().Print_Pause();
		break;
	}
}

bool Snake::Is_Bitten()
{
	auto i = body.begin();
	i++;

	while (i != body.end())
	{
		if (head() == *i)
			return true;

		i++;
	}

	return false;
}

bool Snake::Is_Collistion()
{
	Point headPos = head();
	Display display;
	int board[GBOARD_HEIGHT + 2][GBOARD_WIDTH + 2];

	display.GetBoard(board);

	/*
		충돌 검사는 내가 가려는 방향을 먼저 계산한 다음 그 부분이 1(벽)인지 확인
	*/
	switch (direction)
	{
	case KeyCode::LEFT_KEY_CODE:
		if (board[headPos.y - START_MAP_Y][(headPos.x - START_MAP_X - 2) / 2] == 1)
			return true;
		break;
	case KeyCode::RIGHT_KEY_CODE:
		if (board[headPos.y - START_MAP_Y][(headPos.x - START_MAP_X + 2) / 2] == 1)
			return true;
		break;
	case KeyCode::UP_KEY_CODE:
		if (board[headPos.y - 1 - START_MAP_Y][(headPos.x - START_MAP_X) / 2] == 1)
			return true;
		break;
	case KeyCode::DOWN_KEY_CODE:
		if (board[headPos.y + 1 - START_MAP_Y][(headPos.x - START_MAP_X) / 2] == 1)
			return true;
		break;
	}

	return false;
}

bool Snake::Is_Portal()
{
	Point headPos = head();
	Display display;
	int board[GBOARD_HEIGHT + 2][GBOARD_WIDTH + 2];

	display.GetBoard(board);

	switch (direction)
	{
	case KeyCode::LEFT_KEY_CODE:
		if (headPos.x - 2 == GetPortalPos()[1].x)
			return true;
	case KeyCode::UP_KEY_CODE:
		if (headPos.y - 1 == GetPortalPos()[0].y)
			return true;
	}

	return false;
}

std::list<Point>& Snake::GetBody()
{
	return body;
}

int& Snake::GetLevel()
{
	return level;
}

int& Snake::GetScore()
{
	return score;
}

int &Snake::GetGrowth()
{
    return growth;
}

int &Snake::GetPoison()
{
    return poison;
}

int &Snake::GetGate()
{
    return gate;
}

Point Snake::head()
{
	return body.front();
}

Point Snake::tail()
{
	return body.back();
}

void Snake::Move_UP()
{
	Point HeadPos = { head().x, head().y - 1 };
	body.push_front(HeadPos);
}

void Snake::Move_Down()
{
	Point HeadPos = { head().x, head().y + 1 };
	body.push_front(HeadPos);
}

void Snake::Move_Left()
{
	Point HeadPos = { head().x - 2, head().y };
	body.push_front(HeadPos);
}

void Snake::Move_Right()
{
	Point HeadPos = { head().x + 2, head().y };
	body.push_front(HeadPos);
}

int Snake::GetDirection()
{
	return direction;
}

void Snake::SetStarPos()
{
	Util util;
	int x = util.Get_Random(1, GBOARD_WIDTH + START_MAP_X / 2) * 2;
	int y = util.Get_Random(1, GBOARD_HEIGHT + START_MAP_Y);
	
	starPos.x = x;
	starPos.y = y;

	//만약 스네이크가 있는 부분에 아이템을 띄우려고 하면 다시 랜덤 돌리기
	for (auto i = body.begin(); i != body.end(); i++)
	{
		if (starPos == *i) {
			int x = util.Get_Random(1, GBOARD_WIDTH + START_MAP_X / 2) * 2;
			int y = util.Get_Random(1, GBOARD_HEIGHT + START_MAP_Y);
			
			starPos.x = x;
			starPos.y = y;
		}
	}
}

void Snake::SetPoisonPos()
{
	Util util;
	int x = util.Get_Random(1, GBOARD_WIDTH + START_MAP_X / 2) * 2;
	int y = util.Get_Random(1, GBOARD_HEIGHT + START_MAP_Y);
	
	poisonPos.x = x;
	poisonPos.y = y;

	//만약 스네이크가 있는 부분에 독 아이템을 띄우려고 하면 다시 랜덤 돌리기
	for (auto i = body.begin(); i != body.end(); i++)
	{
		if (starPos == *i)
		{
			int x = util.Get_Random(1, GBOARD_WIDTH + START_MAP_X / 2) * 2;
			int y = util.Get_Random(1, GBOARD_HEIGHT + START_MAP_Y);

			poisonPos.x = x;
			poisonPos.y = y;
		}
	}
}

void Snake::SetPortalPos()
{
	Util util;
	
	int x1 = util.Get_Random(1, GBOARD_WIDTH + START_MAP_X / 2) * 2;
	int y1 = 0;

	int x2 = 0;
	int y2 = util.Get_Random(1, GBOARD_HEIGHT + START_MAP_Y);

	portalPos.push_back(Point(x1, y1));
	portalPos.push_back(Point(x2, y2));
}

Point Snake::GetStarPos()
{
	return starPos;
}

Point Snake::GetPoisonPos()
{
	return poisonPos;
}

std::vector<Point> Snake::GetPortalPos()
{
	return portalPos;
}

void Snake::SaveScore()
{
	FILE * fp = fopen("C:\\Users\\score.txt", "wt");
	Util util;	
	char name[100];

	util.CursorUtil_Set(TITLE_POS_X + 30, TITLE_POS_Y + 17);
	fgets(name, sizeof(name), stdin);
	fprintf(fp, "%s %d \n", name, score);

	exit(0);
}

Point Snake::EraseTail()
{
	Util util;
	Point tailPos = tail();

	// util.CursorUtil_Set(tailPos.x, tailPos.y);
	// std::cout << "  ";
	util.SetColorText(BLANK);
	util.CursorUtil_Print(tailPos.x, tailPos.y, "  ");

	body.remove(body.back());
	return tailPos;
}
