#pragma once

#include "plugin\plugin.h"

#pragma pack(push, 4)
class PLUGIN_API CPad
{
public:
	__int8 field_0[0x134];

	bool CycleWeaponRightJustDown();
	bool CycleWeaponLeftJustDown();
};
#pragma pack(pop)

VALIDATE_SIZE(CPad, 0x134);