#ifndef __DISPLAY_H_
#define __DISPLAY_H_

#define GBOARD_WIDTH	50
#define GBOARD_HEIGHT	30

#define START_MAP_X		0
#define START_MAP_Y		0

#define TITLE_POS_X		30
#define TITLE_POS_Y		10

#include <string>

#include "snake.hpp"

class Display
{
private:
	static int board[GBOARD_HEIGHT + 2][GBOARD_WIDTH + 2];
	// WINDOW *map_panel;
	// WINDOW *score_panel;
	// WINDOW *mission_panel;
public:
	Display();
	void Print_Title();										
	void Print_GameOver();									
	void Print_Wall();										
	void Print_Food(Point pos);								
	void Print_Snake(Snake snake);							
	void Print_Pause();										
	void Erase_Pause();										
	void Print_Ranking();

	void GetBoard(int(*boa)[GBOARD_WIDTH + 2]);				

	void Print_Prompt(std::string str);						
	void Print_Score(Snake snake);							
};

#endif