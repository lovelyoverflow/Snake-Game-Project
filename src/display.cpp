#include <iostream>
#include <cstdlib>
#include <ctime>

#include "util.cpp"
#include "display.hpp"
#include "constant.hpp"
#include "snake.hpp"
#include "point.hpp"

Display::Display()
{}

int Display::board[GBOARD_HEIGHT + 2][GBOARD_WIDTH + 2] = { 0, };

void Display::Print_Title()
{

}

void Display::Print_GameOver()
{

}

void Display::Print_Wall()
{
	Util util;
	Point curPos = util.CursorUtil_Get();

	start_color();
    init_pair(1, COLOR_BLUE, COLOR_WHITE);   // Wall
 	wattron(stdscr, COLOR_PAIR(1));

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
				mvprintw(curPos.y + y + START_MAP_Y, curPos.x + x * 2 + START_MAP_X, "  ");
			}
		}
	}

	util.CursorUtil_Set(curPos.x, curPos.y);
}

void Display::Print_Food(Point pos)
{
}

void Display::Print_Snake(Snake snake)
{
}

void Display::Print_Pause()
{
}

void Display::Erase_Pause()
{
}

void Display::Print_Ranking()
{
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
	std::cout << str;
}

void Display::Print_Score(Snake snake)
{
}