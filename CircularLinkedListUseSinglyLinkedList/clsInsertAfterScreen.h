#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "Global.h"
#include "Display.h"
#include "clsUtil.h"
#include "Validate.h"
#include "Insert.h"
#include "Find.h"
using namespace std;

class clsInsertAfterScreen : protected clsScreen
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
			Find<string> findNode;
			Value = clsInputValidate::ReadString("\nPlease Enter The Value Shown Above : ");
			Node<string>* node = findNode._Node(list.Front, list.Tail, Value);

			if (node != nullptr)
			{
				Insert<string> insert;
				insert.AtAfter(list.Front, list.Tail, Value, NewValue);
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
	static void ShowInsertAfterScreen()
	{
		system("cls");
		_DrawHeaderScreen("\t       Insert After In List Screen");
		_Insert();
	}
};