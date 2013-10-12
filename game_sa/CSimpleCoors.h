#pragma once

#include "plugin\plugin.h"
#include "CVector.h"
#include "CMatrix.h"

class PLUGIN_API CSimpleCoors
{
public:
	CVector m_vPosn;
	float m_fHeading;

	CSimpleCoors();

	void Get(RwMatrix *out); // possibly was operator= ? Idk how R* used this
	void Get(CMatrix *out);
};

VALIDATE_SIZE(CSimpleCoors, 0x10);