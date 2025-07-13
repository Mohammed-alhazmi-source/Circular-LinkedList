#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "Global.h"
#include "Insert.h"
using namespace std;

class clsInsertFirstScreen : protected clsScreen
{
private:

	static void _ExecuteInsert()
	{
		string Value = "";
		char InsertMore = 'n';
		cout << "\n\nExit[0].";
		Insert<string> insert;

		while (true)
		{
			Value = clsInputValidate::ReadString("\nPlease Enter Value : ");

			if (Value == "0")
				break;

			insert.AtBeginning(list.Front, list.Tail, Value);
		}
	}

	static void _Insert()
	{
		_ExecuteInsert();
	}

public:
	static void ShowInsertFirstScreen()
	{
		system("cls");
		_DrawHeaderScreen("\t\t  Insert In First List Screen");
		_Insert();
	}
};