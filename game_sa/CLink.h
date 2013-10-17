#pragma once

#include "plugin\plugin.h"
#include "RenderWare.h"

#pragma pack(push, 4)
class PLUGIN_API CLink
{
	class CLink *m_pNext;
	class CLink *m_pPrev;

	CLink();
	~CLink();
};
#pragma pack(pop)

VALIDATE_SIZE(CLink, 8);