#include "stdafx.h"
#include "VirtualConverter.h"
#include <Windows.h>

VirtualConverter::VirtualConverter(void)
{
	realconverter = new ImageConverter();
	hThread = INVALID_HANDLE_VALUE;
}

VirtualConverter::~VirtualConverter(void)
{
	CloseHandle(hThread);
	delete realconverter;
}

void VirtualConverter::SetImage(string image)
{
	realconverter->SetImage(image);
}

void VirtualConverter::ClearImage()
{
	realconverter->ClearImage();
}

string VirtualConverter::ConvertImage()
{
	DWORD ThreadID;
	hThread = CreateThread(0, 0, DoIt, realconverter, 0, &ThreadID);
	return "��ȯ�� �����Ͽ����ϴ�.";
}

string VirtualConverter::GetImage()
{
	if (hThread == INVALID_HANDLE_VALUE)
	{
		return "";
	}

	DWORD dw = WaitForSingleObject(hThread, 0);

	if (dw == WAIT_TIMEOUT)
	{
		return "��ȯ��";
	}

	return realconverter->GetImage();
}

DWORD WINAPI VirtualConverter::DoIt(LPVOID pin)
{
	ImageConverter *ic = (ImageConverter*)pin;
	ic->ConvertImage();

	return 0;
}