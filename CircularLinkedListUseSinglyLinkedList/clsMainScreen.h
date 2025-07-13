#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsInsertScreen.h"
#include "clsDeleteScreen.h"
#include "clsUpdateScreen.h"
#include "clsSearchScreen.h"
#include "clsDisplayScreen.h"
using namespace std;

class clsMainScreen : protected clsScreen
{
	enum enMainMenuOptions
	{
		Insertion = 1, Deletion = 2, Update = 3, Searching = 4, Displaying = 5, Exit = 6
	};

	static short _ReadOption()
	{
		return clsUtil::ReadOption(1, 6, "Choose An Operation From 1 To 6 ? ");
	}

	static void _GoBackToMainMenu()
	{
		cout << endl;
		system("pause");
		ShowMainMenu();
	}

	static void _ShowInsertionScreen()
	{
		clsInsertScreen::ShowInsertionMenu();
	}

	static void _ShowDeletionScreen()
	{
		clsDeleteScreen::ShowDeletionMenu();
	}

	static void _ShowUpdateScreen()
	{
		clsUpdateScreen::ShowUpdateScreen();
	}

	static void _ShowSearchScreen()
	{
		clsSearchScreen::ShowSearchScreen();
	}

	static void _ShowDisplayItemsScreen()
	{
		clsDisplayScreen::ShowDisplayingMenu();
	}

	static void _Exit()
	{
		cout << endl << "--------------------------------------";
		cout << "\nEnd Program :-)";
		cout << endl << "--------------------------------------\n";
	}

	static void _ExecuteTheSelectedOption(enMainMenuOptions Option)
	{
		switch (Option)
		{
		case clsMainScreen::Insertion:
		{
			system("cls");
			_ShowInsertionScreen();
			_GoBackToMainMenu();
			break;
		}

		case clsMainScreen::Deletion:
		{
			system("cls");
			_ShowDeletionScreen();
			_GoBackToMainMenu();
			break;
		}

		case clsMainScreen::Update:
		{
			system("cls");
			_ShowUpdateScreen();
			_GoBackToMainMenu();
			break;
		}

		case clsMainScreen::Searching:
		{
			system("cls");
			_ShowSearchScreen();
			_GoBackToMainMenu();
			break;
		}		

		case clsMainScreen::Displaying:
		{
			system("cls");
			_ShowDisplayItemsScreen();
			_GoBackToMainMenu();
			break;
		}

		case clsMainScreen::Exit:
		{
			system("cls");
			_Exit();
			break;
		}
		}
	}

	static void _PrintMainMenu()
	{
		cout << "\n\n\n" << setw(42) << left << "" << "======================================";
		cout << "\n" << setw(42) << left << "" << "Enter <1> Insertion.";
		cout << "\n" << setw(42) << left << "" << "Enter <2> Deletion.";
		cout << "\n" << setw(42) << left << "" << "Enter <3> Update Item.";
		cout << "\n" << setw(42) << left << "" << "Enter <4> Search Item.";
		cout << "\n" << setw(42) << left << "" << "Enter <5> Displaying.";
		cout << "\n" << setw(42) << left << "" << "Enter <6> Exit.";
		cout << "\n" << setw(42) << left << "" << "======================================";
	}

public:
	static void ShowMainMenu()
	{
		system("cls");
		_DrawHeaderScreen("Circular LinkedList Use Singly LinkedList Screen");
		_PrintMainMenu();
		_ExecuteTheSelectedOption((enMainMenuOptions)_ReadOption());
	}
};