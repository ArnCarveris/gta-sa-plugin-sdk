#include "CSimpleModelInfo.h"

CSimpleModelInfo::CSimpleModelInfo()
{
	PREPARE_FOR_REDIRECTION();
	//((void (__thiscall *)(CSimpleModelInfo *))0x4C5540)(this);
}

CSimpleModelInfo::~CSimpleModelInfo()
{
	PREPARE_FOR_REDIRECTION();
	//((void (__thiscall *)(CSimpleModelInfo *))0x4C5590)(this);
}

void CSimpleModelInfo::SetAtomic(RpAtomic *atomic)
{
	((void (__thiscall *)(CSimpleModelInfo *, RpAtomic *))this->vtable[15])(this, atomic);
}

RpAtomic *CSimpleModelInfo::GetAtomicFromDistance(float distance)
{
	return ((RpAtomic *(__thiscall *)(CSimpleModelInfo *, float))0x4C44B0)(this, distance);
}