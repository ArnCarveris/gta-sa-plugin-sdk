#pragma once

#include "CVector.h"

#pragma pack(push, 1)
class CSphere
{
public:
	CVector center;
	float radius;

	void Set(float _radius, CVector  const& _center)
	{
		((void (__thiscall *)(CSphere *, float, CVector  const&))0x40FCF0)(this, radius, center);
	}
};
#pragma pack(pop)