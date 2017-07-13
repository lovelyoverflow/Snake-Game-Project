#include "Common.h"
#include "Display.h"
#include "Constant.h"
#include "Util.h"
#include <conio.h>
#include <cstdlib>
#include <ctime>

Display::Display()
{}

int Display::board[GBOARD_HEIGHT + 2][GBOARD_WIDTH + 2] = { 0, };

void Display::Print_Title()
{
	Util util;
	Point curPos = util.CursorUtil_Get();

	util.SetColorText(11);

	util.CursorUtil_Set(TITLE_POS_X - 25, TITLE_POS_Y - 5);
	std::cout << "      ___           ___           ___           ___           ___                    ___           ___           ___           ___";
	util.CursorUtil_Set(TITLE_POS_X - 25, TITLE_POS_Y - 4);
	std::cout << "     /  /\\         /__/\\         /  /\\         /__/|         /  /\\                  /  /\\         /  /\\         /__/\\         /  /\\";
	util.CursorUtil_Set(TITLE_POS_X - 25, TITLE_POS_Y - 3);
	std::cout << "    /  /:/_        \\  \\:\\       /  /::\\       |  |:|        /  /:/_                /  /:/_       /  /::\\       |  |::\\       /  /:/_";
	util.CursorUtil_Set(TITLE_POS_X - 25, TITLE_POS_Y - 2);
	std::cout << "   /  /:/ /\\        \\  \\:\\     /  /:/\\:\\      |  |:|       /  /:/ /\\              /  /:/ /\\     /  /:/\\:\\      |  |:|:\\     /  /:/ /\\";
	util.CursorUtil_Set(TITLE_POS_X - 25, TITLE_POS_Y - 1);
	std::cout << "  /  /:/ /::\\   _____\\__\\:\\   /  /:/~/::\\   __|  |:|      /  /:/ /:/_            /  /:/_/::\\   /  /:/~/::\\   __|__|:|\\:\\   /  /:/ /:/_";
	util.CursorUtil_Set(TITLE_POS_X - 25, TITLE_POS_Y);
	std::cout << " /__/:/ /:/\\:\\ /__/::::::::\\ /__/:/ /:/\\:\\ /__/\\_|:|____ /__/:/ /:/ /\\          /__/:/__\\/\\:\\ /__/:/ /:/\\:\\ /__/::::| \\:\\ /__/:/ /:/ /\\";
	util.CursorUtil_Set(TITLE_POS_X - 25, TITLE_POS_Y + 1);
	std::cout << " \\  \\:\\/:/~/:/ \\  \\:\\~~\\~~\\/ \\  \\:\\/:/__\\/ \\  \\:\\/:::::/ \\  \\:\\/:/ /:/          \\  \\:\\ /~~/:/ \\  \\:\\/:/__\\/ \\  \\:\\~~\\__\\/ \\  \\:\\/:/ /:/";
	util.CursorUtil_Set(TITLE_POS_X - 25, TITLE_POS_Y + 2);
	std::cout << "  \\  \\::/ /:/   \\  \\:\\  ~~~   \\  \\::/       \\  \\::/~~~~   \\  \\::/ /:/            \\  \\:\\  /:/   \\  \\::/       \\  \\:\\        \\  \\::/ /:/";
	util.CursorUtil_Set(TITLE_POS_X - 25, TITLE_POS_Y + 3);
	std::cout << "   \\__\\/ /:/     \\  \\:\\        \\  \\:\\        \\  \\:\\        \\  \\:\\/:/              \\  \\:\\/:/     \\  \\:\\        \\  \\:\\        \\  \\:\\/:/";
	util.CursorUtil_Set(TITLE_POS_X - 25, TITLE_POS_Y + 4);
	std::cout << "     /__/:/       \\  \\:\\        \\  \\:\\        \\  \\:\\        \\  \\::/                \\  \\::/       \\  \\:\\        \\  \\:\\        \\  \\::/";
	util.CursorUtil_Set(TITLE_POS_X - 25, TITLE_POS_Y + 5);
	std::cout << "     \\__\\/         \\__\\/         \\__\\/         \\__\\/         \\__\\/                  \\__\\/         \\__\\/         \\__\\/         \\__\\/";

	while (!_kbhit())
	{
		util.SetColorText(11);
		util.CursorUtil_Set(START_MAP_X + 55, 25);
		std::cout << ("Press and key to START");
		Sleep(400);
		util.CursorUtil_Set(START_MAP_X + 55, 25);
		std::cout << ("                      ");
		Sleep(400);
		util.SetColorText(10);

		util.CursorUtil_Set(START_MAP_X + 56, 28);
		std::cout << ("Press and P to PAUSE");
		util.CursorUtil_Set(START_MAP_Y + 58, 29);
		std::cout << ("Move:   ↑ ↓ ← →");
	}

	util.CursorUtil_Set(curPos.x, curPos.y);
}

