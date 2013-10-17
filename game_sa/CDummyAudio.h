#pragma once

#include "plugin\plugin.h"
#include "CSound.h"

#pragma pack(push, 4)
class PLUGIN_API CDummyAudio
{
protected:
	void *vtable;
public:
	class CEntity *m_pEntity;
	CSound m_Sound;
};
#pragma pack(pop)

VALIDATE_SIZE(CDummyAudio, 0x7C);