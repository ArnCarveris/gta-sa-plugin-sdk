#include "CCutsceneShadow.h"

NOINLINE CCutsceneShadow::CCutsceneShadow()
{
	PREPARE_FOR_REDIRECTION();
	//((void (__thiscall *)(CCutsceneShadow *))0x706410)(this);
}

NOINLINE CCutsceneShadow::~CCutsceneShadow()
{
	PREPARE_FOR_REDIRECTION();
	//((void (__thiscall *)(CCutsceneShadow *))0x706440)(this);
}

RwFrame *CCutsceneShadow::SetLightProperties(float angle, float _unused_param, bool setLight)
{
	return ((RwFrame *(__thiscall *)(CCutsceneShadow *, float, float, bool))0x705900)(this, angle, _unused_param, setLight);
}

void CCutsceneShadow::Destroy()
{
	((void (__thiscall *)(CCutsceneShadow *))0x705990)(this);
}

CShadowCamera *CCutsceneShadow::GetShadowCamera()
{
	return ((CShadowCamera *(__thiscall *)(CCutsceneShadow *))0x7059E0)(this);
}

RwTexture *CCutsceneShadow::GetShadowRwTexture()
{
	return ((RwTexture *(__thiscall *)(CCutsceneShadow *))0x7059F0)(this);
}

void CCutsceneShadow::DrawBorderAroundTexture(RwRGBA  const& color)
{
	((void (__thiscall *)(CCutsceneShadow *, RwRGBA  const&))0x705A00)(this, color);
}

// this creates all stuff for shadow processing (cameras, textures)
bool CCutsceneShadow::Create(bool isBlurred, int blurPasses, bool drawMoreBlur)
{
	return ((bool (__thiscall *)(CCutsceneShadow *, bool, int, bool))0x706460)(this, isBlurred, blurPasses, drawMoreBlur);
}

// this one registers shadow for entity
bool CCutsceneShadow::SetupForThisEntity(CPhysical *owner)
{
	return ((bool (__thiscall *)(CCutsceneShadow *, CPhysical *))0x706520)(this, owner);
}

// this updates texture and give it to us
RwTexture *CCutsceneShadow::Update()
{
	return ((RwTexture *(__thiscall *)(CCutsceneShadow *))0x706600)(this);
}