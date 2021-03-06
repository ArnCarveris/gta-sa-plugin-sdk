#pragma once
#include "plugin\plugin.h"
#include "CSimpleCoors.h"
#include "CCoors.h"

#pragma pack(push, 4)
class PLUGIN_API CPlaceable
{
protected:
	void **vtable;
public:
	CSimpleCoors m_Placement;
	CCoors *m_pCoords;

	CPlaceable();
	~CPlaceable();

	CVector GetRightDirection();
	CVector GetTopDirection();
	CVector GetAtDirection();

	void SetPosn(float x, float y, float z);
	void SetPosn(CVector const& posn);
	void SetOrientation(float x, float y, float z);
	void SetHeading(float heading);
	float GetHeading();
	bool IsWithinArea(float x1, float y1, float x2, float y2);
	bool IsWithinArea(float x1, float y1, float z1, float x2, float y2, float z2);
	void DeleteCoors();
	void CreateCoors();
	void CreateL1Coors();
	void SetCoors(CCoors *coors);
	CVector FromObjectSpace(CVector const& offset);
};
#pragma pack(pop)

VALIDATE_SIZE(CPlaceable, 0x18);