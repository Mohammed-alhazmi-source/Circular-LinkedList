#pragma once
#include <iostream>
#include "clsScreen.h"
#include "Global.h"
#include "Display.h"
#include "clsUtil.h"
#include "Validate.h"

class clsShowItemsScreen : protected clsScreen
{
private:
	static void _DisplayItems()
	{
		Validate<string> validate;
		if (validate.IsEmpty(list.Front, list.Tail))
		{
			clsUtil::PrintMessage("\tCircular LinkedList Is Empty");
			return;
		}

		cout << endl << endl << "Items : ";
		Display::Items(list.Front, list.Tail);
	}
public:
	static void ShowItems()
	{
		system("cls");
		_DrawHeaderScreen("\t\t\tShow Items Screen");
		_DisplayItems();
	}
};