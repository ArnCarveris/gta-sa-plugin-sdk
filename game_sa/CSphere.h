#pragma once

#include "plugin\plugin.h"
#include "CVector.h"

#pragma pack(push, 1)
class PLUGIN_API CSphere
{
public:
	CVector m_vCenter;
	float m_fRadius;

	void Set(float radius, CVector  const& center);
};
#pragma pack(pop)