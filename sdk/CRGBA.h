#pragma once
#include "sa_sdk.h"
#include "RenderWare.h"

#pragma pack(push, 1)
class PLUGIN_API CRGBA
{
public:
	union{
		unsigned int colorInt;
		struct{
			unsigned char red, green, blue, alpha;
		};
	};

	CRGBA(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
	CRGBA();
};
#pragma pack(pop)