#include "Common.h"
#include "Display.h"
#include "Constant.h"
#include "Util.h"
#include <cstdlib>
#include <ctime>

Display::Display()
{}

int Display::board[GBOARD_HEIGHT + 2][GBOARD_WIDTH + 2] = { 0, };

void Display::Print_Wall()
{
	Util util;
	Point curPos = util.CursorUtil_Get();
	util.SetColorText(10);

	for (int y = 0; y < GBOARD_HEIGHT + 2; y++) {
		board[y][0] = 1;
		board[y][GBOARD_WIDTH + 1] = 1;
	}

	for (int x = 0; x < GBOARD_WIDTH + 2; x++) {
		board[0][x] = 1;
		board[GBOARD_HEIGHT + 1][x] = 1;
	}

	for (int y = 0; y < GBOARD_HEIGHT + 2; y++)
	{
		for (int x = 0; x < GBOARD_WIDTH + 2; x++)
		{
			if (board[y][x] == 1)
			{
				util.CursorUtil_Set(curPos.x + x * 2, curPos.y + y);
				std::cout << "▩";
			}
		}
	}

	util.CursorUtil_Set(curPos.x, curPos.y);
}

void Display::Print_Food(Point pos)
{
	Util util;
	Point curPos = util.CursorUtil_Get();
	util.SetColorText(14);

	util.CursorUtil_Set(pos.x, pos.y);
	std::cout << "★";

	util.CursorUtil_Set(curPos.x, curPos.y);
}

void Display::Print_Snake(Snake snake)
{
	Util util;
	Point curPos = util.CursorUtil_Get();
	util.SetColorText(10);

	for (auto i = snake.GetBody()->begin(); i != snake.GetBody()->end(); i++)
	{
		util.CursorUtil_Set(i->x, i->y);
		std::cout << "▣";
	}
}

void Display::GetBoard(int(*boa)[GBOARD_WIDTH + 2])
{
	for (int y = 0; y < GBOARD_HEIGHT + 2; y++)
	{
		for (int x = 0; x < GBOARD_WIDTH + 2; x++)
			boa[y][x] = board[y][x];
	}
}

void Display::Print_Prompt(std::string str)
{
	Util util;
	util.SetColorText(3);

	std::cout << str;
}

void Display::Print_Score(Snake snake)
{
	Util util;
	Point curPos = util.CursorUtil_Get();
	util.SetColorText(15);

	util.CursorUtil_Set(95, 5);
	std::cout << "    ";
	util.CursorUtil_Set(95, 6);
	std::cout << "┏━━━━━━━━━";
	util.CursorUtil_Set(95, 7);
	std::cout << "┃ 현재 점수: " << snake.GetBody()->size() - 2;
	util.CursorUtil_Set(95, 8);
	std::cout << "┗━━━━━━━━━" << std::endl;
}