#pragma once

#include "plugin\plugin.h"
#include "CPlayerInfo.h"

class PLUGIN_API CWorld
{
public:
	// Player data array for 2 players.
	static CPlayerInfo *Players;
	// Current player we playing.
	static __int8& PlayerInFocus;
};