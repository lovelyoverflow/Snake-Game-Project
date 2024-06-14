#ifndef __UTIL_H_
#define __UTIL_H_

#include "point.hpp"
#include "constant.hpp"

#include <random>

class Util
{
private:
	std::random_device rd;
public:
	void CursorUtil_Set(int x, int y);						// 커서 위치 x, y로 지정
	Point CursorUtil_Get(void);								// 현재 커서 위치 반환
	void CursorUtil_Hide(void);								// 커서 숨기기 전용으로 만든건데 안씀
	void CursorUtil_Print(int x, int y, const char* str);	// x, y좌표에 str 출력
	void SetColorText(Color color);							// 다음에 출력할 문자 color 지정
	bool kbhit(void);										// 

	int Get_Random(int s, int e);							// s ~ e 범위의 랜덤 수 반환
};

#endif