#ifndef __DISPLAY_H_
#define __DISPLAY_H_

#define GBOARD_WIDTH	35
#define GBOARD_HEIGHT	25

#include "Snake.h"
#include <string>
class Display
{
private:
	static int board[GBOARD_HEIGHT + 2][GBOARD_WIDTH + 2];
public:
	Display();
	void Print_Wall();
	void Print_Food(Point pos);
	void Print_Snake(Snake snake);
	void GetBoard(int(*boa)[GBOARD_WIDTH + 2]);
	void Print_Prompt(std::string str);
	void Print_Score(Snake snake);
};

#endif