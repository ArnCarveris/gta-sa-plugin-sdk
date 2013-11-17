#pragma once
#include "plugin\plugin.h"

#define FUNC_CPad__AddToPCCheatString 0x438480
#define FUNC_CPad__DoCheats 0x439AF0
#define FUNC_CPad__ResetCheats 0x438450

#define VAR_CPad__KeyBoardCheatString 0x969110
#define VAR_CPad__CheatEnabledArray 0x969130
#define VAR_CPad__bHasPlayerCheated 0x96918C

// #define MAX_SIZEOF_

#pragma pack(push, 1)
// Set values to 128 unless otherwise specified
class CControllerState
{
public:
        signed short LeftStickX; // move/steer left (-128?)/right (+128)
        signed short LeftStickY; // move back(+128)/forwards(-128?)
        signed short RightStickX; // numpad 6(+128)/numpad 4(-128?)
        signed short RightStickY;
        
        signed short LeftShoulder1;
        signed short LeftShoulder2;
        signed short RightShoulder1; // target / hand brake
        signed short RightShoulder2; 
        
        signed short DPadUp; // radio change up
        signed short DPadDown; // radio change down
        signed short DPadLeft;
        signed short DPadRight;


        signed short Start;
        signed short Select;


        signed short ButtonSquare; // jump / reverse
        signed short ButtonTriangle; // get in/out
        signed short ButtonCross; // sprint / accelerate
        signed short ButtonCircle; // fire


        signed short ShockButtonL;
        signed short ShockButtonR; // look behind


        signed short m_bChatIndicated;
        signed short m_bPedWalk;
        signed short m_bVehicleMouseLook;
        signed short m_bRadioTrackSkip;

		/*
		NOINLINE CControllerState() {
			PREPARE_FOR_REDIRECTION()	// redirect to 
                // memset(this, 0, sizeof(CControllerState));
				// GetCurrentDirectory(3, "fds");
        }
		*/
};

VALIDATE_SIZE(CControllerState, 0x30);

#define KEYBOARD_CHEAT_STRING_COUNTOF 30
#define MIN_VALID_CHEAT_STRING_LEN 6

#pragma pack(push, 1)
class PLUGIN_API CPad
{
public:
	bool CycleWeaponRightJustDown();
	bool CycleWeaponLeftJustDown();


public:
	// VARIABLES
	CControllerState NewState;
	CControllerState OldState;
	__int16 SteeringLeftRightBuffer[10];
	signed __int32 DrunkDrivingBufferUsed;
	CControllerState PCTempKeyState;
	CControllerState PCTempJoyState;
	CControllerState PCTempMouseState;
	char Phase;
	char __pad1;
	__int16 Mode;
	signed __int16 ShakeDur;
	WORD DisablePlayerControls;
	BYTE ShakeFreq;
	char bHornHistory[5];
	BYTE iCurrHornHistory;
	BYTE JustOutOfFrontEnd;
	BYTE bApplyBrakes;
	BYTE bDisablePlayerEnterCar;
	BYTE bDisablePlayerDuck;
	BYTE bDisablePlayerFireWeapon;
	BYTE bDisablePlayerFireWeaponWithL1;
	BYTE bDisablePlayerCycleWeapon;
	BYTE bDisablePlayerJump;
	BYTE bDisablePlayerDisplayVitalStats;
	int LastTimeTouched;
	signed __int32 AverageWeapon;
	signed __int32 AverageEntries;
	DWORD NoShakeBeforeThis;
	char NoShakeFreq;
	__int16 __pad2;
	char __pad3;

	// Static variables

	// Keyboard cheat string, the last typed character is at index [0], the second last typed character is at index [1].
	// Countof: KEYBOARD_CHEAT_STRING_COUNTOF
	static char* KeyBoardCheatString;

	// Array of cheat states
	static bool* CheatEnabledArray;

	// True if player has cheated
	static bool& bHasPlayerCheated;

	// FUNCTIONS

	// Constructor
	NOINLINE CPad::CPad();
  
	// Destructor
	NOINLINE CPad::~CPad();

	// Adds character to cheat string
	static void CPad::AddToPCCheatString(char character);

	// Processes keyboard input for cheat purpose
	static void CPad::DoCheats();

	// Resets cheats
	static void CPad::ResetCheats();
};
#pragma pack(pop)

VALIDATE_SIZE(CPad, 0x134);