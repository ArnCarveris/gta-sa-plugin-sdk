#pragma once

#include "CVector.h"
#include "CMatrix.h"

class CSimpleCoors
{
public:
	CVector m_vPosn;
	float m_fAngle;

	void Get(RwMatrix *out); // possibly was operator= ? Idk how R* used this
	void Get(CMatrix *out);
};

VALIDATE_SIZE(CSimpleCoors, 0x10);