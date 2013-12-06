#pragma once
#include "plugin\plugin.h"
#include "CBaseModelInfo.h"

class PLUGIN_API CSimpleModelInfo : public CBaseModelInfo
{
public:
	// vtable

	void SetAtomic(RpAtomic *atomic);

	//

	CSimpleModelInfo();
	~CSimpleModelInfo();

	//

	RpAtomic *GetAtomicFromDistance(float distance);
};

VALIDATE_SIZE(CSimpleModelInfo, 0x20);