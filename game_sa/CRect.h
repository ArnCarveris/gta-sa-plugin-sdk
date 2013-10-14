#pragma once

#include "plugin\plugin.h"

#pragma pack(push, 1)
class PLUGIN_API CRect
{
public:
	float m_X1;
	float m_Y1;
	float m_X2;
	float m_Y2;

	CRect(float x1, float y1, float x2, float y2);
	CRect();
	bool IsFlipped();
};
#pragma pack(pop)

VALIDATE_SIZE(CRect, 0x10);