#include <iostream>
#include <ncurses.h>

#include "point.hpp"
#include "display.hpp"

int main(void)
{
	initscr();
	cbreak();
	noecho();
	keypad(stdscr, true);
	curs_set(0);

	Display display;
	display.Print_Wall();
	refresh();

	getch();

	endwin();
	return 0;
}