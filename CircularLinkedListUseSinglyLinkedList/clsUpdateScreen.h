#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsInputValidate.h"
#include "clsUtil.h"
#include "Global.h"
#include "Display.h"
#include "Validate.h"
#include "Find.h"
#include "Update.h"

class clsUpdateScreen : protected clsScreen
{
private:
	static void _PrintNodeCard(Node<string>* NodeCard)
	{
		cout << "\n\nNode Card:\n";
		cout << "---------------------------------------------\n";
		cout << "Data    : " << NodeCard->Data << endl;
		cout << "Next    : " << (NodeCard->Next == nullptr ? "NULL" : NodeCard->Next->Data) << endl;
		cout << "---------------------------------------------";
	}

	static void _ExecuteUpdate()
	{
		string Value = "";
		string NewValue = "";
		char Answer = 'n';
		Validate<string> validate;

		if (validate.IsEmpty(list.Front,list.Tail))
			clsUtil::PrintMessage("\t Circular Linked List Is Empty");

		else
		{
			Find<string> findNode;
			Node<string>* Current = nullptr;

			do
			{
				cout << endl << endl << "Items : ";
				Display::Items(list.Front, list.Tail);
				Value = clsInputValidate::ReadString("\nPlease Enter The Value Shown Above : ");
				Current = findNode._Node(list.Front, list.Tail, Value);

				if (Current != nullptr)
				{
					_PrintNodeCard(Current);

					NewValue = clsInputValidate::ReadString("\n\nPlease Enter New Value: ");

					Answer = clsUtil::DoYouWantToContinue("Are You Sure Updated Value ? y/n ? ");

					if (Answer == 'Y' || Answer == 'y')
					{
						Update::Node<string>(Current, NewValue);
						_PrintNodeCard(Current);
						cout << "\n\nUpdated Successfully...\n";
					}

					if (Answer == 'Y' || Answer == 'y')
					{
						Answer = clsUtil::DoYouWantToContinue("Do You Want To Update More ? y/n ? ");
						if (Answer == 'Y' || Answer == 'y')
						{
							system("cls");
							_DrawHeaderScreen("\t\t Update Screen");
						}
					}
				}

				else
				{
					cout << Value << " Not Found:-(\n";
					return;
				}
			} while (Answer == 'Y' || Answer == 'y');
		}
	}

	static void _Update()
	{
		_ExecuteUpdate();
	}

public:
	static void ShowUpdateScreen()
	{
		system("cls");
		_DrawHeaderScreen("\t\t\t Update Screen");
		_Update();
	}
};