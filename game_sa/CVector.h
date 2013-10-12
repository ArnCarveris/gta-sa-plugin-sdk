#pragma once
#include "plugin\plugin.h"
#include "RenderWare.h"

#pragma pack(push, 1)
class PLUGIN_API CVector : public RwV3d
{
public:
	CVector();
	CVector(float x, float y, float z);

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