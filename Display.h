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
	void Print_Title();										// Title ���
	void Print_GameOver();									// Game Over ���
	void Print_Wall();										// ���� �� �׸���
	void Print_Food(Point pos);								// �� �׸���
	void Print_Snake(Snake snake);							// ������ũ �׸���
	void Print_Pause();										// �Ͻ� ���� ȭ�� �׸���
	void Erase_Pause();										// �Ͻ� ���� ȭ�� �����
	void Print_Ranking();

	void GetBoard(int(*boa)[GBOARD_WIDTH + 2]);				// ���� ���� ��������

	void Print_Prompt(std::string str);						// ��� ���
	void Print_Score(Snake snake);							// ���� ���
};

#endif