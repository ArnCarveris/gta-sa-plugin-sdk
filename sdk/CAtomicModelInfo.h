#pragma once
#include "sa_sdk.h"
#include "CBaseModelInfo.h"

class PLUGIN_API CAtomicModelInfo : public CBaseModelInfo
{
public:
	// vtable

	void SetAtomic(RpAtomic *atomic);

	//

	CAtomicModelInfo();
	~CAtomicModelInfo();

	//

	RpAtomic *GetAtomicFromDistance(float distance);
};

VALIDATE_SIZE(CAtomicModelInfo, 0x20);