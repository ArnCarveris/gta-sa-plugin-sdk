#include "CPad.h"

bool CPad::CycleWeaponRightJustDown()
{
	return ((bool (__thiscall *)(CPad *))0x540640)(this);
}

bool CPad::CycleWeaponLeftJustDown()
{
	return ((bool (__thiscall *)(CPad *))0x540610)(this);
}