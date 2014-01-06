#pragma once
#include "plugin\plugin.h"
#include "CEntity.h"
#include "CColPoint.h"
#include "CVector.h"
#include "CQuaternion.h"
#include "CCutsceneShadow.h"

#pragma pack(push, 4)
class PLUGIN_API CPhysical : public CEntity
{
public:
	__int32 field_38;
	unsigned __int32 m_dwLastCollisionTime;
	/* https://code.google.com/p/mtasa-blue/source/browse/tags/1.3.4/MTA10/game_sa/CPhysicalSA.h */
	unsigned __int32 b0x01 : 1; // 64
	unsigned __int32 m_bApplyGravity : 1;
	unsigned __int32 m_bDisableFriction : 1;
	unsigned __int32 m_bCollidable : 1; 
	unsigned __int32 b0x10 : 1;
	unsigned __int32 m_bDisableMovement : 1;
	unsigned __int32 b0x40 : 1;
	unsigned __int32 b0x80 : 1;
	unsigned __int32 m_bSubmergedInWater : 1; // 65
	unsigned __int32 m_bOnSolidSurface : 1;
	unsigned __int32 m_bBroken : 1;
	unsigned __int32 b0x800 : 1; // ref @ 0x6F5CF0
	unsigned __int32 b0x1000 : 1;//
	unsigned __int32 b0x2000 : 1;//
	unsigned __int32 b0x4000 : 1;//
	unsigned __int32 b0x8000 : 1;//
	unsigned __int32 b0x10000 : 1; // 66
	unsigned __int32 b0x20000 : 1; // ref @ CPhysical__processCollision
	unsigned __int32 m_bBulletProof : 1;
	unsigned __int32 m_bFireProof : 1;
	unsigned __int32 m_bCollisionProof : 1;
	unsigned __int32 m_bMeeleProof : 1;
	unsigned __int32 m_bInvulnerable : 1;
	unsigned __int32 m_bExplosionProof : 1;
	unsigned __int32 b0x1000000 : 1; // 67
	unsigned __int32 m_bAttachedToEntity : 1;
	unsigned __int32 b0x4000000 : 1;
	unsigned __int32 m_bTouchingWater : 1;
	unsigned __int32 m_bEnableCollision : 1;
	unsigned __int32 m_bDestroyed : 1;
	unsigned __int32 b0x40000000 : 1;
	unsigned __int32 b0x80000000 : 1;
	CVector          m_vVelocity;
	CVector          m_vAngularVelocity;
	CVector          m_vAcceleration;
	CVector          m_vAngularAcceleration;
	CVector          m_vForce;
	CVector          m_vTorque;
	float            m_fMass;
	float            m_fTurnMass;
	float            m_fVelocityFrequency;
	float            m_fAirResistance;
	float            m_fElasticity;
	float            m_fBuoyancyConstant;
	CVector          m_vCentreOfMass;
	void            *m_pCollisionList;
	void            *m_pMovingList;
	__int8 field_B8;
	unsigned __int8  m_nNumEntitiesCollided;
	unsigned __int8  m_nContactSurface;
	__int8 field_BB;
	CEntity         *m_apCollidedEntities[6];
	__int32 field_D4;
	float            m_fDamageIntensity;
	CEntity         *m_pDamageEntity;
	CVector          m_vLastCollisionDirection;
	CVector          m_vLastCollisionPosn;
	unsigned __int16 m_wDamagedPart;
	__int16 field_FA;
	class CPhysical *m_pAttachedTo;
	CVector          m_vAttachOffset;
	CVector          m_vAttachRotation;
	CQuaternion      m_qAttachRotation;
	CEntity         *m_pEntityIgnoredCollision;
	float            m_fContactSurfaceBrightness;
	__int32 field_130;
	CCutsceneShadow *m_pShadowData;

	CPhysical();
	~CPhysical();

	// originally virtual functions
	void ProcessEntityCollision(CEntity *entity, CColPoint *point);

	// functions
	void RemoveAndAdd();
	void AddToMovingList();
	void RemoveFromMovingList();
	void ApplyMoveForce(float x, float y, float z);
	void ApplyTurnForce(float x1, float y1, float z1, float x2, float y2, float z2);
	// opcode 07D5
	void SetVelocityInDirection(float dir_x, float dir_y, float dir_z, float vel_x, float vel_y, float vel_z, bool unk);
	void ApplyMoveSpeed();
	void ApplyTurnSpeed();
	void ApplyFriction();
	void ApplyFrictionMoveForce(float x, float y, float z);
	void ApplyFrictionTurnForce(float x1, float y1, float z1, float x2, float y2, float z2);
	// stores entity into m_apCollidedEntities array.
	void AddCollisionRecord(CEntity *collidedEntity);
	// checks if physical is collided with this entity
	bool GetHasCollidedWith(CEntity *entity);
	// removes entity from m_apCollidedEntities array.
	void RemoveRefsToEntity(CEntity *entity);
	void ApplyAirResistance();
	class CPhysical *Attach(CPhysical *attachTo, float offsetX, float offsetY, float offsetZ, float rotX, float rotY, float rotZ);
	void Detach(float x, float y, float z, bool applyTurnForce);
};
#pragma pack(pop)

VALIDATE_SIZE(CPhysical, 0x138);