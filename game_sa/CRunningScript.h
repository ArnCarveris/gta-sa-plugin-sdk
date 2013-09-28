#pragma once
#include "plugin/plugin.h"

#define FUNC_CRunningScript__Init 0x4648E0
#define FUNC_CRunningScript__GetPointerToScriptVariable 0x464790
#define FUNC_CRunningScript__ProcessOneCommand 0x469EB0
#define FUNC_CRunningScript__CollectParameters 0x464080
#define FUNC_CRunningScript__StoreParameters 0x464370
#define FUNC_CRunningScript__CollectParametersToNewScript 0x464500
#define FUNC_CRunningScript__Process 0x469F00
#define FUNC_CRunningScript__DoDeatharrestCheck 0x485A50
#define FUNC_CRunningScript__CollectParameterWithoutMovingIP 0x464250
#define FUNC_CRunningScript__UpdateCompareFlag 0x4859D0
#define FUNC_CRunningScript__AddScriptToList 0x464C00
#define FUNC_CRunningScript__RemoveScriptFromList 0x464BD0
#define FUNC_CRunningScript__GetPadState 0x485B10

#define FUNC_CRunningScript__LocateCarCommand 0x487A20
#define FUNC_CRunningScript__LocateCharCarCommand 0x487420
#define FUNC_CRunningScript__LocateCharCharCommand 0x4870F0
#define FUNC_CRunningScript__LocateCharCommand 0x486D80
#define FUNC_CRunningScript__LocateCharObjectCommand 0x487720
#define FUNC_CRunningScript__LocateObjectCommand 0x487D10

// Command handlers
#define FUNC_CRunningScript__ProcessCommands_0To99 0x465E60
#define FUNC_CRunningScript__ProcessCommands_100To199 0x466DE0
#define FUNC_CRunningScript__ProcessCommands_200To299 0x469390
#define FUNC_CRunningScript__ProcessCommands_300To399 0x47C100
#define FUNC_CRunningScript__ProcessCommands_400To499 0x47D210
#define FUNC_CRunningScript__ProcessCommands_500To599 0x47E090
#define FUNC_CRunningScript__ProcessCommands_600To699 0x47F370
#define FUNC_CRunningScript__ProcessCommands_700To799 0x47FA30
#define FUNC_CRunningScript__ProcessCommands_800To899 0x481300
#define FUNC_CRunningScript__ProcessCommands_900To999 0x483BD0
#define FUNC_CRunningScript__ProcessCommands_1000To1099 0x489500
#define FUNC_CRunningScript__ProcessCommands_1100To1199 0x48A320
#define FUNC_CRunningScript__ProcessCommands_1200To1299 0x48B590
#define FUNC_CRunningScript__ProcessCommands_1300To1399 0x48CDD0
#define FUNC_CRunningScript__ProcessCommands_1400To1499 0x48EAA0
#define FUNC_CRunningScript__ProcessCommands_1500To1599 0x490DB0
#define FUNC_CRunningScript__ProcessCommands_1600To1699 0x493FE0
#define FUNC_CRunningScript__ProcessCommands_1700To1799 0x496E00
#define FUNC_CRunningScript__ProcessCommands_1800To1899 0x46D050
#define FUNC_CRunningScript__ProcessCommands_1900To1999 0x46B460
#define FUNC_CRunningScript__ProcessCommands_2000To2099 0x472310
#define FUNC_CRunningScript__ProcessCommands_2100To2199 0x470A90
#define FUNC_CRunningScript__ProcessCommands_2200To2299 0x474900
#define FUNC_CRunningScript__ProcessCommands_2300To2399 0x4762D0
#define FUNC_CRunningScript__ProcessCommands_2400To2499 0x478000
#define FUNC_CRunningScript__ProcessCommands_2500To2599 0x47A760
#define FUNC_CRunningScript__ProcessCommands_2600To2699 0x479DA0

