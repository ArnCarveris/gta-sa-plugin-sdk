#pragma once

#include "plugin\plugin.h"
#include "tHandlingData.h"
#include "tBikeHandlingData.h"
#include "tFlyingHandlingData.h"
#include "tBoatHandlingData.h"

#pragma pack(push, 4)
class PLUGIN_API cHandlingDataMgr
{
public:
	float field_0;
	float field_4;
	float field_8;
	float field_C;
	float field_10;
	tHandlingData       m_aVehicleHandling[210];
	tBikeHandlingData   m_aBikeHandling[13];
	tFlyingHandlingData m_aFlyingHandling[24];
	tBoatHandlingData   m_aBoatHandling[12];

	cHandlingDataMgr();

	void Initialise();
	// process handling.cfg
	void LoadHandlingData();
	// get vehicle number id in names table
	int FindExactWord(char *line, char *nameTable, int entrySize, int entryCount);
	bool IsNotRearDriveVehicle(unsigned char handlingId);
	bool IsNotFrontDriveVehicle(unsigned char handlingId);
	// get handling id by name
	int GetHandlingId(char *name);
	// update some handling variables with some world-specific multipliers
	void ConvertDataToWorldUnits(tHandlingData *handling);
	// update some handling variables with some game-specific multipliers
	void ConvertDataToGameUnits(tHandlingData *handling);
	void ConvertBikeDataToWorldUnits(tBikeHandlingData *bikeHandling);
	void ConvertBikeDataToGameUnits(tBikeHandlingData *bikeHandling);
	// get flying handling by id
	tFlyingHandlingData *GetFlyingPointer(unsigned char handlingId);
	// get boat handling by id
	tBoatHandlingData *GetBoatPointer(unsigned char handlingId);
};
#pragma pack(pop)

VALIDATE_SIZE(cHandlingDataMgr, 0xC624);