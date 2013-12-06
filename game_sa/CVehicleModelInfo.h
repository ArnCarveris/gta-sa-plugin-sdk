#pragma once
#include "plugin\plugin.h"
#include "CClumpModelInfo.h"

#pragma pack(push, 4)
class PLUGIN_API CVehicleModelInfo : public CClumpModelInfo
{
public:
	

	// vtable



	// static functions

	

	//

	CVehicleModelInfo();
	~CVehicleModelInfo();
};
#pragma pack(pop)

VALIDATE_SIZE(CVehicleModelInfo, 0x24);