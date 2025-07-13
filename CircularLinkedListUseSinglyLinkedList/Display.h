#pragma once
#include <iostream>
#include "Node.h"
#include "Validate.h"

using namespace std;

class Display
{
public:

	template <typename T>
	static void Items(Node<T>*& Front, Node<T> *&Tail)
	{
		Validate<T> validate;
		if (validate.IsEmpty(Front, Tail))
		{
			return;
		}

		else if (Front == Tail)
		{
			cout << Front->Data << " -> NULL \n";
			return;
		}

		Node<T>* Current = Front;
		do
		{
			cout << Current->Data;
			
			if (Current->Next != Front)
				cout << " -> ";

			Current = Current->Next;
		} while (!validate.IsCircular(Front, Current));
	}
};