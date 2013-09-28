#include "CRunningScript.h"

// Initializes member variables.
void CRunningScript::Init()
{
	((void (__thiscall*)(CRunningScript*)) FUNC_CRunningScript__Init )(this);	
}

// Processes one command
void CRunningScript::ProcessOneCommand()
{
	 ((void (__thiscall*)(CRunningScript*)) FUNC_CRunningScript__ProcessOneCommand )(this);
}

// Returns pointer to script variable of any type.
tScriptVarValue* CRunningScript::GetPointerToScriptVariable(unsigned __int8 unk1)
{
	return ((tScriptVarValue* (__thiscall*)(CRunningScript*, unsigned __int8)) FUNC_CRunningScript__GetPointerToScriptVariable )(this, unk1);
}

// Collects parameters
void CRunningScript::CollectParameters(__int16 count)
{
	((void (__thiscall*)(CRunningScript*, __int16)) FUNC_CRunningScript__CollectParameters )(this, count);
}

// Stores parameters
void CRunningScript::StoreParameters(__int16 count)
{
	((void (__thiscall*)(CRunningScript*, __int16)) FUNC_CRunningScript__StoreParameters )(this, count);
}

// Collects parameters and puts them to local variables of new script
void CRunningScript::CollectParametersToNewScript(CRunningScript* pNewScript)
{
	((void (__thiscall*)(CRunningScript*, CRunningScript*)) FUNC_CRunningScript__CollectParametersToNewScript )(this, pNewScript);
}

// Performs death arrest check
void CRunningScript::DoDeatharrestCheck()
{
	((void (__thiscall*)(CRunningScript*)) FUNC_CRunningScript__DoDeatharrestCheck )(this);
}

// Processes running script
void CRunningScript::Process()
{
	((void (__thiscall*)(CRunningScript*)) FUNC_CRunningScript__Process )(this);
}