void Display::Print_GameOver()
{
	Util util;
	Point curPos = util.CursorUtil_Get();

	util.SetColorText(11);

	util.CursorUtil_Set(TITLE_POS_X - 7, TITLE_POS_Y - 3);
	std::cout << " ________  ________  _____ ______   _______           ________  ___      ___ _______   ________";
	util.CursorUtil_Set(TITLE_POS_X - 7, TITLE_POS_Y - 2);
	std::cout << "|\\   ____\\|\\   __  \\|\\   _ \\  _   \\|\\  ___ \\         |\\   __  \\|\\  \\    /  /|\\  ___ \\ |\\   __  \\";
	util.CursorUtil_Set(TITLE_POS_X - 7, TITLE_POS_Y - 1);
	std::cout << "\\ \\  \\___|\\ \\  \\|\\  \\ \\  \\\\\\__\\ \\  \\ \\   __/|        \\ \\  \\|\\  \\ \\  \\  /  / | \\   __/|\\ \\  \\|\\  \\";
	util.CursorUtil_Set(TITLE_POS_X - 7, TITLE_POS_Y);
	std::cout << " \\ \\  \\  __\\ \\   __  \\ \\  \\\\|__| \\  \\ \\  \\_|/__       \\ \\  \\\\\\  \\ \\  \\/  / / \\ \\  \\_|/_\\ \\   _  _\\";
	util.CursorUtil_Set(TITLE_POS_X - 7, TITLE_POS_Y + 1);
	std::cout << "  \\ \\  \\|\\  \\ \\  \\ \\  \\ \\  \\    \\ \\  \\ \\  \\_|\\ \\       \\ \\  \\\\\\  \\ \\    / /   \\ \\  \\_|\\ \\ \\  \\\\  \\|";
	util.CursorUtil_Set(TITLE_POS_X - 7, TITLE_POS_Y + 2);
	std::cout << "   \\ \\_______\\ \\__\\ \\__\\ \\__\\    \\ \\__\\ \\_______\\       \\ \\_______\\ \\__/ /     \\ \\_______\\ \\__\\\\ _\\";
	util.CursorUtil_Set(TITLE_POS_X - 7, TITLE_POS_Y + 3);
	std::cout << "    \\|_______|\\|__|\\|__|\\|__|     \\|__|\\|_______|        \\|_______|\\|__|/       \\|_______|\\|__|\\|__|";

	while (!_kbhit())
	{
		util.CursorUtil_Set(TITLE_POS_X + 30, TITLE_POS_Y + 10);
		std::cout << "                    ";
		Sleep(400);

		util.CursorUtil_Set(TITLE_POS_X + 30, TITLE_POS_Y + 10);
		std::cout << "1. resume    2. exit";
		Sleep(500);
	}

	util.CursorUtil_Set(curPos.x, curPos.y);
}

