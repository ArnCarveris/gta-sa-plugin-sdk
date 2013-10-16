#include "CPhysical.h"

NOINLINE CPhysical::CPhysical()
{
	PREPARE_FOR_REDIRECTION();
	//((void (__thiscall *)(CPhysical *))0x542260)(this);
}

NOINLINE CPhysical::~CPhysical()
{
	PREPARE_FOR_REDIRECTION();
	//((void (__thiscall *)(CPhysical *))0x542450)(this);
}

void CPhysical::ProcessEntityCollision(CEntity *entity, CColPoint *point)
{
	((void (__thiscall *)(CEntity *, CColPoint *))this->vtable[22])(this, point);
}

