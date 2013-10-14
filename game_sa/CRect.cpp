#include "CRect.h"

CRect::CRect(float x1, float y1, float x2, float y2)
{
	((void (__thiscall *)(CRect *, float, float, float, float))0x4041C0)(this, x1, y1, x2, y2);
}

CRect::CRect()
{
	((void (__thiscall *)(CRect *))0x4041E0)(this);
}

bool CRect::IsFlipped()
{
	return ((bool (__thiscall *)(CRect *))0x404190)(this);
}