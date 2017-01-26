#pragma once
#include "IConvert.h"

class ImageConverter :public IConvert
{
	string image;

public:
	ImageConverter();
	virtual void SetImage(string image);
	virtual void ClearImage();
	virtual string ConvertImage();
	virtual string GetImage();
};
