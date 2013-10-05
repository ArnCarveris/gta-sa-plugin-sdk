#pragma once

// NOT FINISHED!

#include "CMatrix.h"
#include "CVector.h"

class CCoors : public CMatrix
{
public:
	void *m_pPlaceable;
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