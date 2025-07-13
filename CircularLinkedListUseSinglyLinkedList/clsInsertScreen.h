#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsInsertFirstScreen.h"
#include "clsInsertLastScreen.h"
#include "clsInsertBeforeScreen.h"
#include "clsInsertAfterScreen.h"
using namespace std;

class clsInsertScreen : protected clsScreen
{
	enum enInsertionMenuOptions
	{
		InsertFirst = 1, InsertLast = 2, InsertBefore = 3, InsertAfter = 4, MainMenu = 5
	};

	static short _ReadOption()
	{
		return clsUtil::ReadOption(1, 5, "Choose An Operation From 1 To 5 ? ");
	}

	static void _GoBackToInsertionMenu()
	{
		cout << endl;
		system("pause");
		ShowInsertionMenu();
	}

	static void _ShowInsertFirstScreen()
	{
		clsInsertFirstScreen::ShowInsertFirstScreen();
	}

	static void _ShowInsertLastScreen()
	{
		clsInsertLastScreen::ShowInsertLastScreen();
	}

	static void _ShowInsertBeforeScreen()
	{
		clsInsertBeforeScreen::ShowInsertBeforeScreen();
	}

	static void _ShowInsertAfterScreen()
	{
		clsInsertAfterScreen::ShowInsertAfterScreen();
	}

	static void _ExecuteTheSelectedOption(enInsertionMenuOptions Option)
	{
		switch (Option)
		{
		case clsInsertScreen::InsertFirst:
		{
			system("cls");
			_ShowInsertFirstScreen();
			_GoBackToInsertionMenu();
			break;
		}

		case clsInsertScreen::InsertLast:
		{
			system("cls");
			_ShowInsertLastScreen();
			_GoBackToInsertionMenu();
			break;
		}
		case clsInsertScreen::InsertBefore:
		{
			system("cls");
			_ShowInsertBeforeScreen();
			_GoBackToInsertionMenu();
			break;
		}

		case clsInsertScreen::InsertAfter:
		{
			system("cls");
			_ShowInsertAfterScreen();
			_GoBackToInsertionMenu();
			break;
		}



		case clsInsertScreen::MainMenu:
		{
			break;
		}
		}
	}

	static void _PrintInsertionMenu()
	{
		cout << "\n\n\n" << setw(42) << left << "" << "======================================";
		cout << "\n" << setw(42) << left << "" << "Enter <1>  Insert First.";
		cout << "\n" << setw(42) << left << "" << "Enter <2>  Insert Last.";
		cout << "\n" << setw(42) << left << "" << "Enter <3>  Insert Before.";
		cout << "\n" << setw(42) << left << "" << "Enter <4>  Insert After.";
		cout << "\n" << setw(42) << left << "" << "Enter <5>  Main Menu.";
		cout << "\n" << setw(42) << left << "" << "======================================";
	}

public:
	static void ShowInsertionMenu()
	{
		system("cls");
		_DrawHeaderScreen("\t\t      Insertion Screen");
		_PrintInsertionMenu();
		_ExecuteTheSelectedOption((enInsertionMenuOptions)_ReadOption());
	}
};