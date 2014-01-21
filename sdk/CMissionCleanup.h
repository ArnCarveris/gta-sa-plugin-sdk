#pragma once
#include "sa_sdk.h"

#define FUNC_CMissionCleanup__Init 0x4637A0
#define FUNC_CMissionCleanup__Process 0x468560
#define FUNC_CMissionCleanup__FindFree 0x4637C0
#define FUNC_CMissionCleanup__AddEntityToList 0x4637E0
#define FUNC_CMissionCleanup__RemoveEntityFromList 0x4654B0
#define FUNC_CMissionCleanup__CheckIfCollisionHasLoadedForMissionObjects 0x4652D0

enum MissionCleanUpEntityType : char
{
	MISSION_CLEANUP_ENTITY_TYPE_EMPTY = 0,	// free slot

	MISSION_CLEANUP_ENTITY_TYPE_VEHICLE = 1,
	MISSION_CLEANUP_ENTITY_TYPE_PED = 2,
	MISSION_CLEANUP_ENTITY_TYPE_OBJECT = 3,
	MISSION_CLEANUP_ENTITY_TYPE_PARTICLE = 4,
	MISSION_CLEANUP_ENTITY_TYPE_GROUP = 5,
	MISSION_CLEANUP_ENTITY_TYPE_PED_QUEUE = 7,
	MISSION_CLEANUP_ENTITY_TYPE_TASK_SEQUENCE = 8,
	MISSION_CLEANUP_ENTITY_TYPE_DECISION_MAKER = 9,
	// type 10 does not exist
	MISSION_CLEANUP_ENTITY_TYPE_SEARCHLIGHT = 11,
	MISSION_CLEANUP_ENTITY_TYPE_CHECKPOINT = 12,
	MISSION_CLEANUP_ENTITY_TYPE_TXD = 13
};

#pragma pack(push, 1)
struct PLUGIN_API tMissionCleanupEntity
{
  MissionCleanUpEntityType type;
  char __pad[3];
  int handle;
};
#pragma pack(pop)

#pragma pack(push, 1)
class PLUGIN_API CMissionCleanup
{
	tMissionCleanupEntity m_Objects[75];
	char m_Count;

public:
	// Default constructor
	CMissionCleanup();

	// Initializes data
	void Init();

	// Performs a clean-up
	void Process();

	// Finds a free entity, returns NULL if no free entity can be found.
	tMissionCleanupEntity* FindFree();

	// Adds entity to list
	void AddEntityToList(int handle, MissionCleanUpEntityType type);

	// Remotes entity from list
	void RemoveEntityFromList(int handle, MissionCleanUpEntityType type);

	// Checks if collision has loaded for mission objects
	void CheckIfCollisionHasLoadedForMissionObjects();
};
#pragma pack(pop)

VALIDATE_SIZE(CMissionCleanup, 0x259);