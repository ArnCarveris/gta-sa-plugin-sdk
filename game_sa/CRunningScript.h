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

union tScriptVarValue 
{
	unsigned	dwParam;
	int			nParam;
	float		fParam;
	void		*pParam;
	char		*szParam;
};

VALIDATE_SIZE(tScriptVarValue, 0x4);

#pragma pack(push, 1)
struct PLUGIN_API CRunningScript
{
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

	// Returns pointer to script variable of any type.
	tScriptVarValue* CRunningScript::GetPointerToScriptVariable(unsigned __int8 unk1);

	// Processes one command
	void CRunningScript::ProcessOneCommand();

	// Collects parameters
	void CRunningScript::CollectParameters(__int16 count);

	// Collects parameter and returns it.
	tScriptVarValue CRunningScript::CollectParameterWithoutMovingIP();

	// Stores parameters
	void CRunningScript::StoreParameters(__int16 count);

	// Collects parameters and puts them to local variables of new script
	void CRunningScript::CollectParametersToNewScript(CRunningScript* pNewScript);

	// Performs death arrest check
	void CRunningScript::DoDeatharrestCheck();

	// Processes running script
	void CRunningScript::Process();

};
#pragma pack(pop)

VALIDATE_SIZE(CRunningScript, 0xE0);