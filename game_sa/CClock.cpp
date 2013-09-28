#include "CClock.h"

// Stored clock
bool& CClock::bClockHasBeenStored = *(bool*)VAR_CClock__bClockHasBeenStored;

WORD& CClock::ms_Stored_nGameClockSeconds = *(WORD*)VAR_CClock__ms_Stored_nGameClockSeconds;

BYTE& CClock::ms_Stored_nGameClockMinutes = *(BYTE*)VAR_CClock__ms_Stored_nGameClockMinutes;

BYTE& CClock::ms_Stored_nGameClockHours = *(BYTE*)VAR_CClock__ms_Stored_nGameClockHours;

BYTE& CClock::ms_Stored_nGameClockMonthDay = *(BYTE*)VAR_CClock__ms_Stored_nGameClockMonthDay;

BYTE& CClock::ms_Stored_nGameClockMonth = *(BYTE*)VAR_CClock__ms_Stored_nGameClockMonth;

// Current clock
BYTE& CClock::ms_nGameClockDayOfWeek = *(BYTE*)VAR_CClock__ms_nGameClockDayOfWeek;

WORD& CClock::ms_nGameClockSeconds = *(WORD*)VAR_CClock__ms_nGameClockSeconds;

BYTE& CClock::ms_nGameClockMinutes = *(BYTE*)VAR_CClock__ms_nGameClockMinutes;

BYTE& CClock::ms_nGameClockHours = *(BYTE*)VAR_CClock__ms_nGameClockHours;

BYTE& CClock::ms_nGameClockMonthDay = *(BYTE*)VAR_CClock__ms_nGameClockMonthDay;

BYTE& CClock::ms_nGameClockMonth = *(BYTE*)VAR_CClock__ms_nGameClockMonth;

DWORD& CClock::ms_nLastClockTick = *(DWORD*)VAR_CClock__ms_nLastClockTick;

// Returns true current hour is in range of two specified hours.
bool CClock::GetIsTimeInRange(BYTE hourA, BYTE hourB)
{
	return ((bool (_cdecl*)(BYTE hourA, BYTE hourB))FUNC_CClock__GetIsTimeInRange)(hourA, hourB);
}

// Returns number of minutes to specified hour & minute.
WORD CClock::GetGameClockMinutesUntil(BYTE hours, BYTE minutes)
{
	return ((WORD (_cdecl*)(BYTE hours, BYTE minutes))FUNC_CClock__GetGameClockMinutesUntil)(hours, minutes);
}

// Initializes clock
void CClock::Initialise(DWORD milisecondsPerGameMinute)
{
	((void (_cdecl*)(DWORD milisecondsPerGameMinute))FUNC_CClock__Initialise)(milisecondsPerGameMinute);
}

// Updates a time
void CClock::Update()
{
	((void (_cdecl*)())FUNC_CClock__Update)();
}

// Normalizes game clock
// For example hour of 24 means new day and hour 1.
void CClock::NormaliseGameClock()
{
	((void (_cdecl*)())FUNC_CClock__NormaliseGameClock)();
}

// Backups a clock time
void CClock::StoreClock()
{
	((void (_cdecl*)())FUNC_CClock__StoreClock)();
}


// Restores a clock time
void CClock::RestoreClock()
{
	((void (_cdecl*)())FUNC_CClock__RestoreClock)();
}

// Sets new day
// Directions (0 = one day backwards, 1 = one day forwards)
void CClock::SetNewDay(bool timeDirection)
{
	((void (_cdecl*)(bool timeDirection))FUNC_CClock__SetNewDay)(timeDirection);
}

// Sets game clock
void CClock::SetGameClock(BYTE hours, BYTE minutes, BYTE day)
{
	((void (_cdecl*)(BYTE hours, BYTE minutes, BYTE day))FUNC_CClock__SetGameClock)(hours, minutes, day);
}