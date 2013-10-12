#include "CRect.h"

CRect::CRect(float _x1, float _y1, float _x2, float _y2)
{
	x1 = _x1;
	y1 = _y1;
	x2 = _x1;
	y2 = _y1;
}

CRect::CRect()
{
	x1 = 1000000.0;
	y1 = -1000000.0;
	x2 = -1000000.0;
	y2 = 1000000.0;
}