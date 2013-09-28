#pragma once

#include "CVector.h"

#pragma pack(push, 1)
class PLUGIN_API CBox
{
public:
	CVector sup;
	CVector inf;

	void Set(CVector  const& _sup, CVector  const& _inf);
};
#pragma pack(pop)