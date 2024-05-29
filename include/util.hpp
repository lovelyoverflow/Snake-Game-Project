#ifndef __UTIL_H_
#define __UTIL_H_

#include "point.hpp"
#include "constant.hpp"

class Util
{
public:
	void CursorUtil_Set(int x, int y);		
	Point CursorUtil_Get(void);				
	void CursorUtil_Hide(void);				
	void SetColorText(Color color);			
};

#endif