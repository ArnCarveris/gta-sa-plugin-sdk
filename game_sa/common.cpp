#include "common.h"

CVector FindPlayerCoors(int playerId)
{
	return ((CVector (__cdecl *)(int))0x56E010)(playerId);
}

CVector const& FindPlayerSpeed(int playerId)
{
	return ((CVector const& (__cdecl *)(int))0x56E090)(playerId);
}

CEntity * FindPlayerEntity(int playerId)
{
	return ((CEntity *(__cdecl *)(int))0x56E120)(playerId);
}

CVector const& FindPlayerCentreOfWorld(int playerId)
{
	return ((CVector const& (__cdecl *)(int))0x56E250)(playerId);
}

CVector const& FindPlayerCentreOfWorld_NoSniperShift(int playerId)
{
	return ((CVector const& (__cdecl *)(int))0x56E320)(playerId);
}

CVector FindPlayerCentreOfWorld_NoInteriorShift(int playerId)
{
	return ((CVector (__cdecl *)(int))0x56E400)(playerId);
}

float FindPlayerHeading(int playerId)
{
	return ((float (__cdecl *)(int))0x56E450)(playerId);
}

float FindPlayerHeight()
{
	return ((float (__cdecl *)())0x56E520)();
}

CPed * FindPlayerPed(int playerId)
{
	return ((CPed *(__cdecl *)(int))0x56E210)(playerId);
}