#pragma once

#include "sa_sdk.h"

#pragma pack(push, 4)
class PLUGIN_API CCamPathSplines
{
public:
	float *m_pArrPathData;
};
#pragma pack(pop)

VALIDATE_SIZE(CCamPathSplines, 4);