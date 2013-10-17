#pragma once

#include "plugin\plugin.h"
#include "CDummyAudio.h"
#include "CSound.h"

#pragma pack(push, 1)
class PLUGIN_API C85F438 : public CDummyAudio
{
	__int16 m_wBankSlotId;
	__int16 m_wSoundType;
	__int32 field_80;
	__int32 field_84;
	__int16 word88;
	__int16 f8A;
	__int32 field_8C;
	__int32 field_90;
	__int32 field_94;
	__int32 field_98;
	__int32 field_9C;
	CSound *dwordA0;
	CSound *dwordA4;
};

VALIDATE_SIZE(C85F438, 0xA8);