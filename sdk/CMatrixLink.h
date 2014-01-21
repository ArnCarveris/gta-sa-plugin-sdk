#pragma once

// NOT FINISHED!

#include "sa_sdk.h"
#include "CMatrix.h"
#include "CVector.h"

class PLUGIN_API CMatrixLink : public CMatrix
{
public:
	class CPlaceable *m_pOwner;
	class CCoors *m_pPrev;
	class CCoors *m_pNext;

	CMatrixLink();
	~CMatrixLink();
	void Insert(CMatrixLink *matrixLink);
	void Remove();
};

VALIDATE_SIZE(CMatrixLink, 0x54);