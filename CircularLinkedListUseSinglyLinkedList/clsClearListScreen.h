#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include "clsScreen.h"
#include "Global.h"
#include "clsUtil.h"
#include "Display.h"
#include "Validate.h"

class clsClearListScreen : protected clsScreen
{
private:
	static void _LoadingBar(const string& Value)
	{
		cout << "\nDeleting Value : " << Value << endl;
		for (short i = 0; i <= 100; i += 9)
		{
			cout << "\rProgress " << i + 1 << "%";
			std::this_thread::sleep_for(std::chrono::milliseconds(300));
		}
	}

	static void _ExecuteClear()
	{
		Validate<string> validate;
		if (validate.IsEmpty(list.Front,list.Tail))
			clsUtil::PrintMessage("\t  Circular Linked List Is Empty");

		else
		{
			char Answer = clsUtil::DoYouWantToContinue("\nDo You Want To Clear List ? y/n ? ");

			if (Answer == 'Y' || Answer == 'y')
			{
				Delete<string> deleteNode;
				while (!validate.IsEmpty(list.Front, list.Tail))
				{
					cout << "\nItems : ";
					Display::Items(list.Front, list.Tail);
					_LoadingBar(list.Front->Data);
					deleteNode.AtBeginning(list.Front,list.Tail);
					system("cls");
					_DrawHeaderScreen("\t\t      Clear List Screen");
				}
				clsUtil::PrintMessage("Completed Clear Circular Linked List");
			}
		}
	}

	static void _Clear()
	{
		_ExecuteClear();
	}

public:
	static void ShowClearScreen()
	{
		system("cls");
		_DrawHeaderScreen("\t\t      Clear List Screen");
		_Clear();
	}
};