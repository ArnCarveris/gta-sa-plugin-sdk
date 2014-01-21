#pragma once
#include "sa_sdk.h"
#include "CEntity.h"
#include "CColPoint.h"
#include "CVector.h"
#include "CQuaternion.h"
#include "CCutsceneShadow.h"
#include "CRepeatSector.h"

#pragma pack(push, 4)
class PLUGIN_API CPhysical : public CEntity
{
public:
	Int32 field_38;
	UInt32 m_dwLastCollisionTime;
	/* https://code.google.com/p/mtasa-blue/source/browse/tags/1.3.4/MTA10/game_sa/CPhysicalSA.h */
	UInt32 b0x01 : 1; // 64
	UInt32 m_bApplyGravity : 1;
	UInt32 m_bDisableFriction : 1;
	UInt32 m_bCollidable : 1; 
	UInt32 b0x10 : 1;
	UInt32 m_bDisableMovement : 1;
	UInt32 b0x40 : 1;
	UInt32 b0x80 : 1;
	UInt32 m_bSubmergedInWater : 1; // 65
	UInt32 m_bOnSolidSurface : 1;
	UInt32 m_bBroken : 1;
	UInt32 b0x800 : 1; // ref @ 0x6F5CF0
	UInt32 b0x1000 : 1;//
	UInt32 b0x2000 : 1;//
	UInt32 b0x4000 : 1;//
	UInt32 b0x8000 : 1;//
	UInt32 b0x10000 : 1; // 66
	UInt32 b0x20000 : 1; // ref @ CPhysical__processCollision
	UInt32 m_bBulletProof : 1;
	UInt32 m_bFireProof : 1;
	UInt32 m_bCollisionProof : 1;
	UInt32 m_bMeeleProof : 1;
	UInt32 m_bInvulnerable : 1;
	UInt32 m_bExplosionProof : 1;
	UInt32 b0x1000000 : 1; // 67
	UInt32 m_bAttachedToEntity : 1;
	UInt32 b0x4000000 : 1;
	UInt32 m_bTouchingWater : 1;
	UInt32 m_bEnableCollision : 1;
	UInt32 m_bDestroyed : 1;
	UInt32 b0x40000000 : 1;
	UInt32 b0x80000000 : 1;
	CVector          m_vVelocity;
	CVector          m_vAngularVelocity;
	CVector          m_vAcceleration;
	CVector          m_vAngularAcceleration;
	CVector          m_vForce;
	CVector          m_vTorque;
	Float            m_fMass;
	Float            m_fTurnMass;
	Float            m_fVelocityFrequency;
	Float            m_fAirResistance;
	Float            m_fElasticity;
	Float            m_fBuoyancyConstant;
	CVector          m_vCentreOfMass;
	void            *m_pCollisionList;
	void            *m_pMovingList;
	Int8 field_B8;
	UInt8  m_nNumEntitiesCollided;
	UInt8  m_nContactSurface;
	Int8 field_BB;
	CEntity         *m_apCollidedEntities[6];
	__int32 field_D4;
	Float            m_fDamageIntensity;
	CEntity         *m_pDamageEntity;
	CVector          m_vLastCollisionDirection;
	CVector          m_vLastCollisionPosn;
	UInt16 m_wDamagedPart;
	Int16 field_FA;
	class CPhysical *m_pAttachedTo;
	CVector          m_vAttachOffset;
	CVector          m_vAttachRotation;
	CQuaternion      m_qAttachRotation;
	CEntity         *m_pEntityIgnoredCollision;
	float            m_fContactSurfaceBrightness;
	Int32 field_130;
	CCutsceneShadow *m_pShadowData;

	CPhysical();
	~CPhysical();

	// originally virtual functions
	void ProcessEntityCollision(CEntity *entity, CColPoint *point);

	// static functions
	static void PlacePhysicalRelativeToOtherPhysical(CPhysical *physical1, CPhysical *physical2, CVector offset);

	// functions
	/*void Remove();
	void RemoveAndAdd();
	void AddToMovingList();
	void RemoveFromMovingList();
	void SetDamagedPieceRecord(float damageIntensity, CEntity *damagingEntity, CColPoint &colPoint, float distanceMult);
	void ApplyMoveForce(CVector moveForce);
	void ApplyTurnForce(CVector posn, CVector velocity);
	void ApplyForce(CVector posn, CVector velocity, bool flag);
	CVector GetSpeed(CVector direction);
	void ApplyMoveSpeed();
	void ApplyTurnSpeed();
	void ApplyGravity();
	void ApplyFrictionMoveForce(CVector moveForce);
	void ApplyFrictionTurnForce(CVector posn, CVector velocity);
	void ApplyFrictionForce(CVector posn, CVector velocity);
	void SkipPhysics();
	void AddCollisionRecord(CEntity *collidedEntity);
	Bool GetHasCollidedWith(CEntity *entity);
	Bool GetHasCollidedWithAnyObject();
	Bool ApplyCollision(CEntity *entity, CColPoint &colPoint, float &arg3);
	Bool ApplySoftCollision(CEntity *entity, CColPoint &colPoint, float &arg3);
	Bool ApplySpringCollision(float arg1, CVector &arg2, CVector &arg3, float arg4, float arg5, float &arg6);
	Bool ApplySpringCollisionAlt(float arg1, CVector &arg2, CVector &arg3, float arg4, float arg5,CVector & arg6, float &arg7);
	Bool ApplySpringDampening(float arg1, float arg2, CVector &arg3, CVector &arg4, CVector &arg5);
	Bool ApplySpringDampeningOld(float arg1, float arg2, CVector &arg3, CVector &arg4, CVector &arg5);
	void RemoveRefsToEntity(CEntity *entity);
	void DettachEntityFromEntity(float x, float y,float z, bool useCollision);
	void DettachAutoAttachedEntity();
	float GetLightingFromCol(bool flag);
	float GetLightingTotal();
	Bool CanPhysicalBeDamaged(eWeaponType weapon, unsigned char *arg2);
	void ApplyAirResistance();
	Bool ApplyCollisionAlt(CEntity *entity, CColPoint &colPoint, float &arg3, CVector &arg4, CVector &arg5);
	Bool ApplyFriction(float arg1, CColPoint &colPoint);
	Bool ApplyFriction(CPhysical *physical, float arg2, CColPoint &colPoint);
	Bool ProcessShiftSectorList(int sectorX, int sectorY);
	float ApplyScriptCollision(CVector arg1, float arg2, float arg3, CVector *arg4);
	void PositionAttachedEntity();
	void ApplySpeed();
	void UnsetIsInSafePosition();
	void ApplyFriction();
	Bool ApplyCollision(CPhysical *physical, CColPoint &colPoint, float &arg3, float &arg4);
	Bool ApplySoftCollision(CPhysical *physical, CColPoint &colPoint, float &arg3, float &arg4);
	Bool ProcessCollisionSectorList(int sectorX, int sectorY);
	Bool ProcessCollisionSectorList_SimpleCar(CRepeatSector *sector);
	class CPhysical *AttachEntityToEntity(CEntity *entity, CVector offset, CVector rotation);
	class CPhysical *AttachEntityToEntity(CEntity *entity, CVector *offset, RtQuat *rotation);
	Bool CheckCollision();
	Bool CheckCollision_SimpleCar();*/
};
#pragma pack(pop)

VALIDATE_SIZE(CPhysical, 0x138);