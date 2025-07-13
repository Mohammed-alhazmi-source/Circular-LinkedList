#pragma once
#include "IFindServices.h"
#include "Node.h"
#include "Validate.h"

template <typename T>
class Find : public IFindServices<T>
{
public:
	Node<T>* _Node(Node<T>*& Front, Node<T>*& Tail , T Item) const override
	{
		Validate<T> validate;
		if (validate.IsEmpty(Front, Tail))
			return nullptr;

		else if (Front == Tail && Front->Data == Item)
			return Front;

		else if (Front == Tail && Front->Data != Item)
			return nullptr;

		Node<T>* Current = Front;
		do
		{
			if (Current->Data == Item)
				return Current;
			Current = Current->Next;
		} while (!validate.IsCircular(Front, Current));

		return nullptr;
	}

	Node<T>* PreviousNode(Node<T>*& Front, Node<T>*& Tail, T Item) const override
	{
		Node<T>* Current = _Node(Front, Tail, Item);
		if (Current != nullptr)
		{
			if (Current == Front)
				return Current;

			Validate<T> validate;
			Node<T>* Previous = Front;
			do
			{
				// åäÇ ááÍãÇíÉ ÍÊì ãÇíÚãá ãÞÇÑäÉ ãÚ Çæá ÚÞÏÉ æåæ íÄÔÑ Úáì ÇáÚÞÏÉ ÇáÇÎíÑÉ
				if (Previous->Next == Front)
					break;

				else if (Previous->Next == Current)
					return Previous;

				Previous = Previous->Next;
			} while (!validate.IsCircular(Front, Previous));
		}
		return nullptr;
	}
};