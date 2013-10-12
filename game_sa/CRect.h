#pragma once

#include "plugin\plugin.h"

#pragma pack(push, 1)
class PLUGIN_API CRect
{
public:
	float x1;
	float y1;
	float x2;
	float y2;

	CRect(float _x1, float _y1, float _x2, float _y2);
	CRect();
};
#pragma pack(pop)

VALIDATE_SIZE(CRect, 0x10);