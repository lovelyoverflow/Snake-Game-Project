#ifndef __DISPLAY_H_
#define __DISPLAY_H_

#define GBOARD_WIDTH	50
#define GBOARD_HEIGHT	30

#define START_MAP_X		0
#define START_MAP_Y		0

#define TITLE_POS_X		30
#define TITLE_POS_Y		10

#include <string>
#include <vector>

#include "snake.hpp"

class Display
{
private:
	static int board[GBOARD_HEIGHT + 2][GBOARD_WIDTH + 2];
public:
	Display();
	void Print_Title();										
	void Print_GameOver();	
	void Init_Wall();								
	void Print_Wall();										
	void Print_Food(Point pos);
	void Erase_Food(Point pos);
	
	void Print_Poison(Point pos);							
	void Print_Snake(Snake snake);	
	void Print_Portal(std::vector<Point> pos);

	void Print_Pause();										
	void Erase_Pause();										
	void Print_Ranking();

	void GetBoard(int(*boa)[GBOARD_WIDTH + 2]);				

	void Print_Prompt(std::string str);						
	void Print_Score(Snake snake);							
};

#endif