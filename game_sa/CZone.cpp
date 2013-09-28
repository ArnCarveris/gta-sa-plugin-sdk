#include "CZone.h"

// Returns pointer to GXT name string.
const char* CZone::GetTranslatedName()
{
	return ( ( const char *(__thiscall* )(CZone *) )FUNC_CZone__GetTranslatedName)(this);
}