#pragma once

#include "plugin\plugin.h"
#include "CVector2D.h"

#pragma pack(push, 1)
class PLUGIN_API CRect
{
public:

	/* CRect class describes a rectangle.

	      A(X1;Y1)-----------------------|
		  |                               |
		  |                               |
		  |                               |
		  |________________________B(X2;Y2)
	
	*/

	float m_X1;
	float m_Y1;
	float m_X2;
	float m_Y2;

	CRect(float x1, float y1, float x2, float y2);
	CRect();

	bool IsFlipped();
	void Restrict(CRect const& restriction);
	void Resize(float resizeX, float resizeY);
	bool IsPointInside(CVector2D const& point);
	bool IsCircleInside(CVector2D const& circleCenter, float circleRadius);
};
#pragma pack(pop)

VALIDATE_SIZE(CRect, 0x10);