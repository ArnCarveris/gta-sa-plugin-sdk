#pragma once
#include "plugin.h"

#include <windows.h>
#define VAR_CClock__bClockHasBeenStored 0xB70144
#define VAR_CClock__ms_Stored_nGameClockSeconds 0xB70148
#define VAR_CClock__ms_Stored_nGameClockMinutes 0xB7014A
#define VAR_CClock__ms_Stored_nGameClockHours 0xB7014B
#define VAR_CClock__ms_Stored_nGameClockMonthDay 0xB7014C
#define VAR_CClock__ms_Stored_nGameClockMonth 0xB7014D

#define VAR_CClock__ms_nGameClockDayOfWeek 0xB7014E
#define VAR_CClock__ms_nGameClockSeconds 0xB70150
#define VAR_CClock__ms_nGameClockMinutes 0x0B70152
#define VAR_CClock__ms_nGameClockHours 0xB70153
#define VAR_CClock__ms_nGameClockMonthDay 0xB70154
#define VAR_CClock__ms_nGameClockMonth 0xB70155
#define VAR_CClock__ms_nLastClockTick 0xB70158

#define FUNC_CClock__GetIsTimeInRange 0x52CEE0
#define FUNC_CClock__GetGameClockMinutesUntil 0x52CEB0
#define FUNC_CClock__Initialise 0x52CD90
#define FUNC_CClock__Update 0x52CF10
#define FUNC_CClock__NormaliseGameClock 0x52CDE0
#define FUNC_CClock__StoreClock 0x52D020
#define FUNC_CClock__RestoreClock 0x52D070
#define FUNC_CClock__SetNewDay 0x52D0B0
#define FUNC_CClock__SetGameClock 0x52D150

class PLUGIN_API CClock
{
public:
	// Variables
	static bool& bClockHasBeenStored;

	// Stored clock
	static WORD& ms_Stored_nGameClockSeconds;

	static BYTE& ms_Stored_nGameClockMinutes;

	static BYTE& ms_Stored_nGameClockHours;

	static BYTE& ms_Stored_nGameClockMonthDay;

	static BYTE& ms_Stored_nGameClockMonth;

	// Current clock
	static BYTE& ms_nGameClockDayOfWeek;

	static WORD& ms_nGameClockSeconds;

	static BYTE& ms_nGameClockMinutes;

	static BYTE& ms_nGameClockHours;

	static BYTE& ms_nGameClockMonthDay;
	
	static BYTE& ms_nGameClockMonth;

	static DWORD& ms_nLastClockTick;

	// Functions

	// Returns true current hour is in range of two specified hours.
	static bool CClock::GetIsTimeInRange(BYTE hourA, BYTE hourB);

	// Returns number of minutes to specified hour & minute.
	static WORD CClock::GetGameClockMinutesUntil(BYTE hours, BYTE minutes);

	// Initializes clock
	static void CClock::Initialise(DWORD milisecondsPerGameMinute);

	// Updates a time
	static void CClock::Update();

	// Normalizes game clock
	// For example hour of 24 means new day and hour 1.
	static void CClock::NormaliseGameClock();

	// Backups a clock time
	static void CClock::StoreClock();


	// Restores a clock time
	static void CClock::RestoreClock();

	// Sets new day
	// Directions (0 = one day backwards, 1 = one day forwards)
	static void CClock::SetNewDay(bool timeDirection);

	// Sets game clock
	static void CClock::SetGameClock(BYTE hours, BYTE minutes, BYTE day);
};