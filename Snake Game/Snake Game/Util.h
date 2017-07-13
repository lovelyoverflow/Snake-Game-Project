#ifndef __UTIL_H_
#define __UTIL_H_

#include "Common.h"
#include "Point.h"

class Util
{
public:
	void CursorUtil_Set(int x, int y);		// 커서 위치를 x, y 좌표로 이동
	Point CursorUtil_Get(void);				// 현재 커서 위치를 불러옴
	void CursorUtil_Hide(void);				// 커서를 노출하지 않게 함
	void SetColorText(int color);			// 텍스트 색 조정
};

#endif