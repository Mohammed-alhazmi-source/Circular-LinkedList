#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "Global.h"
#include "Validate.h"
#include "Find.h"

class clsSearchScreen : protected clsScreen
{
private:

	static void _PrintNodeCard(Node<string>* NodeCard)
	{
		cout << "\n\nNode Card : " << NodeCard->Data << "\n";
		cout << "---------------------------------------------\n";
		cout << "Data    : " << NodeCard->Data << endl;
		cout << "Next    : " << (NodeCard->Next == nullptr ? "NULL" : NodeCard->Next->Data) << endl;
		cout << "---------------------------------------------";
	}

	static void _ExecuteSearch()
	{
		Validate<string> validate;
		if (validate.IsEmpty(list.Front,list.Tail))
			clsUtil::PrintMessage("\t  Circular Linked List Is Empty");

		else
		{
			string Value = clsInputValidate::ReadString("\n\nPlease Enter The Value You Want To Search For ? ");

			Find<string> findNode;
			Node<string>* Temp = findNode._Node(list.Front, list.Tail, Value);

			if (Temp != nullptr)
				_PrintNodeCard(Temp);

			else
				cout << endl << Value << " Is Not Found :-(\n";
		}
	}

	static void _Search()
	{
		_ExecuteSearch();
	}

public:
	static void ShowSearchScreen()
	{
		system("cls");
		_DrawHeaderScreen("\t\t\t Search Screen");
		_Search();
	}
};