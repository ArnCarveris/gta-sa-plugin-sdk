#include "CSimpleTransform.h"

void CSimpleTransform::UpdateRwMatrix(RwMatrix *out)
{
	((void (__thiscall *)(CSimpleTransform *, RwMatrix *))0x54EF40)(this, out);
}

void CSimpleTransform::Invert(CSimpleTransform const& base)
{
	((void (__thiscall *)(CSimpleTransform *, CSimpleTransform const&))0x54EF90)(this, base);
}

void CSimpleTransform::UpdateMatrix(CMatrix *out)
{
	((void (__thiscall *)(CSimpleTransform *, CMatrix *))0x54F1B0)(this, out);
}