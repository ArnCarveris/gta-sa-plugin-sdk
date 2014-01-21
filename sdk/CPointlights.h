#pragma once

#include "sa_sdk.h"
#include "CPointLight.h"

#define MAX_POINTLIGHTS 32

class PLUGIN_API CPointLights
{
public:
	// static variables

	// num of registered lights in frame
	static unsigned __int32& NumLights;
	// lights array. Count: MAX_POINTLIGHTS (32)
	static CPointLight *aLights;

	// static functions


};