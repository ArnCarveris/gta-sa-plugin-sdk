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

// vtable functions

void CEntity::Add(CRect &rect)
{
	((void (__thiscall *)(CEntity *, CRect &))this->vtable[1])(this, rect);
}

void CEntity::Add()
{
	((void (__thiscall *)(CEntity *))this->vtable[2])(this);
}

void CEntity::Remove()
{
	((void (__thiscall *)(CEntity *))this->vtable[3])(this);
}

void CEntity::SetIsStatic(bool isStatic)
{
	((void (__thiscall *)(CEntity *, bool))this->vtable[4])(this, isStatic);
}

void CEntity::SetModelIndex(unsigned int index)
{
	((void (__thiscall *)(CEntity *, unsigned int))this->vtable[5])(this, index);
}

void CEntity::SetModelIndexNoCreate(unsigned int index)
{
	((void (__thiscall *)(CEntity *, unsigned int))this->vtable[6])(this, index);
}

void CEntity::CreateRwObject()
{
	((void (__thiscall *)(CEntity *))this->vtable[7])(this);
}

void CEntity::DeleteRwObject()
{
	((void (__thiscall *)(CEntity *))this->vtable[8])(this);
}

CRect CEntity::GetBoundRect()
{
	return ((CRect (__thiscall *)(CEntity *))this->vtable[9])(this);
}

void CEntity::ProcessControl()
{
	((void (__thiscall *)(CEntity *))this->vtable[10])(this);
}

void CEntity::ProcessCollision()
{
	((void (__thiscall *)(CEntity *))this->vtable[11])(this);
}

void CEntity::ProcessShift()
{
	((void (__thiscall *)(CEntity *))this->vtable[12])(this);
}

bool CEntity::TestCollision()
{
	return ((bool (__thiscall *)(CEntity *))this->vtable[13])(this);
}

void CEntity::Teleport(CVector destination, bool resetRotation)
{
	((void (__thiscall *)(CEntity *, CVector, bool))this->vtable[14])(this, destination, resetRotation);
}

void CEntity::SpecialEntityPreCollisionStuff(CEntity *colEntity, bool unk1, unsigned char *unk2, unsigned char *unk3, unsigned char *unk4, unsigned char *unk5)
{
	((void (__thiscall *)(CEntity *, CEntity *, bool, unsigned char *, unsigned char *, unsigned char *, unsigned char *))this->vtable[15])(this, colEntity, unk1, unk2, unk3, unk4, unk5);
}

void CEntity::SpecialEntityCalcCollisionSteps(unsigned char *unk1, unsigned char *unk2)
{
	((void (__thiscall *)(CEntity *, unsigned char *, unsigned char *))this->vtable[16])(this, unk1, unk2);
}

void CEntity::PreRender()
{
	((void (__thiscall *)(CEntity *))this->vtable[17])(this);
}

void CEntity::Render()
{
	((void (__thiscall *)(CEntity *))this->vtable[18])(this);
}

bool CEntity::SetupLighting()
{
	return ((bool (__thiscall *)(CEntity *))this->vtable[19])(this);
}

void CEntity::RemoveLighting()
{
	((void (__thiscall *)(CEntity *))this->vtable[20])(this);
}

void CEntity::FlagToDestroyWhenNextProcessed()
{
	((void (__thiscall *)(CEntity *))this->vtable[21])(this);
}