void Display::Print_Wall()
{
	Util util;
	Point curPos = util.CursorUtil_Get();
	util.SetColorText(11);

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
				util.CursorUtil_Set(curPos.x + x * 2 + START_MAP_X, curPos.y + y + START_MAP_Y);
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

void Display::Print_Pause()
{
	Util util;
	Point curPos = util.CursorUtil_Get();
	util.SetColorText(11);

	util.CursorUtil_Set(TITLE_POS_X + 80, TITLE_POS_Y + 8);
	std::cout << " _____       _    _  _____ ______ ";
	util.CursorUtil_Set(TITLE_POS_X + 80, TITLE_POS_Y + 9);
	std::cout << "|  __ \\ /\\  | |  | |/ ____|  ____|";
	util.CursorUtil_Set(TITLE_POS_X + 80, TITLE_POS_Y + 10);
	std::cout << "| |__) /  \\ | |  | | (___ | |__   ";
	util.CursorUtil_Set(TITLE_POS_X + 80, TITLE_POS_Y + 11);
	std::cout << "|  ___/ /\\ \\| |  | |\\___ \\|  __|  ";
	util.CursorUtil_Set(TITLE_POS_X + 80, TITLE_POS_Y + 12);
	std::cout << "| |  / ____ \\ |__| |____) | |____ ";
	util.CursorUtil_Set(TITLE_POS_X + 80, TITLE_POS_Y + 13);
	std::cout << "|_| /_/    \\_\\____/|_____/|______|";

	util.CursorUtil_Set(curPos.x, curPos.y);
}

void Display::Erase_Pause()
{
	Util util;
	Point curPos = util.CursorUtil_Get();

	util.CursorUtil_Set(TITLE_POS_X + 80, TITLE_POS_Y + 8);
	std::cout << "                                        ";
	util.CursorUtil_Set(TITLE_POS_X + 80, TITLE_POS_Y + 9);
	std::cout << "                                        ";
	util.CursorUtil_Set(TITLE_POS_X + 80, TITLE_POS_Y + 10);
	std::cout << "                                        ";
	util.CursorUtil_Set(TITLE_POS_X + 80, TITLE_POS_Y + 11);
	std::cout << "                                        ";
	util.CursorUtil_Set(TITLE_POS_X + 80, TITLE_POS_Y + 12);
	std::cout << "                                        ";
	util.CursorUtil_Set(TITLE_POS_X + 80, TITLE_POS_Y + 13);
	std::cout << "                                        ";

	util.CursorUtil_Set(curPos.x, curPos.y);
}

void Display::Print_Ranking()
{
	Util util;
	Point curPos = util.CursorUtil_Get();

	system("cls");
	util.CursorUtil_Set(TITLE_POS_X + 30, TITLE_POS_Y + 5);
	std::cout << "What is your name?";
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

	util.CursorUtil_Set(START_MAP_X + 110, START_MAP_Y + 1);
	std::cout << "    ";
	util.CursorUtil_Set(START_MAP_X + 110, START_MAP_Y + 2);
	std::cout << "┏━━━━━━━━━┓";
	util.CursorUtil_Set(START_MAP_X + 110, START_MAP_Y + 3);
	std::cout << "┃                  ┃";
	util.CursorUtil_Set(START_MAP_X + 110, START_MAP_Y + 4);
	std::cout << "┃ 현재 점수: " << snake.GetScore();
	util.CursorUtil_Set(START_MAP_X + 130, START_MAP_Y + 4);
	std::cout << "┃";
	util.CursorUtil_Set(START_MAP_X + 110, START_MAP_Y + 5);
	std::cout << "┃                  ┃";
	util.CursorUtil_Set(START_MAP_X + 110, START_MAP_Y + 6);
	std::cout << "┃                  ┃";
	util.CursorUtil_Set(START_MAP_X + 110, START_MAP_Y + 7);
	std::cout << "┃ 현재 레벨: " << snake.GetLevel();
	util.CursorUtil_Set(START_MAP_X + 130, START_MAP_Y + 7);
	std::cout << "┃";
	util.CursorUtil_Set(START_MAP_X + 110, START_MAP_Y + 8);
	std::cout << "┃                  ┃";
	util.CursorUtil_Set(START_MAP_X + 110, START_MAP_Y + 9);
	std::cout << "┗━━━━━━━━━┛" << std::endl;

	util.CursorUtil_Set(curPos.x, curPos.y);
}