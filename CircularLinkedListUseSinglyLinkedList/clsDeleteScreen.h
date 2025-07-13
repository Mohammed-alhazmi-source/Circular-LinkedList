#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsDeleteFirstScreen.h"
#include "clsDeleteLastScreen.h"
#include "clsDeleteSpecificNodeScreen.h"
#include "clsClearListScreen.h"
using namespace std;

class clsDeleteScreen : protected clsScreen
{
	enum enDeletionMenuOptions
	{
		DeleteFirst = 1, DeleteLast = 2, DeleteSpecificNode = 3,Clear = 4, MainMenu = 5
	};

	static short _ReadOption()
	{
		return clsUtil::ReadOption(1, 5, "Choose An Operation From 1 To 5 ? ");
	}

	static void _GoBackToDeletionMenu()
	{
		cout << endl;
		system("pause");
		ShowDeletionMenu();
	}

	static void _ShowDeleteFirstScreen()
	{
		clsDeleteFirstScreen::ShowDeleteFirstScreen();
	}

	static void _ShowDeleteLastScreen()
	{
		clsDeleteLastScreen::ShowDeleteLastScreen();
	}

	static void _ShowDeleteSpecificNodeScreen()
	{
		clsDeleteSpecificNodeScreen::ShowDeleteLastScreen();
	}

	static void _ShowClearListScreen()
	{
		clsClearListScreen::ShowClearScreen();
	}

	static void _ExecuteTheSelectedOption(enDeletionMenuOptions Option)
	{
		switch (Option)
		{
		case clsDeleteScreen::DeleteFirst:
		{
			system("cls");
			_ShowDeleteFirstScreen();
			_GoBackToDeletionMenu();
			break;
		}

		case clsDeleteScreen::DeleteLast:
		{
			system("cls");
			_ShowDeleteLastScreen();
			_GoBackToDeletionMenu();
			break;
		}

		case clsDeleteScreen::DeleteSpecificNode:
		{
			system("cls");
			_ShowDeleteSpecificNodeScreen();
			_GoBackToDeletionMenu();
			break;
		}

		case clsDeleteScreen::Clear:
		{
			system("cls");
			_ShowClearListScreen();
			_GoBackToDeletionMenu();
			break;
		}

		case clsDeleteScreen::MainMenu:
		{
			break;
		}
		}
	}

	static void _PrintDeletionMenu()
	{
		cout << "\n\n\n" << setw(42) << left << "" << "======================================";
		cout << "\n" << setw(42) << left << "" << "Enter <1>  Delete First.";
		cout << "\n" << setw(42) << left << "" << "Enter <2>  Delete Last.";
		cout << "\n" << setw(42) << left << "" << "Enter <3>  Delete Specific Node.";
		cout << "\n" << setw(42) << left << "" << "Enter <4>  Clear List.";
		cout << "\n" << setw(42) << left << "" << "Enter <5>  Main Menu.";
		cout << "\n" << setw(42) << left << "" << "======================================";
	}

public:
	static void ShowDeletionMenu()
	{
		system("cls");
		_DrawHeaderScreen("\t\t       Deletion Screen");
		_PrintDeletionMenu();
		_ExecuteTheSelectedOption((enDeletionMenuOptions)_ReadOption());
	}
};