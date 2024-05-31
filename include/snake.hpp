#ifndef __SNAKE_H_
#define __SNAKE_H_

#include <list>
#define START_SNAKE_POS_X	70
#define START_SNAKE_POS_Y	25

#include "point.hpp"

class Snake
{
private:
	std::list<Point> body;
	Point starPos;	
	Point poisonPos;				
	int direction;					
	int level;						
	int score;						
private:
	void Move_UP();
	void Move_Down();
	void Move_Left();
	void Move_Right();
public:
	Snake();

	void Init();					
	void Set_Direction(int key);	
	void Move();					
	bool Is_Bitten();				
	bool Is_Collistion();			
	int GetDirection();				
	int& GetLevel();				
	int& GetScore();
	void SetStarPos();
	void SetPoisonPos();				

	void SaveScore();

	Point GetStarPos();	
	Point GetPoisonPos();
				
	std::list<Point>& GetBody();	
	Point EraseTail();				

	Point head();					
	Point tail();					
};

#endif