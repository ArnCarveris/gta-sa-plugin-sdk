#pragma once
#include "plugin\plugin.h"
#include "CSimpleModelInfo.h"

class PLUGIN_API CTimeModelInfo : public CSimpleModelInfo
{
public:
	tTimeInfo m_timeInfo;

	//

	CTimeModelInfo();
	~CTimeModelInfo();

	//

	void FindOtherTimeModel(char *modelName);
};

VALIDATE_SIZE(CTimeModelInfo, 0x24);