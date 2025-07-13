#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "Global.h"
#include "Display.h"
#include "Validate.h"
#include "Delete.h"
using namespace std;

class clsDeleteFirstScreen : protected clsScreen
{
private:

	static void _ExecuteDelete()
	{
		Validate<string> validate;
		if (validate.IsEmpty(list.Front,list.Tail))
		{
			clsUtil::PrintMessage("   Circular Linked List Is Empty");
			return;
		}

		char DeleteMore = 'n';
		Delete<string> deleteNode;
		do
		{
			cout << endl << endl;
			Display::Items(list.Front, list.Tail);
			DeleteMore = clsUtil::DoYouWantToContinue("\nDo You Want To Delete First Node ? y/n ? ");

			if (DeleteMore == 'Y' || DeleteMore == 'y')
			{
				deleteNode.AtBeginning(list.Front, list.Tail);

				if (!validate.IsEmpty(list.Front, list.Tail))
				{
					cout << endl << endl;
					Display::Items(list.Front, list.Tail);
				}

				else if (validate.IsEmpty(list.Front, list.Tail))
				{
					system("cls");
					_DrawHeaderScreen("\t  Delete Specific Node Of List Screen");
					clsUtil::PrintMessage("   Circular Linked List Is Empty");
					return;
				}
			}

			if (DeleteMore == 'Y' || DeleteMore == 'y')
			{
				DeleteMore = clsUtil::DoYouWantToContinue("\nDo You Want To Delete More ? y/n ? ");
				if (DeleteMore == 'Y' || DeleteMore == 'y')
				{
					system("cls");
					_DrawHeaderScreen("\t  Delete In First List Screen");
				}
			}

		} while (DeleteMore == 'Y' || DeleteMore == 'y');
	}

	static void _Delete()
	{
		_ExecuteDelete();
	}

public:
	static void ShowDeleteFirstScreen()
	{
		system("cls");
		_DrawHeaderScreen("\t        Delete In First List Screen");
		_Delete();
	}
};