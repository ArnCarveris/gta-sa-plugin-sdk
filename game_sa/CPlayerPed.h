#pragma once

#include "plugin\plugin.h"
#include "CPed.h"

#pragma pack(push, 4)
class PLUGIN_API CPlayerPed : public CPed
{
public:
	CPed *m_pPlayerTargettedPed;
	__int32 field_7A0;
};
#pragma pack(pop)

VALIDATE_SIZE(CPlayerPed, 0x7A4);