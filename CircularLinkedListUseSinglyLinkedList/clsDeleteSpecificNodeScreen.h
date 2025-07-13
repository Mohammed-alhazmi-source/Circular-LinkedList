#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "Display.h"
#include "Validate.h"
#include "Delete.h"
#include "Find.h"
using namespace std;

class clsDeleteSpecificNodeScreen : protected clsScreen
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

		string Value = "";
		char DeleteMore = 'n';
		Delete<string> deleteNode;
		Find<string> findNode;
		Node<string>* node = nullptr;

		do
		{
			cout << endl << endl;
			Display::Items(list.Front, list.Tail);

			Value = clsInputValidate::ReadString("\nPlease Enter The Value Shown Above : ");
			node = findNode._Node(list.Front, list.Tail, Value);
			if (node != nullptr)
			{
				DeleteMore = clsUtil::DoYouWantToContinue("\nDo You Want To Delete Specific Node ? y/n ? ");

				if (DeleteMore == 'Y' || DeleteMore == 'y')
				{
					deleteNode.AtNode(list.Front, list.Tail, Value);
					
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
						_DrawHeaderScreen("\t  Delete Specific Node Of List Screen");
					}
				}
			}
			else
			{
				cout << endl << Value << " Is Not Found In List...\n";
				return;
			}

		} while (DeleteMore == 'Y' || DeleteMore == 'y');
	}

	static void _Delete()
	{
		_ExecuteDelete();
	}

public:
	static void ShowDeleteLastScreen()
	{
		system("cls");
		_DrawHeaderScreen("\t    Delete Specific Node Of List Screen");
		_Delete();
	}
};