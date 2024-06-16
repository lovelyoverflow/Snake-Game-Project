#ifndef __SNAKE_H_
#define __SNAKE_H_

#include <list>
#include <vector>
#include <chrono>

#define START_SNAKE_POS_X	70
#define START_SNAKE_POS_Y	25

#include "point.hpp"

class Snake
{
private:
	std::list<Point> body;
	Point starPos;	
	Point poisonPos;
	Point itemPos;
	std::vector<Point> portalPos;		

	int direction;					
	int level;						
	int score;		
	int growth;
	int poison;
	int gate;	
	int speed;			
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
	bool Is_Portal();		
	int GetDirection();				
	int& GetLevel();				
	int& GetScore();
	int& GetGrowth();
	int& GetPoison();
	int& GetSpeed();
	int& GetGate();
	void SetStarPos();
	void SetPoisonPos();	
	void SetItemPos();
	void SetPortalPos();			

	void SaveScore();

	Point GetStarPos();	
	Point GetPoisonPos();
	Point GetItemPos();
	std::vector<Point> GetPortalPos();
				
	std::list<Point>& GetBody();	
	Point EraseTail();				

	Point head();					
	Point tail();					
};

#endif