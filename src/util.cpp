#include "util.hpp"
#include "constant.hpp"
#include <ncurses.h>

void Util::CursorUtil_Set(int x, int y)
{
	move(x, y);
}

void Util::CursorUtil_Hide(void)
{
}

Point Util::CursorUtil_Get(void)
{
	Point cur_pos;
	getyx(stdscr, cur_pos.y, cur_pos.x);

	return cur_pos;
}

void Util::CursorUtil_Print(int x, int y, const char* str)
{
	mvprintw(y, x, str);
}

void Util::SetColorText(Color color)
{
 	wattron(stdscr, COLOR_PAIR(color));
}

bool Util::kbhit(void)
{
	int ch = getch();

    if (ch != ERR) 
	{
        ungetch(ch);
        return true;
    } 
	else 
        return false;
}