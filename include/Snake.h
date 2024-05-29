#ifndef __SNAKE_H_
#define __SNAKE_H_

#include <list>
#include "Point.h"

#define START_SNAKE_POS_X	70
#define START_SNAKE_POS_Y	25

class Snake
{
private:
	std::list<Point> body;
	Point starPos;					// ���� ��ġ ��ǥ
	int direction;					// ������ũ ����
	int level;						// ���� ����
	int score;						// ���� ����
private:
	void Move_UP();
	void Move_Down();
	void Move_Left();
	void Move_Right();
public:
	Snake();

	void Init();					// ������ũ ����, ���� ��ġ �ʱ�ȭ
	void Set_Direction(int key);	// ������ũ ���� ����
	void Move();					// ������ũ �̵�
	bool Is_Bitten();				// �ڱ� ���� ������ ��
	bool Is_Collistion();			// ���� �浹 ���� ��
	int GetDirection();				// ���� ������ũ�� ���� ��������
	int& GetLevel();				// ���� ���� ��������
	int& GetScore();
	void SetStarPos();				// �� ��ġ ����

	void SaveScore();

	Point GetStarPos();				// �� ��ġ ��������
	std::list<Point>* GetBody();	// ������ũ ���� ��ǥ ��������
	Point EraseTail();				// ���� �����

	Point head();					// �Ӹ� ��ǥ ��ȯ
	Point tail();					// ���� ��ǥ ��ȯ
};

#endif