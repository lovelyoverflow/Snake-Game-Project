#ifndef __DISPLAY_H_
#define __DISPLAY_H_

#define GBOARD_WIDTH	50
#define GBOARD_HEIGHT	30

#define START_MAP_X		4
#define START_MAP_Y		2

#define TITLE_POS_X		30
#define TITLE_POS_Y		10

#include "Snake.h"
#include <string>
class Display
{
private:
	static int board[GBOARD_HEIGHT + 2][GBOARD_WIDTH + 2];
public:
	Display();
	void Print_Title();										// Title 출력
	void Print_GameOver();									// Game Over 출력
	void Print_Wall();										// 게임 벽 그리기
	void Print_Food(Point pos);								// 별 그리기
	void Print_Snake(Snake snake);							// 스네이크 그리기
	void Print_Pause();										// 일시 정지 화면 그리기
	void Erase_Pause();										// 일시 정지 화면 지우기
	void Print_Ranking();

	void GetBoard(int(*boa)[GBOARD_WIDTH + 2]);				// 게임 보드 가져오기

	void Print_Prompt(std::string str);						// 명령 출력
	void Print_Score(Snake snake);							// 점수 출력
};

#endif