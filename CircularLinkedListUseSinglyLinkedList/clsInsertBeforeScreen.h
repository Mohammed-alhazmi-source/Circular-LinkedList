#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "Global.h"
#include "Validate.h"
#include "Find.h"
#include "Display.h"
#include "Find.h"
using namespace std;

class clsInsertBeforeScreen : protected clsScreen
{
private:

	static void _ExecuteInsert()
	{

		Validate<string> validate;
		if (validate.IsEmpty(list.Front, list.Tail))
		{
			clsUtil::PrintMessage("   Circular LinkedList Is Empty");
			return;
		}

		string NewValue = "", Value = "";
		char InsertMore = 'n';
		cout << "\n\nExit[0].\n\nItems : ";

		Display::Items(list.Front, list.Tail);

		NewValue = clsInputValidate::ReadString("\nPlease Enter New Value : ");

		if (NewValue == "0" || Value == "0")
			return;

		else
		{			
			Value = clsInputValidate::ReadString("\nPlease Enter The Value Shown Above : ");
			Find<string> findNode;
			Node<string>* node = findNode._Node(list.Front, list.Tail, Value);
			
			if (node != nullptr)
			{
				Insert<string> insert;
				insert.AtBefore(list.Front, list.Tail, Value, NewValue);
				cout << "\nSuccessfully...\n";
				return;
			}

			else
			{
				cout << "Value Is Not Found ...";
				return;
			}
		}
	}

	static void _Insert()
	{
		_ExecuteInsert();
	}

public:
	static void ShowInsertBeforeScreen()
	{
		system("cls");
		_DrawHeaderScreen("\t       Insert Before In List Screen");
		_Insert();
	}
};