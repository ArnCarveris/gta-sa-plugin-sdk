#pragma once

#include "plugin\plugin.h"
#include "RenderWare.h"

class PLUGIN_API CVector2D : public RwV2d
{
public:
	// Returns length of vector
	float Magnitude();
	// Substracts vector from vector.
	void operator-=(const CVector2D& right);
};