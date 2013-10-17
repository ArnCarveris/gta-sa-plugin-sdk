#pragma once

#include "plugin\plugin.h"

#pragma pack(push, 4)
class PLUGIN_API CEntityScanner
{
protected:
	int __vmt;
public:
	int field_4;
	unsigned int m_dwCount;
	class CEntity *m_apEntities[16];
	int field_4C;
};
#pragma pack(pop)

VALIDATE_SIZE(CEntityScanner, 0x50);