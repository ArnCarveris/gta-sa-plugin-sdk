#pragma once

#include "plugin\plugin.h"
#include "CDummyAudio.h"
#include "CSound.h"
#include "C85F438.h"

#pragma pack(push, 1)
class PLUGIN_API CPedCollisionAudio : public CDummyAudio
{
  __int8 field_7C;
  __int8 field_7D;
  __int16 field_7E;
  __int32 field_80;
  float field_84;
  float field_88;
  __int8 field_8C[8];
  class CPed *m_pPed;
  __int8 field_98;
  __int8 field_99[3];
  CSound *field_9C;
  __int32 field_A0;
  CSound *field_A4;
  C85F438 m_85F438;
  CSound *field_150;
  float field_154;
  float field_158;
};
#pragma pack(pop)

VALIDATE_SIZE(CPedCollisionAudio, 0x15C);