union tScriptVarValue 
{
	unsigned __int32	dwParam;
	__int32			nParam;
	float			fParam;
	void		*pParam;
	char		*szParam;
};

VALIDATE_SIZE(tScriptVarValue, 0x4);

#pragma pack(push, 1)
class PLUGIN_API CRunningScript
{
public:
	CRunningScript	*next;
	CRunningScript	*prev;
	char			threadName[8];
	BYTE			*baseIp;
	BYTE			*ip;			
	BYTE			*gosub_stack[8];
	WORD			stack_index;
	WORD			_f3A;
	tScriptVarValue	tls[32];	
	DWORD			timers[2];	
	bool			isActive;
	bool			condResult;	
	bool			MissionCleanUpFlag;
	bool			IsExternalThread;
	BYTE			_fC8;
	char			_fC9;
	BYTE			_fCA;
	BYTE			_fCB;
	DWORD			wakeTime;
	WORD			logicalOp;
	bool			notFlag;
	bool			wastedBustedCheckEnabled;
	bool			wastedOrBusted;
	BYTE			_fD5;
	WORD			_fD6;
	DWORD			sceneSkipOffset;
	bool			missionFlag;

	// bellow is align in 4 bytes
	WORD			scmFunction;
	BYTE			IsCustom;

	// Initializes member variables.
	void CRunningScript::Init();

	// Processes running script
	void CRunningScript::Process();

	// Processes one command
	void CRunningScript::ProcessOneCommand();

	// Performs death arrest check
	void CRunningScript::DoDeatharrestCheck();

	// Returns pointer to script variable of any type.
	tScriptVarValue* CRunningScript::GetPointerToScriptVariable(unsigned __int8 unk1);

	// Collects parameters
	void CRunningScript::CollectParameters(__int16 count);

	// Collects parameter and returns it.
	tScriptVarValue CRunningScript::CollectParameterWithoutMovingIP();

	// Stores parameters
	void CRunningScript::StoreParameters(__int16 count);

	// Collects parameters and puts them to local variables of new script
	void CRunningScript::CollectParametersToNewScript(CRunningScript* pNewScript);

	// Updates comparement flag, used in conditional commands
	void CRunningScript::UpdateCompareFlag(bool state);

	// Adds script to list
	void CRunningScript::AddScriptToList(CRunningScript ** list);

	// Removes script from list
	void CRunningScript::RemoveScriptFromList(CRunningScript ** list);

	// Returns state of pad button.
	short CRunningScript::GetPadState(unsigned short playerIndex, unsigned short buttonID);

	// Command handlers
	void CRunningScript::ProcessCommands_0To99(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_100To199(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_200To299(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_300To399(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_400To499(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_500To599(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_600To699(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_700To799(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_800To899(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_900To999(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_1000To1099(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_1100To1199(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_1200To1299(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_1300To1399(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_1400To1499(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_1500To1599(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_1600To1699(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_1700To1799(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_1800To1899(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_1900To1999(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_2000To2099(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_2100To2199(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_2200To2299(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_2300To2399(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_2400To2499(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_2500To2599(unsigned __int16 commandID);
	void CRunningScript::ProcessCommands_2600To2699(unsigned __int16 commandID);

	// Processes commands that locate a vehicle
	void CRunningScript::LocateCarCommand(unsigned __int16 commandID);

	// Processes commands where char locates car
	void CRunningScript::LocateCharCarCommand(unsigned __int16 commandID);

	// Processes commands where char locates another char
	void CRunningScript::LocateCharCharCommand(unsigned __int16 commandID);

	// Processes commands where char locates map point
	void CRunningScript::LocateCharCommand(unsigned __int16 commandID);

	// Processes commands where char locates object
	void CRunningScript::LocateCharObjectCommand(unsigned __int16 commandID);

	// Processes commands where object locates map point
	void CRunningScript::LocateObjectCommand(unsigned __int16 commandID);

	// 
};
#pragma pack(pop)

VALIDATE_SIZE(CRunningScript, 0xE0);