#ifndef __UTIL_H_
#define __UTIL_H_

#include "Common.h"
#include "Point.h"

class Util
{
public:
	void CursorUtil_Set(int x, int y);		// Ŀ�� ��ġ�� x, y ��ǥ�� �̵�
	Point CursorUtil_Get(void);				// ���� Ŀ�� ��ġ�� �ҷ���
	void CursorUtil_Hide(void);				// Ŀ���� �������� �ʰ� ��
	void SetColorText(int color);			// �ؽ�Ʈ �� ����
};

#endif