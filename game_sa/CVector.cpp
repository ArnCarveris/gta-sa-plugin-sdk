#include "CVector.h"

// Returns length of vector
float CVector::Magnitude()
{
	return ((float (__thiscall*)(CVector*)) FUNC_CVector__Magnitude)(this);
}

// Normalises a vector
void CVector::Normalise()
{
	((void (__thiscall*)(CVector*)) FUNC_CVector__Normalise)(this);
}

// Normalises a vector and returns length
float CVector::NormaliseGetLength()
{
	return ( (float (__thiscall*)(CVector*)) FUNC_CVector__NormaliseGetLength)(this);
}

// Performs cross calculation
void CVector::Cross(const CVector& left, const CVector &right)
{
	( (void (__thiscall*)(CVector*, const CVector& left, const CVector &right)) FUNC_CVector__Cross)(this, left, right);
}

// Adds left + right and stores result
void CVector::Sum(const CVector& left, const CVector &right)
{
	( (void (__thiscall*)(CVector*, const CVector& left, const CVector &right)) FUNC_CVector__Sum)(this, left, right);
}

// Subtracts left - right and stores result
void CVector::Difference(const CVector& left, const CVector &right)
{
	( (void (__thiscall*)(CVector*, const CVector& left, const CVector &right)) FUNC_CVector__Difference)(this, left, right);
}

// Assigns value from other vector
void CVector::operator= (const CVector& right)
{
	( (void (__thiscall*)(CVector*, const CVector &right)) FUNC_CVector__operatorAssignmentCVector)(this, right);
}

// Adds value from the second vector.
void CVector::operator+=(const CVector& right)
{
	( (void (__thiscall*)(CVector*, const CVector &right)) FUNC_CVector__operatorAdditionAssignmentCVector)(this, right);
}

// Multiplies vector by a floating point value
void CVector::operator *= (float multiplier)
{
	( (void (__thiscall*)(CVector*, float multiplier)) FUNC_CVector__operatorMultiplicationAssignmentFloat)(this, multiplier);
}

// Divides vector by a floating point value
void CVector::operator /= (float divisor)
{
	( (void (__thiscall*)(CVector*, float divisor)) FUNC_CVector__operatorDivisionAssignmentFloat)(this, divisor);
}