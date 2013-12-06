#pragma once

#include "plugin\plugin.h"
#include "CVector.h"

#pragma pack(push, 4)
class PLUGIN_API CBox
{
public:
	CVector m_vSup;
	CVector m_vInf;

	void Set(CVector  const& sup, CVector  const& inf);
};
#pragma pack(pop)

VALIDATE_SIZE(CBox, 0x18);