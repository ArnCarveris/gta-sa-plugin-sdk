#include "plugin\plugin.h"

union tScriptVarValue 
{
	unsigned	dwParam;
	int			nParam;
	float		fParam;
	void		*pParam;
	char		*szParam;
};

#pragma pack(push, 4)
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


};
#pragma pack(pop)