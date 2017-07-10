#include "Constant.h"
#include "Snake.h"
#include "Display.h"
#include "Util.h"
#include <cstdlib>
#include <ctime>

Snake::Snake()
{
}

void Snake::Init()
{
	body.clear();

	Point pos[2] = {
		{ START_SNAKE_POS_X, START_SNAKE_POS_Y },
		{ START_SNAKE_POS_X, START_SNAKE_POS_Y + 1 }
	};

	body.push_front(pos[0]);
	body.push_back(pos[1]);

	direction = KeyCode::RIGHT_KEY_CODE;
}

void Snake::Set_Direction(int key)
{
	if (direction == KeyCode::UP_KEY_CODE && key == KeyCode::DOWN_KEY_CODE)
		return;
	if (direction == KeyCode::LEFT_KEY_CODE && key == KeyCode::RIGHT_KEY_CODE)
		return;
	if (direction == KeyCode::RIGHT_KEY_CODE && key == KeyCode::LEFT_KEY_CODE)
		return;
	if (direction == KeyCode::DOWN_KEY_CODE && key == KeyCode::UP_KEY_CODE)
		return;

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

	switch (direction)
	{
	case KeyCode::LEFT_KEY_CODE:
		if (board[headPos.y][(headPos.x - 2) / 2] == 1)
			return true;
		break;
	case KeyCode::RIGHT_KEY_CODE:
		if (board[headPos.y][(headPos.x + 2) / 2] == 1)
			return true;
		break;
	case KeyCode::UP_KEY_CODE:
		if (board[headPos.y - 1][headPos.x / 2] == 1)
			return true;
		break;
	case KeyCode::DOWN_KEY_CODE:
		if (board[headPos.y + 1][headPos.x / 2] == 1)
			return true;
		break;
	}

	return false;
}

std::list<Point>* Snake::GetBody()
{
	return &body;
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
	if (Is_Collistion() == true || Is_Bitten() == true) {
		Display().Print_Prompt("Game Over~");
		exit(-1);
	}

	Point HeadPos = { head().x, head().y - 1 };

	body.push_front(HeadPos);
}

void Snake::Move_Down()
{
	if (Is_Collistion() == true || Is_Bitten() == true) {
		Display().Print_Prompt("Game Over~");
		exit(-1);
	}

	Point HeadPos = { head().x, head().y + 1 };
	body.push_front(HeadPos);
}

void Snake::Move_Left()
{
	if (Is_Collistion() == true || Is_Bitten() == true) {
		Display().Print_Prompt("Game Over~");
		exit(-1);
	}

	Point HeadPos = { head().x - 2, head().y };
	body.push_front(HeadPos);
}

void Snake::Move_Right()
{
	if (Is_Collistion() == true || Is_Bitten() == true) {
		Display().Print_Prompt("Game Over~");
		exit(-1);
	}

	Point HeadPos = { head().x + 2, head().y };
	body.push_front(HeadPos);
}

int Snake::GetDirection()
{
	return direction;
}

void Snake::SetStarPos()
{
	srand((unsigned int)time(NULL));

	int x = (rand() % GBOARD_WIDTH + 1) * 2;
	int y = rand() % GBOARD_HEIGHT + 1;
	starPos.x = x;
	starPos.y = y;

	for (auto i = body.begin(); i != body.end(); i++)
	{
		if (starPos == *i) {
			int x = (rand() % GBOARD_WIDTH + 1) * 2;
			int y = rand() % GBOARD_HEIGHT + 1;
			starPos.x = x;
			starPos.y = y;
		}
	}
}

Point Snake::GetStarPos()
{
	return starPos;
}

Point Snake::EraseTail()
{
	Util util;
	Point tailPos = tail();

	util.CursorUtil_Set(tailPos.x, tailPos.y);
	std::cout << "  ";

	body.remove(body.back());
	return tailPos;
}