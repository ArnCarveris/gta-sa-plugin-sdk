#include "CClumpModelInfo.h"

NOINLINE CClumpModelInfo::CClumpModelInfo()
{
	PREPARE_FOR_REDIRECTION();
	//((void (__thiscall *)(CClumpModelInfo *))0x4C56F0)(this);
}

NOINLINE CClumpModelInfo::~CClumpModelInfo()
{
	PREPARE_FOR_REDIRECTION();
	//((void (__thiscall *)(CClumpModelInfo *))0x4C5750)(this);
}

CColModel *CClumpModelInfo::GetCollisionModel()
{
	return ((CColModel *(__thiscall *)(CClumpModelInfo *))this->vtable[15])(this);
}

void CClumpModelInfo::SetClump(RpClump *clump)
{
	((void (__thiscall *)(CClumpModelInfo *, RpClump *))this->vtable[16])(this, clump);
}

void CClumpModelInfo::SetAtomicRendererCB(RpAtomic *atomic, void *renderFunc)
{
	((void (__cdecl *)(RpAtomic *, void *))0x4C5280)(atomic, renderFunc);
}

RwFrame *CClumpModelInfo::FindFrameFromNameCB(RwFrame *frame, void *searchData)
{
	return ((RwFrame *(__cdecl *)(RwFrame *, void *))0x4C52A0)(frame, searchData);
}

RwFrame *CClumpModelInfo::FindFrameFromNameWithoutIdCB(RwFrame *frame, void *searchData)
{
	return ((RwFrame *(__cdecl *)(RwFrame *, void *))0x4C52F0)(frame, searchData);
}

RwFrame *CClumpModelInfo::FindFrameFromIdCB(RwFrame *frame, void *searchData)
{
	return ((RwFrame *(__cdecl *)(RwFrame *, void *))0x4C5350)(frame, searchData);
}

RwFrame *CClumpModelInfo::FillFrameArrayCB(RwFrame *frame, void *data)
{
	return ((RwFrame *(__cdecl *)(RwFrame *, void *))0x4C5390)(frame, data);
}

RwFrame *CClumpModelInfo::GetFrameFromId(RpClump *clump, int id)
{
	return ((RwFrame *(__cdecl *)(RpClump *, int))0x4C53C0)(clump, id);
}

RwFrame *CClumpModelInfo::GetFrameFromName(RpClump *clump, char *name)
{
	return ((RwFrame *(__cdecl *)(RpClump *, char *))0x4C5400)(clump, name);
}

void CClumpModelInfo::FillFrameArray(RpClump *clump, RwFrame **frames)
{
	((void (__cdecl *)(RpClump *, RwFrame **))0x4C5440)(clump, frames);
}

void CClumpModelInfo::SetFrameIds(RwObjectNameIdAssocation *data)
{
	((void (__cdecl *)(RwObjectNameIdAssocation *))0x4C5460)(data);
}