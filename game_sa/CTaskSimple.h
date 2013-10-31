#pragma once

#include "plugin\plugin.h"

#pragma pack(push, 4)
class PLUGIN_API CTaskSimple
{
public:
  void *vmt;
  class CTaskSimple *m_pParentTask;
};
#pragma pack(pop)

VALIDATE_SIZE(CTaskSimple, 8);

typedef CTaskSimple CTask;