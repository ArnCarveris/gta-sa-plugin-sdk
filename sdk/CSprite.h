#pragma once

#include "sa_sdk.h"

class PLUGIN_API CSprite
{
public:
	static void RenderOneXLUSprite(float x, float y, float z, float halfWidth, float halfHeight, 
		unsigned char red, unsigned char green, unsigned char blue, short alpha, float rhw, 
		unsigned char intensity, unsigned char udir, unsigned char vdir);
};