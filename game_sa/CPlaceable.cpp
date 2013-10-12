#include "CPlaceable.h"

NOINLINE CPlaceable::CPlaceable()
{
	PREPARE_FOR_REDIRECTION();
	//((void (__thiscall *)(CPlaceable *))0x54F1E0)(this);
}

NOINLINE CPlaceable::~CPlaceable()
{
	PREPARE_FOR_REDIRECTION();
	//((void (__thiscall *)(CPlaceable *))0x54F490)(this);
}

CVector CPlaceable::GetRightDirection()
{
	return ((CVector (__thiscall *)(CPlaceable *))0x41CC70)(this);
}

CVector CPlaceable::GetTopDirection()
{
	return ((CVector (__thiscall *)(CPlaceable *))0x41CCB0)(this);
}

CVector CPlaceable::GetAtDirection()
{
	return ((CVector (__thiscall *)(CPlaceable *))0x50E420)(this);
}

void CPlaceable::SetPosn(float x, float y, float z)
{
	((void (__thiscall *)(CPlaceable *, float, float, float))0x420B80)(this, x, y, z);
}

void CPlaceable::SetPosn(CVector const& posn)
{
	((void (__thiscall *)(CPlaceable *, CVector const&))0x4241C0)(this, posn);
}

void CPlaceable::SetOrientation(float x, float y, float z)
{
	((void (__thiscall *)(CPlaceable *, float, float, float))0x439A80)(this, x, y, z);
}

void CPlaceable::SetHeading(float heading)
{
	((void (__thiscall *)(CPlaceable *, float))0x43E0C0)(this, heading);
}

float CPlaceable::GetHeading()
{
	return ((float (__thiscall *)(CPlaceable *))0x441DB0)(this);
}

bool CPlaceable::IsWithinArea(float x1, float y1, float x2, float y2)
{
	return ((bool (__thiscall *)(CPlaceable *, float, float, float, float))0x54F200)(this, x1, y1, x2, y2);
}

bool CPlaceable::IsWithinArea(float x1, float y1, float z1, float x2, float y2, float z2)
{
	return ((bool (__thiscall *)(CPlaceable *, float, float, float, float, float, float))0x54F2B0)(this, x1, y1, z1, x2, y2, z2);
}

void CPlaceable::DeleteCoors()
{
	((void (__thiscall *)(CPlaceable *))0x54F3B0)(this);
}

void CPlaceable::CreateCoors()
{
	((void (__thiscall *)(CPlaceable *))0x54F4C0)(this);
}

void CPlaceable::CreateL1Coors()
{
	((void (__thiscall *)(CPlaceable *))0x54F560)(this);
}

void CPlaceable::SetCoors(CCoors *coors)
{
	((void (__thiscall *)(CPlaceable *, CCoors *))0x54F610)(this, coors);
}

void CPlaceable::TransformFromObjectSpace(CVector *out, CVector const& offset)
{
	((void (__thiscall *)(CPlaceable *, CVector *, CVector const&))0x5334F0)(this, out, offset);
}