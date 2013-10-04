#include "CRunningScript.h"

// Initializes member variables.
void CRunningScript::Init()
{
	((void (__thiscall*)(CRunningScript*)) FUNC_CRunningScript__Init )(this);	
}

// Processes one command
int CRunningScript::ProcessOneCommand()
{
	 return ((int (__thiscall*)(CRunningScript*)) FUNC_CRunningScript__ProcessOneCommand )(this);
}

// Reads array offset and value from array index variable.
void CRunningScript::GetArrayOffsetAndValueOfIndexVariable(__int16 *pOffset, __int32 *pIdx)
{
	((void (__thiscall*)(CRunningScript*, __int16*, __int32*)) FUNC_CRunningScript__GetArrayOffsetAndValueOfIndexVariable )(this, pOffset, pIdx);	
}

// Returns offset of global variable
__int16 CRunningScript::GetOffsetOfGlobalVariable()
{
	return ((__int16 (__thiscall*)(CRunningScript*)) FUNC_CRunningScript__GetOffsetOfGlobalVariable )(this);
}

// Returns pointer to script variable of any type.
tScriptVarValue* CRunningScript::GetPointerToScriptVariable(unsigned __int8 unk1)
{
	return ((tScriptVarValue* (__thiscall*)(CRunningScript*, unsigned __int8)) FUNC_CRunningScript__GetPointerToScriptVariable )(this, unk1);
}

// Returns condition result
inline bool CRunningScript::GetConditionResult()
{
	return this -> condResult;
}

// Returns pointer to local variable pointed by offset and array index as well as multiplier.
void CRunningScript::GetPointerLocalVariableByArrayIndex(__int16 off, __int16 idx, unsigned __int8 mul)
{
	((void (__thiscall*)(CRunningScript*, __int16, __int16, unsigned __int8)) FUNC_CRunningScript__GetPointerLocalVariableByArrayIndex )(this, off, idx, mul);
}

// Collects parameters
void CRunningScript::CollectParameters(__int16 count)
{
	((void (__thiscall*)(CRunningScript*, __int16)) FUNC_CRunningScript__CollectParameters )(this, count);
}

// Collects parameter and returns it.
tScriptVarValue CRunningScript::CollectParameterWithoutMovingIP()
{
	tScriptVarValue value;

	__asm
	{
		mov eax, FUNC_CRunningScript__CollectParameterWithoutMovingIP
		mov ecx, this
		call eax
		mov value, eax
	}
	return value;
}

// Collects string parameter
void CRunningScript::CollectStringParameter(char *pBuffer, unsigned __int8 nBufferLength)
{
	((void (__thiscall*)(CRunningScript*, char *, unsigned __int8)) FUNC_CRunningScript__CollectStringParameter )(this, pBuffer, nBufferLength);
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

// Sets instruction pointer, used in GOTO-like commands
void CRunningScript::SetIntructionPointer(__int32 newIP)
{
	((void (__thiscall*)(CRunningScript*, __int32)) FUNC_CRunningScript__UpdateCompareFlag )(this, newIP);
}

// Updates comparement flag, used in conditional commands
void CRunningScript::UpdateCompareFlag(bool state)
{
	((void (__thiscall*)(CRunningScript*, bool)) FUNC_CRunningScript__UpdateCompareFlag )(this, state);
}

// Terminates a script
void CRunningScript::TerminateThisScript()
{
	((void (__thiscall*)(CRunningScript*)) FUNC_CRunningScript__TerminateThisScript )(this);
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

// Adds script to list
void CRunningScript::AddScriptToList(CRunningScript ** list)
{
	((void (__thiscall*)(CRunningScript*, CRunningScript **)) FUNC_CRunningScript__AddScriptToList )(this, list);
}

// Removes script from list
void CRunningScript::RemoveScriptFromList(CRunningScript ** list)
{
	((void (__thiscall*)(CRunningScript*, CRunningScript **)) FUNC_CRunningScript__RemoveScriptFromList )(this, list);
}

// Returns state of pad button.
short CRunningScript::GetPadState(unsigned short playerIndex, unsigned short buttonID)
{
	return ((short (__thiscall*)(CRunningScript*, unsigned short, unsigned short)) FUNC_CRunningScript__GetPadState )(this, playerIndex, buttonID);
}

// Command handlers
void CRunningScript::ProcessCommands_0To99(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_0To99 )(this, commandID);
}

void CRunningScript::ProcessCommands_100To199(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_100To199 )(this, commandID);
}

