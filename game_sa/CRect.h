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

	inline CRect(float _x1, float _y1, float _x2, float _y2)
	{
		x1 = _x1;
		y1 = _y1;
		x2 = _x1;
		y2 = _y1;
	}

	inline CRect()
	{
		x1 = 1000000.0;
		y1 = -1000000.0;
		x2 = -1000000.0;
		y2 = 1000000.0;
	}
};
#pragma pack(pop)