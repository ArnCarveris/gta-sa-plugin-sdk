#pragma once
#include "plugin.h"
#include "RenderWare.h"

#pragma pack(push, 1)
class PLUGIN_API CRGBA : public RwRGBA
{
public:
	CRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
};
#pragma pack(pop)