#pragma once

#include "plugin\plugin.h"
#include "CVector.h"

#pragma pack(push, 4)
class PLUGIN_API CColLine
{
public:
	CVector m_vStart;
	float m_fStartSize;
	CVector m_vEnd;
	float m_fEndSize;

	CColLine(CVector  const& start, CVector  const& end);
	void Set(CVector  const& start, CVector  const& end);
};
#pragma pack(pop)

VALIDATE_SIZE(CColLine, 0x20);