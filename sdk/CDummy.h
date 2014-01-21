#pragma once
#include "sa_sdk.h"
#include "CEntity.h"

#pragma pack(push, 4)
class PLUGIN_API CDummy : public CEntity
{
public:
	CDummy();
	~CDummy();

	void *operator new(unsigned int size);
	void operator delete(void *object);
};
#pragma pack(pop)

VALIDATE_SIZE(CDummy, 0x38);