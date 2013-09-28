#pragma once
#include "plugin.h"
#include "RenderWare.h"

#define FUNC_CVector__Magnitude 0x4082C0
#define FUNC_CVector__Normalise 0x59C910
#define FUNC_CVector__NormaliseGetLength 0x59C970
#define FUNC_CVector__Cross 0x70F890
#define FUNC_CVector__Sum 0x40FDD0
#define FUNC_CVector__Difference 0x40FE00
#define FUNC_CVector__operatorAssignmentCVector 0x411B50
#define FUNC_CVector__operatorAdditionAssignmentCVector 0x411A00
#define FUNC_CVector__operatorMultiplicationAssignmentFloat 0x40FEF0
#define FUNC_CVector__operatorDivisionAssignmentFloat 0x0411A30

#pragma pack(push, 1)
class PLUGIN_API CVector : public RwV3d
{
public:
	// Returns length of vector
	float Magnitude();

	// Normalises a vector
	void Normalise();

	// Normalises a vector and returns length
	float NormaliseGetLength();

	// Performs cross calculation
	void Cross(const CVector& left, const CVector &right);

	// Adds left + right and stores result
	void Sum(const CVector& left, const CVector &right);

	// Subtracts left - right and stores result
	void Difference(const CVector& left, const CVector &right);

	// Assigns value from other vector
	void operator= (const CVector& right);

	// Adds value from the second vector.
	void operator+=(const CVector& right);

	// Multiplies vector by a floating point value
	void operator *= (float multiplier);

	// Divides vector by a floating point value
	void operator /= (float divisor);
};
#pragma pack(pop)