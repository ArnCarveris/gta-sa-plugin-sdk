#include "plugin\plugin.h"
#include "CVector.h"
#include "CEntity.h"
#include "CPed.h"
#include "CWeaponInfo.h"

// returns player coors
PLUGIN_API CVector FindPlayerCoors(int playerId);
// returns player speed
PLUGIN_API CVector const& FindPlayerSpeed(int playerId);
// returns player ped or player vehicle if he's driving
PLUGIN_API CEntity * FindPlayerEntity(int playerId);
// gets player coords
PLUGIN_API CVector const& FindPlayerCentreOfWorld(int playerId);
// gets player coords with skipping sniper shift
PLUGIN_API CVector const& FindPlayerCentreOfWorld_NoSniperShift(int playerId);
// returns player coords with skipping interior shift
PLUGIN_API CVector FindPlayerCentreOfWorld_NoInteriorShift(int playerId);
// returns player angle in radians
PLUGIN_API float FindPlayerHeading(int playerId);
// returns Z coord for active player
PLUGIN_API float FindPlayerHeight();
// returns player ped
PLUGIN_API CPed * FindPlayerPed(int playerId);
// 2 players are playing
PLUGIN_API bool InTwoPlayersMode();