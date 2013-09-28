#pragma once

#include "plugin\plugin.h"
#include "CVector.h"

#pragma pack(push, 1)
class PLUGIN_API CSphere
{
public:
	CVector center;
	float radius;

	void Set(float _radius, CVector  const& _center);
};
#pragma pack(pop)