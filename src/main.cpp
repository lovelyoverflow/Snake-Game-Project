#include <iostream>
#include <ncurses.h>
#include <locale>

#include "snakemanager.hpp"

int main(void)
{
	setlocale(LC_ALL, "");

	initscr();
	start_color();	

	cbreak();
	noecho();
	keypad(stdscr, true);
	curs_set(0);

	SnakeManager manager;
	manager.Init();

	while(true)
		manager.Game();
		
	// getch();

	endwin();
	return 0;
}