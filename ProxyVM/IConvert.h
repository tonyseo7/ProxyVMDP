#pragma once
#include "common.h"

class IConvert
{
public:
	virtual void SetImage(string image) = 0;
	virtual void ClearImage() = 0;
	virtual string ConvertImage() = 0;
	virtual string GetImage() = 0;
};
