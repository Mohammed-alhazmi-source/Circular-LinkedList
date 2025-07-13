#pragma once
#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "Display.h"
#include "clsUtil.h"
#include "Validate.h"

class clsShowElementsRepeatedlyScreen : protected clsScreen
{
private:
	static void _DisplayElementsRepeatedly()
	{
		Validate<string> validate;
		if (validate.IsEmpty(list.Front, list.Tail))
		{
			clsUtil::PrintMessage("\tCircular LinkedList Is Empty");
			return;
		}

		cout << endl << endl << "Items : ";
		Display::Items(list.Front, list.Tail);
		cout << " -> " << list.Tail->Next->Data << " Circular\n";
	}
public:
	static void ShowElementsRepeatedly()
	{
		system("cls");
		_DrawHeaderScreen("\t\tShow Elements Repeatedly Screen");
		_DisplayElementsRepeatedly();
	}
};