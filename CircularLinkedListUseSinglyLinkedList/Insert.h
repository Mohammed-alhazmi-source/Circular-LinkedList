#pragma once
#include "IInsertionServices.h"
#include "Validate.h"
#include "Find.h"
#include "Node.h"

template <typename T>
class Insert : public IInsertionServices<T>
{
public:
	bool AtBeginning(Node<T>*& Front, Node<T>*& Tail, T Item) override
	{
		Node<T>* NewNode = new Node<T>();
		NewNode->Data = Item;

		Validate<T> validate;
		if (validate.IsEmpty(Front, Tail))
		{
			Front = Tail = NewNode;
			return true;
		}

		NewNode->Next = Front;
		Front = NewNode;
		Tail->Next = Front;
		return true;
	}

	bool AtEnd(Node<T>*& Front, Node<T>*& Tail, T Item) override
	{
		Validate<T> validate;
		if (validate.IsEmpty(Front, Tail))
		{
			AtBeginning(Front, Tail, Item);
			return true;
		}

		Node<T>* NewNode = new Node<T>();
		NewNode->Data = Item;
		Tail->Next = NewNode;
		NewNode->Next = Front;
		Tail = NewNode;
		return true;
	}

	bool AtAfter(Node<T>*& Front, Node<T>*& Tail, T ValueNode, T Value) override
	{
		Find<T> find;
		Node<T>* Current = find._Node(Front, Tail, ValueNode);

		if (Current != nullptr)
		{			
			if (Tail->Data == ValueNode)
			{
				AtEnd(Front, Tail, Value);
				return true;
			}

			Node<T>* NewNode = new Node<T>();
			NewNode->Data = Value;
			NewNode->Next = Current->Next;
			Current->Next = NewNode;
			return true;
		}
		return false;
	}

	bool AtBefore(Node<T>*& Front, Node<T>*& Tail, T ValueNode, T Item) override
	{
		Find<T> find;
		Node<T>* Previous = find.PreviousNode(Front, Tail, ValueNode);
		if (Previous != nullptr)
		{						
			if (Front->Data == ValueNode)
			{
				AtBeginning(Front, Tail, Item);
				return true;
			}

			Node<T>* NewNode = new Node<T>();
			NewNode->Data = Item;
			NewNode->Next = Previous->Next;
			Previous->Next = NewNode;
			return true;			
		}

		return false;
	}
};