#pragma once

#include "plugin\plugin.h"
#include "CVector.h"

#pragma pack(push, 1)
class PLUGIN_API CSound
{
public:
	__int16 m_wBankSlotId;
	__int16 m_wSoundIdInSlot;
	void *m_pBaseAudio;
	class CEntity *m_pEntity;
	unsigned __int32 m_dwEvent;
	float m_fMaxVolume;
	float m_fVolume;
	float field_18;
	float m_fSpeed;
	float field_20;
	CVector m_vLastPosn;
	CVector m_vCurrPosn;
	unsigned __int32 m_dwLastFrameUpdate;
	unsigned __int32 m_dwLastTime;
	unsigned __int32 m_dwCurrTime;
	float m_fLastDistance;
	float m_fCurrDistance;
	float field_50;
	__int8 field_54;
	__int8 field_55;
	__int16 m_nFlags;
	__int16 m_wIsUsed;
	__int16 field_5A;
	__int16 field_5C;
	__int16 field_5E;
	float field_60;
	float field_64;
	__int16 field_68;
	__int8 field_6A[2];
	float field_6C;
	__int16 field_70;
	__int16 field_72;
};
#pragma pack(pop)

VALIDATE_SIZE(CSound, 0x74);