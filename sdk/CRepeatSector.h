#pragma once
#include "sa_sdk.h"
#include "CPtrList.h"

#pragma pack(push, 4)
class PLUGIN_API CRepeatSector
{
public:
	CPtrList m_VehiclesList;
	CPtrList m_PedsList;
	CPtrList m_ObjectsList;
};
#pragma pack(pop)

VALIDATE_SIZE(CRepeatSector, 0xC);