void CRunningScript::ProcessCommands_200To299(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_200To299 )(this, commandID);
}

void CRunningScript::ProcessCommands_300To399(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_300To399 )(this, commandID);
}

void CRunningScript::ProcessCommands_400To499(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_400To499 )(this, commandID);
}

void CRunningScript::ProcessCommands_500To599(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_500To599 )(this, commandID);
}

void CRunningScript::ProcessCommands_600To699(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_600To699 )(this, commandID);
}

void CRunningScript::ProcessCommands_700To799(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_700To799 )(this, commandID);
}

void CRunningScript::ProcessCommands_800To899(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_800To899 )(this, commandID);
}

void CRunningScript::ProcessCommands_900To999(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_900To999 )(this, commandID);
}

void CRunningScript::ProcessCommands_1000To1099(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_1000To1099 )(this, commandID);
}

void CRunningScript::ProcessCommands_1100To1199(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_1100To1199 )(this, commandID);
}

void CRunningScript::ProcessCommands_1200To1299(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_1200To1299 )(this, commandID);
}

void CRunningScript::ProcessCommands_1300To1399(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_1300To1399 )(this, commandID);
}

void CRunningScript::ProcessCommands_1400To1499(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_1400To1499 )(this, commandID);
}

void CRunningScript::ProcessCommands_1500To1599(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_1500To1599 )(this, commandID);
}

void CRunningScript::ProcessCommands_1600To1699(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_1600To1699 )(this, commandID);
}

void CRunningScript::ProcessCommands_1700To1799(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_1700To1799 )(this, commandID);
}

void CRunningScript::ProcessCommands_1800To1899(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_1800To1899 )(this, commandID);
}

void CRunningScript::ProcessCommands_1900To1999(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_1900To1999 )(this, commandID);
}

void CRunningScript::ProcessCommands_2000To2099(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_2000To2099 )(this, commandID);
}

void CRunningScript::ProcessCommands_2100To2199(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_2100To2199 )(this, commandID);
}

void CRunningScript::ProcessCommands_2200To2299(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_2200To2299 )(this, commandID);
}

void CRunningScript::ProcessCommands_2300To2399(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_2300To2399 )(this, commandID);
}

void CRunningScript::ProcessCommands_2400To2499(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_2400To2499 )(this, commandID);
}

void CRunningScript::ProcessCommands_2500To2599(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_2500To2599 )(this, commandID);
}

void CRunningScript::ProcessCommands_2600To2699(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ProcessCommands_2600To2699 )(this, commandID);
}

// Processes commands that locate a vehicle
void CRunningScript::LocateCarCommand(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__LocateCarCommand )(this, commandID);
}

// Processes commands where char locates car
void CRunningScript::LocateCharCarCommand(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__LocateCharCarCommand )(this, commandID);
}

// Processes commands where char locates another char
void CRunningScript::LocateCharCharCommand(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__LocateCharCharCommand )(this, commandID);
}

// Processes commands where char locates map point
void CRunningScript::LocateCharCommand(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__LocateCharCommand )(this, commandID);
}

// Processes commands where char locates object
void CRunningScript::LocateCharObjectCommand(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__LocateCharObjectCommand )(this, commandID);
}

// Processes commands where object locates map point
void CRunningScript::LocateObjectCommand(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__LocateObjectCommand )(this, commandID);
}

// Processes commands that check if object is in area
void CRunningScript::ObjectInAreaCheckCommand(unsigned __int16 commandID)
{
	((void (__thiscall*)(CRunningScript*, unsigned __int16)) FUNC_CRunningScript__ObjectInAreaCheckCommand )(this, commandID);
}

// Checks if ped type conforms to valid ped types.
bool CRunningScript::ThisIsAValidRandomPed(ePedType pedType, bool civilian, bool gang, bool criminal)
{
	return ((bool (__thiscall*)(CRunningScript*, ePedType, bool, bool, bool)) FUNC_CRunningScript__ThisIsAValidRandomPed )(this, pedType, civilian, gang, criminal);
}