#pragma once

#include "plugin\plugin.h"
#include "CPhysical.h"
#include "tHandlingData.h"
#include "tFlyingHandlingData.h"
#include "eVehicleHandlingFlags.h"

#pragma pack(push, 4)
class PLUGIN_API CVehicle : public CPhysical
{
	tHandlingData            *m_pHandlingData;
	tFlyingHandlingData      *m_pFlyingHandlingData;
	union {
		eVehicleHandlingFlags m_dwHandlingFlags;
		struct {
			unsigned __int32 m_b1gBoost : 1;
			unsigned __int32 m_b2gBoost : 1;
			unsigned __int32 m_bNpcAntiRoll : 1;
			unsigned __int32 m_bNpcNeutralHandl : 1;
			unsigned __int32 m_bNoHandbrake : 1;
			unsigned __int32 m_bSteerRearwheels : 1;
			unsigned __int32 m_bHbRearwheelSteer : 1;
			unsigned __int32 m_bAltSteerOpt : 1;
			unsigned __int32 m_bWheelFNarrow2 : 1;
			unsigned __int32 m_bWheelFNarrow : 1;
			unsigned __int32 m_bWheelFWide : 1;
			unsigned __int32 m_bWheelFWide2 : 1;
			unsigned __int32 m_bWheelRNarrow2 : 1;
			unsigned __int32 m_bWheelRNarrow : 1;
			unsigned __int32 m_bWheelRWide : 1;
			unsigned __int32 m_bWheelRWide2 : 1;
			unsigned __int32 m_bHydraulicGeom : 1;
			unsigned __int32 m_bHydraulicInst : 1;
			unsigned __int32 m_bHydraulicNone : 1;
			unsigned __int32 m_bNosInst : 1;
			unsigned __int32 m_bOffroadAbility : 1;
			unsigned __int32 m_bOffroadAbility2 : 1;
			unsigned __int32 m_bHalogenLights : 1;
			unsigned __int32 m_bProcRearwheelFirst : 1;
			unsigned __int32 m_bUseMaxspLimit : 1;
			unsigned __int32 m_bLowRider : 1;
			unsigned __int32 m_bStreetRacer : 1;
			unsigned __int32 m_bSwingingChassis : 1;
		};
	};

};
#pragma pack(pop)