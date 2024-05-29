#ifndef __UTIL_H_
#define __UTIL_H_

#include "point.hpp"

class Util
{
public:
	void CursorUtil_Set(int x, int y);		
	Point CursorUtil_Get(void);				
	void CursorUtil_Hide(void);				
	void SetColorText(int color);			
};

#endif