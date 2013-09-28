#include "CTheZones.h"

// Variables
eLevelName& CTheZones::m_CurrLevel = *(eLevelName*)VAR_CTheZones__m_CurrLevel;

char* CTheZones::ExploredTerritoriesArray = (char*)VAR_CTheZones__ExploredTerritoriesArray;
DWORD& CTheZones::TotalNumberExploredTerritories = *(DWORD*)VAR_CTheZones__TotalNumberExploredTerritories;

WORD& CTheZones::TotalNumberOfMapZones = *(WORD*)VAR_CTheZones__TotalNumberOfInfoZones;
CZone* CTheZones::ZoneInfoArray = (CZone*)VAR_CTheZones__ZoneInfoArray;

WORD& CTheZones::TotalNumberOfInfoZones = *(WORD*)VAR_CTheZones__TotalNumberOfMapZones;
CZone* CTheZones::MapZoneArray = (CZone*)VAR_CTheZones__MapZoneArray;

// Functions
// Creates a zone
void CTheZones::CreateZone(const char *name, eZoneType type, float posX1, float posY1, float posZ1, float posX2, float posY2, float posZ2, eLevelName island, const char *GXT_key)
{
	((void (__cdecl*)(const char *, eZoneType, float, float, float, float, float, float, eLevelName island, const char *)) FUNC_CTheZones__CreateZone)
		(name, type, posX1, posY1, posZ1, posX2, posY2, posZ2, island, GXT_key);
}

// Returns eLevelName from position
eLevelName CTheZones::GetLevelFromPosition(CVector const* pPoint)
{
	return ((eLevelName (__cdecl*)(CVector const*)) FUNC_CTheZones__GetLevelFromPosition)(pPoint);
}

// Returns pointer to zone by index
CZone* CTheZones::GetInfoZone(WORD index)
{
	return ((CZone* (__cdecl*)(WORD)) FUNC_CTheZones__GetInfoZone)(index);
}

// Returns pointer to zone by index
CZone* CTheZones::GetMapZone(WORD index)
{
	return ((CZone* (__cdecl*)(WORD)) FUNC_CTheZones__GetMapZone)(index);
}

// Returns pointer to zone by index
WORD CTheZones::FindZoneByLabelAndReturnIndex(const char* name, int unk2)
{
	return ((WORD (__cdecl*)(const char*, int)) FUNC_CTheZones__FindZoneByLabelAndReturnIndex)(name, unk2);
}

// Returns pointer to zone by a point
CZone* CTheZones::FindZoneForPoint(const CVector& point, bool FindOnlyZonesType0)
{
	return ((CZone* (__cdecl*)(const CVector&, bool)) FUNC_CTheZones__FindZoneForPoint)(point, FindOnlyZonesType0);
}

// Initializes CTheZones
void CTheZones::Init()
{
	((void (__cdecl*)()) FUNC_CTheZones__Init)();
}

// Returns true if point lies within zone
bool CTheZones::PointLiesWithinZone(CVector const* pPoint, CZone * pZone)
{
	return ((bool (__cdecl*)(CVector const*, CZone *)) FUNC_CTheZones__PointLiesWithinZone)(pPoint, pZone);
}

// Updates CTheZones info
void CTheZones::Update()
{
	((void (__cdecl*)()) FUNC_CTheZones__Update)();
}