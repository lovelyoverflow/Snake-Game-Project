#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h>

#include "util.cpp"
#include "display.hpp"
#include "constant.hpp"
#include "snake.hpp"
#include "point.hpp"

Display::Display()
{
	init_pair(WALL, COLOR_WHITE, COLOR_WHITE);
	init_pair(FOOD, COLOR_WHITE, COLOR_BLUE);
	init_pair(IMMUNE_WALL, COLOR_WHITE, COLOR_CYAN);
	init_pair(TITLE, COLOR_YELLOW, COLOR_BLACK);
}

int Display::board[GBOARD_HEIGHT + 2][GBOARD_WIDTH + 2] = { 0, };

void Display::Print_Title()
{
	Util util;
	Point curPos = util.CursorUtil_Get();

	util.SetColorText(TITLE);
	util.CursorUtil_Print(TITLE_POS_X - 25, TITLE_POS_Y - 5, "      ___           ___           ___           ___           ___                    ___           ___           ___           ___");
	util.CursorUtil_Print(TITLE_POS_X - 25, TITLE_POS_Y - 4, "     /  /\\         /__/\\         /  /\\         /__/|         /  /\\                  /  /\\         /  /\\         /__/\\         /  /\\");
	util.CursorUtil_Print(TITLE_POS_X - 25, TITLE_POS_Y - 3, "    /  /:/_        \\  \\:\\       /  /::\\       |  |:|        /  /:/_                /  /:/_       /  /::\\       |  |::\\       /  /:/_");
	util.CursorUtil_Print(TITLE_POS_X - 25, TITLE_POS_Y - 2, "   /  /:/ /\\        \\  \\:\\     /  /:/\\:\\      |  |:|       /  /:/ /\\              /  /:/ /\\     /  /:/\\:\\      |  |:|:\\     /  /:/ /\\");
	util.CursorUtil_Print(TITLE_POS_X - 25, TITLE_POS_Y - 1, "  /  /:/ /::\\   _____\\__\\:\\   /  /:/~/::\\   __|  |:|      /  /:/ /:/_            /  /:/_/::\\   /  /:/~/::\\   __|__|:|\\:\\   /  /:/ /:/_");
	util.CursorUtil_Print(TITLE_POS_X - 25, TITLE_POS_Y    , " /__/:/ /:/\\:\\ /__/::::::::\\ /__/:/ /:/\\:\\ /__/\\_|:|____ /__/:/ /:/ /\\          /__/:/__\\/\\:\\ /__/:/ /:/\\:\\ /__/::::| \\:\\ /__/:/ /:/ /\\");
	util.CursorUtil_Print(TITLE_POS_X - 25, TITLE_POS_Y + 1, " \\  \\:\\/:/~/:/ \\  \\:\\~~\\~~\\/ \\  \\:\\/:/__\\/ \\  \\:\\/:::::/ \\  \\:\\/:/ /:/          \\  \\:\\ /~~/:/ \\  \\:\\/:/__\\/ \\  \\:\\~~\\__\\/ \\  \\:\\/:/ /:/");
	util.CursorUtil_Print(TITLE_POS_X - 25, TITLE_POS_Y + 2, "  \\  \\::/ /:/   \\  \\:\\  ~~~   \\  \\::/       \\  \\::/~~~~   \\  \\::/ /:/            \\  \\:\\  /:/   \\  \\::/       \\  \\:\\        \\  \\::/ /:/");
	util.CursorUtil_Print(TITLE_POS_X - 25, TITLE_POS_Y + 3, "   \\__\\/ /:/     \\  \\:\\        \\  \\:\\        \\  \\:\\        \\  \\:\\/:/              \\  \\:\\/:/     \\  \\:\\        \\  \\:\\        \\  \\:\\/:/");
	util.CursorUtil_Print(TITLE_POS_X - 25, TITLE_POS_Y + 4, "     /__/:/       \\  \\:\\        \\  \\:\\        \\  \\:\\        \\  \\::/                \\  \\::/       \\  \\:\\        \\  \\:\\        \\  \\::/");
	util.CursorUtil_Print(TITLE_POS_X - 25, TITLE_POS_Y + 5, "     \\__\\/         \\__\\/         \\__\\/         \\__\\/         \\__\\/                  \\__\\/         \\__\\/         \\__\\/         \\__\\/");

	// while (!util.kbhit())
	{
		util.SetColorText(TITLE);
		util.CursorUtil_Print(START_MAP_X + 55, 25, "Press and key to START");
		// usleep(400);
		// mvprintw(START_MAP_X + 55, 25, "                      ");
		// usleep(400);
		// refresh();

		util.CursorUtil_Print(START_MAP_X + 56, 28, "Press and P to PAUSE");
		util.CursorUtil_Print(START_MAP_X + 54, 29, "Move: up down left right");

		getch();
		erase();
		refresh();
	}

	util.CursorUtil_Set(curPos.x, curPos.y);
}

void Display::Print_GameOver()
{

}

void Display::Print_Wall()
{
	Util util;
	Point curPos = util.CursorUtil_Get();

	for(int y = 0; y < GBOARD_HEIGHT + 2; y++)
	{
		for(int x = 0; x < GBOARD_WIDTH + 2; x++)
		{
			if(x == 0 || x == GBOARD_WIDTH + 1)
			{
				if(y == 0 || y == GBOARD_HEIGHT + 1)
					board[y][x] = 2;
				else
					board[y][x] = 1;
			}
			else
			{
				if(y == 0 || y == GBOARD_HEIGHT + 1)
					board[y][x] = 1;
			}
		}
	}

	for (int y = 0; y < GBOARD_HEIGHT + 2; y++)
	{
		for (int x = 0; x < GBOARD_WIDTH + 2; x++)
		{
			if (board[y][x] == 1)
			{
				wattron(stdscr, COLOR_PAIR(WALL));
				mvprintw(curPos.y + y + START_MAP_Y, curPos.x + x * 2 + START_MAP_X, "  ");
			}
			else if(board[y][x] == 2)
			{
				wattron(stdscr, COLOR_PAIR(IMMUNE_WALL));
				mvprintw(curPos.y + y + START_MAP_Y, curPos.x + x * 2 + START_MAP_X, "  ");
			}
		}
	}

	util.CursorUtil_Set(curPos.x, curPos.y);
}

void Display::Print_Food(Point pos)
{
	Util util;
	Point curPos = util.CursorUtil_Get();
	// start_color();
    // init_pair(FOOD, COLOR_WHITE, COLOR_BLUE);
 	wattron(stdscr, COLOR_PAIR(FOOD));

	// util.CursorUtil_Set(pos.x, pos.y);
	// std::cout << "★";
	mvprintw(pos.y, pos.x, "  ");

	util.CursorUtil_Set(curPos.x, curPos.y);
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