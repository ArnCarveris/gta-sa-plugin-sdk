#pragma once
#include "sa_sdk.h"
#include "AnimBlendFrameData.h"

#pragma pack(push, 4)
class PLUGIN_API CAnimBlenClumpData
{
public:
	void               *m_pLastAssociationLink;
	Int32 field_4;
	UInt32              m_dwNumBones;
	Int32 field_C;
	AnimBlendFrameData *m_pBones;
};