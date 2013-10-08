#include "CCoors.h"

NOINLINE CCoors::CCoors()
{
	((void (__thiscall *)(CCoors *))0x54F0C0)(this);
}

CCoors::~CCoors()
{
	((void (__thiscall *)(CCoors *))0x54E8E0)(this);
}

CCoors *CCoors::GetPrev()
{
	return ((CCoors * (__thiscall *)(CCoors *))0x54E8B0)(this);
}

CCoors *CCoors::GetNext()
{
	return ((CCoors * (__thiscall *)(CCoors *))0x54E8C0)(this);
}

void CCoors::SetScale(float scale)
{
	((void (__thiscall *)(CCoors *, float))0x54F050)(this, scale);
}

void CCoors::SetTranslate(CVector *translation)
{
	((void (__thiscall *)(CCoors *, CVector *))0x54F070)(this, translation);
}