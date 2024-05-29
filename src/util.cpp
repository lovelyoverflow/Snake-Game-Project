#include "util.hpp"

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

void Util::SetColorText(int color)
{
}