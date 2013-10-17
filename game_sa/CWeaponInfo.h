#pragma once

#include "plugin\plugin.h"
#include "eWeaponType.h"
#include "CVector.h"

#define MAX_WEAPON_INFOS 80
#define MAX_WEAPON_NAMES 50

#pragma pack(push, 4)
class PLUGIN_API CWeaponInfo
{
	eWeaponType m_eWeaponType;
	float m_fTargetRange;
	float m_fWeaponRange;
	__int32 m_dwModelId1;
	__int32 m_dwModelId2;
	unsigned __int32 m_dwSlot;
	unsigned __int32 m_dwFlags;
	unsigned __int32 m_dwAssocGroupId;
	unsigned __int16 m_wAmmoClip;
	unsigned __int16 m_wDamage;
	CVector m_vFireOffset;
	unsigned __int32 m_dwSkillLevel;
	unsigned __int32 m_dwReqStatLevelToGetThisWeaponSkilLevel;
	float m_fAccuracy;
	float m_fMoveSpeed;
	float m_fAnimLoopStart;
	float m_fAnimLoopEnd;
	unsigned __int32 m_dwAnimLoopFire;
	unsigned __int32 m_dwAnimLoop2Start;
	unsigned __int32 m_dwAnimLoop2End;
	unsigned __int32 m_dwAnimLoop2Fire;
	float m_fBreakoutTime;
	float m_fSpeed;
	float m_fRadius;
	float m_fLifespan;
	float m_fSpread;
	unsigned __int8 m_nAssocGroupId2;
	unsigned __int8 field_6D;
	unsigned __int8 m_nBaseCombo;
	unsigned __int8 m_nNumCombos;

	// functions
	CWeaponInfo();
	~CWeaponInfo();

	// static variables

	// weapon names array. Count: MAX_WEAPON_NAMES(50)
	static char *ms_aWeaponNames;

	// static functions

	// load weapon data file
	static void LoadWeaponData();
	// get weapon info for this type and with this skill
	static CWeaponInfo *GetWeaponInfo(eWeaponType weaponType, unsigned char skill);
	// get weapon type by name
	static eWeaponType FindWeaponType(char *name);
	// initialisation
	static void Initialise();
	// closing
	static void Shutdown();
};
#pragma pack(pop)

VALIDATE_SIZE(CWeaponInfo, 0x70);

// list of weapon infos. Count: MAX_WEAPON_INFOS (80)
extern PLUGIN_API CWeaponInfo *aWeaponInfo;