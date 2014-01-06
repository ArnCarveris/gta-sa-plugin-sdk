#include "CVehicle.h"

void CVehicle::SetComponentVisibility(RwFrame *component, unsigned int visibilityState)
{
	((void (__thiscall *)(CVehicle *, RwFrame *, unsigned int))0x6D2700)(this, component, visibilityState);
}