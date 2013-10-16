#pragma once

#include "plugin\plugin.h"
#include "CRegisteredCorona.h"

#define MAX_NUM_CORONAS 64

class PLUGIN_API CCoronas
{
public:
	static float& SunScreenX;
	static float& SunScreenY;
	static unsigned __int8& SunBlockedByClouds;
	static bool& bChangeBrightnessImmediately;
	static unsigned __int32& NumRegisteredCoronas;
	// count: MAX_NUM_CORONAS (64)
	static CRegisteredCorona *aCoronas;

	static void Init();
	static void Shutdown();
	static void Update();
	static void Render();
	static void RenderReflections();
	static void RenderSunReflection();
	static void RegisterCorona(unsigned int id, CEntity *attachTo, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha, CVector const &posn, float radius, float farClip, RwTexture *texture, unsigned char flare, bool enableReflection, bool checkObstacles, int _param_not_used, float angle, bool longDistance, float nearClip, unsigned char fadeState, float fadeSpeed, bool onlyFromBelow, bool reflectionDelay);
	static void RegisterCorona(unsigned int id, CEntity *attachTo, unsigned char red, unsigned char green, unsigned char blue, unsigned char alpha, CVector const &posn, float radius, float farClip, unsigned char coronaType, unsigned char flare, bool enableReflection, bool checkObstacles, int _param_not_used, float angle, bool longDistance, float nearClip, unsigned char fadeState, float fadeSpeed, bool onlyFromBelow, bool reflectionDelay);
	static void UpdateCoronaCoors(unsigned int id, CVector  const& posn, float farClip, float angle);
	static void DoSunAndMoon();
};