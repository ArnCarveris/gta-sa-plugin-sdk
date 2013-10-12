#include "CEntity.h"

NOINLINE CEntity::CEntity()
{
	PREPARE_FOR_REDIRECTION();
	//((void (__thiscall *)(CEntity *))0x532A90)(this);
}

NOINLINE CEntity::~CEntity()
{
	PREPARE_FOR_REDIRECTION();
	//((void (__thiscall *)(CEntity *))0x535E90)(this);
}

void CEntity::Add(CRect &rect)
{
	((void (__thiscall *)(CEntity *, CRect &))0x5347D0)(this, rect);
}

void CEntity::Add()
{
	((void (__thiscall *)(CEntity *))0x533020)(this);
}

void CEntity::Remove()
{
	((void (__thiscall *)(CEntity *))0x534AE0)(this);
}

void CEntity::SetIsStatic(bool isStatic)
{
	((void (__thiscall *)(CEntity *, bool))0x403E20)(this, isStatic);
}

void CEntity::SetModelIndex(unsigned int index)
{
	((void (__thiscall *)(CEntity *, unsigned int))0x532AE0)(this, index);
}

void CEntity::SetModelIndexNoCreate(unsigned int index)
{
	((void (__thiscall *)(CEntity *, unsigned int))0x533700)(this, index);
}