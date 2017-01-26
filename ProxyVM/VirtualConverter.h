#pragma once
#include "stdafx.h"
#include "ImageConverter.h"
#include <Windows.h>

class VirtualConverter :public IConvert
{
	ImageConverter *realconverter;		//실제개체
	HANDLE hThread;

public:
	VirtualConverter();
	~VirtualConverter();
	virtual void SetImage(string image);
	virtual void ClearImage();
	virtual string ConvertImage();
	virtual string GetImage();

private:
	static DWORD WINAPI DoIt(LPVOID pin);			//스레드

};
