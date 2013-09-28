#include "CBulletTraces.h"

CBulletTrace *CBulletTraces::aTraces = (CBulletTrace *)0xC7C748;

static void AddTrace(CVector *start, CVector *end, float radius, unsigned int time, unsigned char transparency)
{
	((void (__cdecl *)(CVector *, CVector *, float, unsigned int, unsigned char))0x723750)(start, end, radius, time, transparency);
}

static void Render()
{
	((void (__cdecl *)())0x723C10)();
}

static void Update()
{
	((void (__cdecl *)())0x723FB0)();
}