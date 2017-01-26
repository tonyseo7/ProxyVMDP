#include "stdafx.h"
#include "ImageConverter.h"
#include <Windows.h>


ImageConverter::ImageConverter(void)
{
	image = "";
}

void ImageConverter::SetImage(string image)
{
	this->image = image;
}

void ImageConverter::ClearImage()
{
	SetImage("");
}

string ImageConverter::ConvertImage()
{
	char buf[256];
	strcpy_s(buf, image.c_str());
	int len = strlen(buf);
	int i = 0;

	for (i = 0; i < len; i++)
	{
		if (isupper(buf[i]))
		{
			Sleep(300);
			buf[i] = buf[i] - ('A' - 'a');
		}
	}

	buf[i] = 0;
	image = buf;
	
	return image;
}

string ImageConverter::GetImage()
{
	return image;

}