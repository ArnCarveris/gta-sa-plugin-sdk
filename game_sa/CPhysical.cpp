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
	((void (__thiscall *)(CPhysical *, CEntity *, CColPoint *))this->vtable[22])(this, entity, point);
}

void CPhysical::RemoveAndAdd()
{
	((void (__thiscall *)(CPhysical *))0x542560)(this);
}

void CPhysical::AddToMovingList()
{
	((void (__thiscall *)(CPhysical *))0x542800)(this);
}

void CPhysical::RemoveFromMovingList()
{
	((void (__thiscall *)(CPhysical *))0x542860)(this);
}

void CPhysical::ApplyMoveForce(float x, float y, float z)
{
	((void (__thiscall *)(CPhysical *, float, float, float))0x5429F0)(this, x, y, z);
}

void CPhysical::ApplyTurnForce(float x1, float y1, float z1, float x2, float y2, float z2)
{
	((void (__thiscall *)(CPhysical *, float, float, float, float, float, float))0x542A50)(this, x1, y1, z1, x2, y2, z2);
}

void CPhysical::SetVelocityInDirection(float dir_x, float dir_y, float dir_z, float vel_x, float vel_y, float vel_z, bool unk)
{
	((void (__thiscall *)(CPhysical *, float, float, float, float, float, float, bool))0x542B50)(this, dir_x, dir_y, dir_z, vel_x, vel_y, vel_z, unk);
}

void CPhysical::ApplyMoveSpeed()
{
	((void (__thiscall *)(CPhysical *))0x542DD0)(this);
}

void CPhysical::ApplyTurnSpeed()
{
	((void (__thiscall *)(CPhysical *))0x542E20)(this);
}

void CPhysical::ApplyFriction()
{
	((void (__thiscall *)(CPhysical *))0x542FE0)(this);
}

void CPhysical::ApplyFrictionMoveForce(float x, float y, float z)
{
	((void (__thiscall *)(CPhysical *, float, float, float))0x5430A0)(this, x, y, z);
}

void CPhysical::ApplyFrictionTurnForce(float x1, float y1, float z1, float x2, float y2, float z2)
{
	((void (__thiscall *)(CPhysical *, float, float, float, float, float, float))0x543100)(this, x1, y1, z1, x2, y2, z2);
}

void CPhysical::AddCollisionRecord(CEntity *collidedEntity)
{
	((void (__thiscall *)(CPhysical *, CEntity *))0x543490)(this, collidedEntity);
}

bool CPhysical::GetHasCollidedWith(CEntity *entity)
{
	return ((bool (__thiscall *)(CPhysical *, CEntity *))0x543540)(this, entity);
}

void CPhysical::RemoveRefsToEntity(CEntity *entity)
{
	((void (__thiscall *)(CPhysical *, CEntity *))0x544280)(this, entity);
}

void CPhysical::ApplyAirResistance()
{
	((void (__thiscall *)(CPhysical *))0x544C40)(this);
}

CPhysical *CPhysical::Attach(CPhysical *attachTo, float offsetX, float offsetY, float offsetZ, float rotX, float rotY, float rotZ)
{
	return ((CPhysical *(__thiscall *)(CPhysical *, CPhysical *, float, float, float, float, float, float))0x54D570)(this, attachTo, offsetX, offsetY, offsetZ, rotX, rotY, rotZ);
}

void CPhysical::Detach(float x, float y, float z, bool applyTurnForce)
{
	((void (__thiscall *)(CPhysical *, float, float, float, bool))0x5442F0)(this, x, y, z, applyTurnForce);
}