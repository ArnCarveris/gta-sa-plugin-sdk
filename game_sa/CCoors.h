#pragma once

// NOT FINISHED!

#include "plugin\plugin.h"
#include "CMatrix.h"
#include "CVector.h"

class PLUGIN_API CCoors : public CMatrix
{
public:
	class CPlaceable *m_pOwner;
	class CCoors *m_pPrev;
	class CCoors *m_pNext;

	CCoors();
	~CCoors();
	CCoors *GetPrev();
	CCoors *GetNext();
	void SetScale(float scale);
	void SetTranslate(CVector *translation);
};

VALIDATE_SIZE(CCoors, 0x54);