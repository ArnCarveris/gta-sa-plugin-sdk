#pragma once

#include "plugin\plugin.h"
#include "CVector.h"

#pragma pack(push, 4)
class PLUGIN_API CPointLight
{
public:
	CVector m_vPosn;
	CVector m_vDirection;
    float m_fRange;
    float m_fColorRed;
    float m_fColorGreen;
    float m_fColorBlue;
    class CEntity *m_pEntityToLight;
    unsigned __int8 m_nType;
    unsigned __int8 m_nFogType;
    unsigned __int8 m_bGenerateShadows;
};
#pragma pack(pop)

VALIDATE_SIZE(CPointLight, 0x30);