#pragma once

#include "plugin\plugin.h"
#include "CBox.h"
#include "CColSphere.h"
#include "CColData.h"

#pragma pack(push, 4)
class PLUGIN_API CColModel
{
public:
	CBox m_Box;
	CColSphere m_Sphere;
	CColData *m_pColData;
};
#pragma pack(pop)

VALIDATE_SIZE(CColModel, 0x30);