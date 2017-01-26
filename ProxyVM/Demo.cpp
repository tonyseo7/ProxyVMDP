#include "stdafx.h"
#include "VirtualConverter.h"

void main()
{
	VirtualConverter *mc = new VirtualConverter();
	VirtualConverter *mc2 = new VirtualConverter();

	mc->SetImage("EVERYDAY IS A HOLIDAY.");
	mc2->SetImage("WELCOME TO EHCLUB.NET");
	mc->ConvertImage();
	mc2->ConvertImage();

	for (int i = 0; i < 4; i++)
	{
		cout << mc->GetImage() << endl;
		cout << mc2->GetImage() << endl;

		Sleep(2000);
	}

	delete mc2;
	delete mc;
}