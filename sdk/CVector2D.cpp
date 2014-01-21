#include "CVector2D.h"

CVector2D::CVector2D()
{
	((void (__thiscall *)(CVector2D *))0x43E0E0)(this);
}

CVector2D::CVector2D(float x, float y)
{
	((void (__thiscall *)(CVector2D *, float, float))0x420840)(this, x, y);
}

float CVector2D::Magnitude()
{
	return ((float (__thiscall *)(CVector2D *))0x420860)(this);
}

void CVector2D::operator=(CVector2D const& right)
{
	((void (__thiscall *)(CVector2D *, CVector2D const&))0x43E110)(this, right);
}