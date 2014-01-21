#pragma once
#include "sa_sdk.h"
#include "CSimpleTransform.h"
#include "CMatrixLink.h"

#pragma pack(push, 4)
class PLUGIN_API CPlaceable
{
protected:
	void **vtable;
public:
	CSimpleTransform m_Placement;
	CMatrixLink *m_pCoords;

	CPlaceable();
	~CPlaceable();

	static void ShutdownMatrixArray();
	static void InitMatrixArray();

	CVector GetRightDirection();
	CVector GetTopDirection();
	CVector GetAtDirection();

	void FreeStaticMatrix();
	void SetPosn(float x, float y, float z);
	void SetPosn(CVector const& posn);
	void SetOrientation(float x, float y, float z);
	void SetHeading(float heading);
	float GetHeading();
	bool IsWithinArea(float x1, float y1, float x2, float y2);
	bool IsWithinArea(float x1, float y1, float z1, float x2, float y2, float z2);
	void RemoveMatrix();
	void AllocateStaticMatrix();
	void AllocateMatrix();
	void SetMatrix(CMatrix  const& matrix);
	CVector FromObjectSpace(CVector const& offset);
};
#pragma pack(pop)

VALIDATE_SIZE(CPlaceable, 0x18);