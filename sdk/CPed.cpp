#include "CPed.h"

NOINLINE CPed::CPed(ePedType type)
{
	PREPARE_FOR_REDIRECTION();
	//((void (__thiscall *)(CPed *, ePedType))0x5E8030)(this, type);
}

NOINLINE CPed::~CPed()
{
	PREPARE_FOR_REDIRECTION();
	//((void (__thiscall *)(CPed *))0x5E8620)(this);
}

void *CPed::operator new(unsigned int size)
{
	return ((void *(__cdecl *)(unsigned int))0x5E4720)(size);
}

void CPed::operator delete(void *object)
{
	((void (__cdecl *)(void *))0x5E4760)(object);
}

void CPed::SetMoveAnim()
{
	((void (__thiscall *)(CPed *))this->vtable[23])(this);
}

bool CPed::Save()
{
	return ((bool (__thiscall *)(CPed *))this->vtable[24])(this);
}

bool CPed::Load()
{
	return ((bool (__thiscall *)(CPed *))this->vtable[25])(this);
}

void CPed::RemoveWeaponAnims(int weaponSlot, float blenDelta)
{
	((void (__thiscall *)(CPed *, int, float))0x5F0250)(this, weaponSlot, blenDelta);
}

unsigned char CPed::GetWeaponSkill(eWeaponType weaponType)
{
	return ((unsigned char (__thiscall *)(CPed *, eWeaponType))0x5E3B60)(this, weaponType);
}