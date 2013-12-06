#include "CVector2D.h"

float CVector2D::Magnitude()
{
	return ((float (__thiscall *)(CVector2D *))0x406D50)(this);
}

void CVector2D::operator-=(const CVector2D& right)
{
	((void (__thiscall *)(CVector2D *, const CVector2D &right))0x406D70)(this, right);
}