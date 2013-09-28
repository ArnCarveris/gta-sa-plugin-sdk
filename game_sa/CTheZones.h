#pragma once
#include <windows.h>
#include "plugin.h"
#include "CVector.h"
#include "CZone.h"

#define VAR_CTheZones__m_CurrLevel 0xBA6718
#define VAR_CTheZones__ExploredTerritoriesArray 0xBA3730
#define VAR_CTheZones__TotalNumberExploredTerritories 0xBA372C
#define VAR_CTheZones__TotalNumberOfInfoZones 0x572A5A
#define VAR_CTheZones__ZoneInfoArray 0xBA3798
#define VAR_CTheZones__TotalNumberOfMapZones 0xBA3794
#define VAR_CTheZones__MapZoneArray 0xBA1908

#define FUNC_CTheZones__CreateZone 0x5728A0
#define FUNC_CTheZones__GetLevelFromPosition 0x572300
#define FUNC_CTheZones__GetInfoZone 0x572590
#define FUNC_CTheZones__GetMapZone 0x5725A0
#define FUNC_CTheZones__FindZoneByLabelAndReturnIndex 0x572C40
#define FUNC_CTheZones__FindZoneForPoint 0x572360
#define FUNC_CTheZones__Init 0x572670
#define FUNC_CTheZones__PointLiesWithinZone 0x572270
#define FUNC_CTheZones__Update 0x572800

#pragma pack(push, 1)
class PLUGIN_API CTheZones
{
public:
	// Variables

	static eLevelName& m_CurrLevel;	
	
	// Explored teritories

	// Count: 100
	static char* ExploredTerritoriesArray;
	// Number of explored territories
	static DWORD& TotalNumberExploredTerritories;

	// Info zones
	static WORD& TotalNumberOfInfoZones;
	// Count: 380
	static CZone* ZoneInfoArray;

	// Map zones
	static WORD& TotalNumberOfMapZones;
	// Count: 39
	static CZone* MapZoneArray;

	// Functions

	// Creates a zone
	static void CreateZone(const char *name, eZoneType type, float posX1, float posY1, float posZ1, float posX2, float posY2, float posZ2, eLevelName island, const char *GXT_key);

	// Returns eLevelName from position
	static eLevelName GetLevelFromPosition(CVector const* pPoint);

	// Returns pointer to zone by index
	static CZone* GetInfoZone(WORD index);

	// Returns pointer to zone by index
	static CZone* GetMapZone(WORD index);

	// Returns pointer to zone by index
	static WORD FindZoneByLabelAndReturnIndex(const char* name, int unk2);

	// Returns pointer to zone by a point
	static CZone* FindZoneForPoint(const CVector& point, bool FindOnlyZonesType0);

	// Initializes CTheZones
	static void Init();

	// Returns true if point lies within zone
	static bool PointLiesWithinZone(CVector const* pPoint, CZone * pZone);

	// Updates CTheZones info
	static void Update();

};
#pragma pack(pop)