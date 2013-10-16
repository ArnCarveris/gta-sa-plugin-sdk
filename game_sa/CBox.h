#pragma once

#include "plugin\plugin.h"
#include "CVector.h"

#pragma pack(push, 1)
class PLUGIN_API CBox
{
public:
	CVector m_vSup;
	CVector m_vInf;

	void Set(CVector  const& sup, CVector  const& inf);
};
#pragma pack(pop)