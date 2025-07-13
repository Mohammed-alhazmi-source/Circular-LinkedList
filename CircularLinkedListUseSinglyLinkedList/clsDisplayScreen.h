#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsUtil.h"
#include "clsShowItemsScreen.h"
#include "clsShowElementsRepeatedlyScreen.h"
using namespace std;

class clsDisplayScreen : protected clsScreen
{
private:
	enum enDisplayingMenuOptions { DisplayItems = 1, ElementsRepetition = 2, MainMenu = 3 };

	static short _ReadOption()
	{
		return clsUtil::ReadOption(1, 3, "Choose An Operation From 1 To 3 ? ");
	}

	static void _GoBackToDisplayingMenu()
	{
		cout << endl;
		system("pause");
		ShowDisplayingMenu();
	}

	static void _ShowItemsScreen()
	{
		clsShowItemsScreen::ShowItems();
	}

	static void _ShowElementsRepeatedlyScreen()
	{
		clsShowElementsRepeatedlyScreen::ShowElementsRepeatedly();
	}	

	static void _ExecuteTheSelectedOption(enDisplayingMenuOptions Option)
	{
		switch (Option)
		{
		case clsDisplayScreen::DisplayItems:
		{
			system("cls");
			_ShowItemsScreen();
			_GoBackToDisplayingMenu();
			break;
		}

		case clsDisplayScreen::ElementsRepetition:
		{
			system("cls");
			_ShowElementsRepeatedlyScreen();
			_GoBackToDisplayingMenu();
			break;
		}		

		case clsDisplayScreen::MainMenu:
		{
			break;
		}
		}
	}

	static void _PrintDisplayingMenu()
	{
		cout << "\n\n\n" << setw(42) << left << "" << "======================================";
		cout << "\n" << setw(42) << left << "" << "Enter <1>  Displaying Elements.";
		cout << "\n" << setw(42) << left << "" << "Enter <2>  Displaying Elements Repeatedly.";
		cout << "\n" << setw(42) << left << "" << "Enter <3>  Main Menu.";
		cout << "\n" << setw(42) << left << "" << "======================================";
	}

public:
	static void ShowDisplayingMenu()
	{
		system("cls");
		_DrawHeaderScreen("\t\t      Displaying Screen");
		_PrintDisplayingMenu();
		_ExecuteTheSelectedOption((enDisplayingMenuOptions)_ReadOption());
	}
};