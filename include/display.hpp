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
	static std::vector<std::vector<int>> board;
public:
	Display();
	void Print_Title();										
	void Print_GameOver();	
	void Init_Wall();
	void Load_Wall(int stage);							
	void Print_Wall();										
	void Print_Food(Point pos);
	void Erase_Food(Point pos);
	
	void Print_Poison(Point pos);	
	void Print_Item(Point pos);						
	void Print_Snake(Snake snake);	
	void Print_Portal(std::vector<Point> pos);

	void Print_Pause();										
	void Erase_Pause();										
	void Print_Ranking();

	std::vector<std::vector<int>>& GetBoard();				

	void Print_Prompt(std::string str);						
	void Print_Score(Snake snake);							
};

#endif