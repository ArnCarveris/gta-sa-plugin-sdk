#pragma once
#include <stdio.h>

#include "plugin\plugin.h"

#pragma pack(push, 1)
struct PLUGIN_API CText__TDat
{
	char* data;
	int size;

	// Reads TABL block from GXT file
	bool read(size_t TABLblockSize, FILE *file, int *pFileOffset, bool skipRead);
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PLUGIN_API CText__TablEntry
{
  char name[8];
  int offset;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PLUGIN_API CText__Tabl
{
	CText__TablEntry data[200];
	__int16 size;
	__int16 __pad;

	// Constructor
	CText__Tabl();

	// Reads TABL block from GXT file
	void read(size_t TABLblockSize, FILE *file, int *pFileOffset, int maxReadSize);
};
#pragma pack(pop)

#pragma pack(push, 1)
struct PLUGIN_API tGXT_VERSION_2_TKEY_item
{
	unsigned long int Position;		// TDAT + 8 offset
	unsigned long int KeyHash;
};
#pragma pack(pop)

#pragma pack(push, 4)
struct PLUGIN_API CText__TKey
{
	tGXT_VERSION_2_TKEY_item* data;
	__int16 size;
	

	// Reads TKEY block from GXT file
	bool read(size_t TKEYblockSize, FILE *file, int *pFileOffset, bool skipReading);

	// Patches offsets - adds specified integer value to every position member of TKEY item
	void patchOffsets(int PosOffsetMovement);

	// Performs a binary search for a specified key and returns pointer if found, otherwise NULL.
	tGXT_VERSION_2_TKEY_item* bsearch(unsigned int key, tGXT_VERSION_2_TKEY_item *data, signed __int16 firstIndex, __int16 lastIndex);

	// Returns pointer to string by GXT key name (label)
	const char* GetTextByLabel(const char* keyName, bool* bFound);

	// Destructor
	~CText__TKey();
};
#pragma pack(pop)

#pragma pack(push, 1)
class PLUGIN_API CText
{
public:
	CText__TKey tkeyMain;
	CText__TDat tdatMain;
	CText__TKey tkeyMission;
	CText__TDat tdatMission;
	char field_20;
	char haveTabl;
	char cderrorInitialized;
	char missionTableLoaded;
	char missionTableName[8];
	char cderrorText[256];
	CText__Tabl tabl;

	// Constructor
	CText();

	// Destructor
	~CText();

	// Returns text pointer by GXT key
	const char *__thiscall Get(const char *key);

	// Reads MPACK tag
	static void __stdcall readTag(char *buf, FILE *file, int *pFileOffset, bool dontRead);

	// Loads mission table from GXT file
	void LoadMissionTable(const char *tableName);

	// Loads MPACK
	void LoadMpack();

	// Loads GXT file
	void Load();

	// Unloads GXT file
	void Unload(bool bUnloadMissionData);

	// Writes a mission table name into buffer
	void getMissionTableName(char *outStr);
};
#pragma pack(pop)

extern PLUGIN_API CText& TheText;