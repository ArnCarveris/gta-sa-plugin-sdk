#include "CVehicle.h"

void CVehicle::SetComponentVisibility(RwFrame *component, unsigned int visibilityState)
{
	((void (__thiscall *)(CVehicle *, RwFrame *, unsigned int))0x6D2700)(this, component, visibilityState);
}

void CVehicle::SetComponentAtomicAlpha(RpAtomic *atomic, int alpha)
{
	((void (__cdecl *)(RpAtomic *, int))0x6D2960)(atomic, alpha);
}

void CVehicle::SetWindowOpenFlag(unsigned char door)
{
	((void (__thiscall *)(CVehicle *, unsigned char))0x6D3080)(this, door);
}

void CVehicle::ClearWindowOpenFlag(unsigned char door)
{
	((void (__thiscall *)(CVehicle *, unsigned char))0x6D30B0)(this, door);
}