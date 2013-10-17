#pragma once

#include "plugin\plugin.h"
#include "CPed.h"
#include "eCopType.h"

#pragma pack(push, 4)
class PLUGIN_API CCopPed : public CPed
{
	__int32 field_79C;
	eCopType       m_dwCopType;
	__int32 field_7A4;
	class CCopPed *m_pCopPartner;
	CPed          *m_pCriminalPeds[5];
	__int8 field_7C0;
};
#pragma pack(pop)

VALIDATE_SIZE(CCopPed, 0x7C4);