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
	Point starPos;					// 별의 위치 좌표
	int direction;					// 스네이크 방향
	int level;						// 현재 레벨
	int score;						// 현재 점수
private:
	void Move_UP();
	void Move_Down();
	void Move_Left();
	void Move_Right();
public:
	Snake();

	void Init();					// 스네이크 길이, 시작 위치 초기화
	void Set_Direction(int key);	// 스네이크 방향 지정
	void Move();					// 스네이크 이동
	bool Is_Bitten();				// 자기 몸을 물었을 때
	bool Is_Collistion();			// 벽과 충돌 했을 때
	int GetDirection();				// 현재 스네이크의 방향 가져오기
	int& GetLevel();				// 현재 레벨 가져오기
	int& GetScore();
	void SetStarPos();				// 별 위치 지정

	void SaveScore();

	Point GetStarPos();				// 별 위치 가져오기
	std::list<Point>* GetBody();	// 스네이크 몸의 좌표 가져오기
	Point EraseTail();				// 꼬리 지우기

	Point head();					// 머리 좌표 반환
	Point tail();					// 꼬리 좌표 반환
};

#endif