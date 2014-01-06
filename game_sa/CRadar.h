#pragma once

#include "plugin\plugin.h"
#include "CVector.h"
#include "CRGBA.h"
#include "CVector2D.h"
#include "CSprite2d.h"

#pragma pack(push, 1)
struct PLUGIN_API tRadarTrace
{
	UInt32  m_dwColour;
	UInt32  m_dwEntityHandle;
	CVector m_vPosition;
	UInt16  m_wIndex;
	PAD2
	Float   m_fSphereRadius;
	UInt16  m_dwBlipSize;
	PAD2
	class CEntryExit *m_pEntryExit;
	UInt8   m_nBlipSprite;
	/* http://code.google.com/p/mtasa-blue/source/browse/tags/1.3.4/MTA10/game_sa/CMarkerSA.h */
	UInt8   m_bBright : 1;
    UInt8   m_bTrackingBlip : 1;
    UInt8   m_bShortRange : 1;
    UInt8   m_bFriendly : 1;    
    UInt8   m_bBlipRemain : 1;
    UInt8   m_bBlipFade : 1;
    UInt8   m_nCoordBlipAppearance : 2;
    UInt8   m_nBlipDisplayFlag : 2;
    UInt8   m_nBlipType : 4;
	PAD1
};
#pragma pack(pop)

VALIDATE_SIZE(tRadarTrace, 0x28);

class PLUGIN_API CRadar
{
public:
	// 2990.0 by default
	static float &m_radarRange;
	// static UInt16 MapLegendList[175];
	static UInt16 *MapLegendList;
	// num icons in legend
	static UInt16 &MapLegendCounter;
	// static CRGBA ArrowBlipColours[6];
	static CRGBA *ArrowBlipColours;
	// static tRadarTrace ms_RadarTrace[175];
	static tRadarTrace *ms_RadarTrace;
	// static CVector2D vec2DRadarOrigin;
	static CVector2D &vec2DRadarOrigin;
	// static CSprite2d RadarBlipSprites[64];
	static CSprite2d *RadarBlipSprites;
};