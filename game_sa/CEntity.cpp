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

void CEntity::UpdateRwFrame()
{
	((void (__thiscall *)(CEntity *))0x532B00)(this);
}

void CEntity::UpdateRpHAnim()
{
	((void (__thiscall *)(CEntity *))0x532B20)(this);
}

bool CEntity::HasPreRenderEffects()
{
	return ((bool (__thiscall *)(CEntity *))0x532B70)(this);
}

void CEntity::ModifyMatrixForPoleInWind()
{
	((void (__thiscall *)(CEntity *))0x532DB0)(this);
}

void CEntity::PreRenderForGlassWindow()
{
	((void (__thiscall *)(CEntity *))0x533240)(this);
}

void CEntity::SetRwObjectAlpha(int alpha)
{
	((void (__thiscall *)(CEntity *, int))0x5332C0)(this, alpha);
}

CVector CEntity::GetSlotmachineWheelPosn(unsigned int wheelId)
{
	return ((CVector (__thiscall *)(CEntity *, unsigned int))0x533380)(this, wheelId);
}

void CEntity::Initialise2dEffects()
{
	((void (__thiscall *)(CEntity *))0x533790)(this);
}

void CEntity::Destroy2dEffects()
{
	((void (__thiscall *)(CEntity *))0x533BF0)(this);
}

void CEntity::AttachToRwObject(RwObject *object, bool moveToObject)
{
	((void (__thiscall *)(CEntity *, RwObject *, bool))0x533ED0)(this, object, moveToObject);
}

CVector CEntity::GetBoundCentre()
{
	return ((CVector (__thiscall *)(CEntity *))0x534250)(this);
}

void CEntity::GetBoundCentre(CVector& out)
{
	((void (__thiscall *)(CEntity *, CVector&))0x534290)(this, out);
}

bool CEntity::GetIsTouching(CEntity *entity)
{
	return ((bool (__thiscall *)(CEntity *, CEntity *))0x5343F0)(this, entity);
}

bool CEntity::GetIsTouching(CVector const &posn, float radius)
{
	return ((bool (__thiscall *)(CEntity *, CVector const &, float))0x5344B0)(this, posn, radius);
}

bool CEntity::GetIsOnScreen()
{
	return ((bool (__thiscall *)(CEntity *))0x534540)(this);
}

void CEntity::ModifyMatrixForTreeInWind()
{
	((void (__thiscall *)(CEntity *))0x534E90)(this);
}

void CEntity::ModifyMatrixForBannerInWind()
{
	((void (__thiscall *)(CEntity *))0x535040)(this);
}

CColModel *CEntity::GetColModel()
{
	return ((CColModel *(__thiscall *)(CEntity *))0x535300)(this);
}

float CEntity::GetDistanceFromCentreOfMassToBaseOfModel()
{
	return ((float (__thiscall *)(CEntity *))0x536BE0)(this);
}

void CEntity::CleanUpOldReference(CEntity**pEntity)
{
	((void (__thiscall *)(CEntity *, CEntity**))0x571A00)(this, pEntity);
}

void CEntity::ResolveReferences()
{
	((void (__thiscall *)(CEntity *))0x571A40)(this);
}

void CEntity::PruneReferences()
{
	((void (__thiscall *)(CEntity *))0x571A90)(this);
}

void CEntity::RegisterReference(CEntity**pEntity)
{
	((void (__thiscall *)(CEntity *, CEntity**))0x571B70)(this, pEntity);
}

void CEntity::ProcessLightsForEntity()
{
	((void (__thiscall *)(CEntity *))0x6FC7A0)(this);
}

void CEntity::RemoveEscalator()
{
	((void (__thiscall *)(CEntity *))0x717900)(this);
}

bool CEntity::IsEntityOccluded()
{
	return ((bool (__thiscall *)(CEntity *))0x71FAE0)(this);
}