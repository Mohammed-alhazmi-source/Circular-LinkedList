#pragma once
#include "Node.h"
#include "IDeletionServices.h"
#include "Validate.h"
#include "Find.h"

template <typename T>
class Delete : protected IDeletionServices<T>
{
public:
	bool AtBeginning(Node<T>*& Front, Node<T>*& Tail) override
	{
		Validate<T> validate;
		
		if (validate.IsEmpty(Front, Tail))
			return false;

		else if (Front == Tail)
		{
			delete Front;
			Front = Tail = nullptr;
			return true;
		}


		Node<T>* Current = Front;
		Front = Front->Next;

		// ÅÐÇ ÃÕÈÍÊ ÇáÞÇÆãÉ ÊÍÊæí Úáì ÚÞÏÉ æÇÍÏÉ ÝÞØ ÈÚÏ ÇáÍÐÝ
		// äÍÐÝ ÇáÑÇÈØ ÇáÏÇÆÑí ãÄÞÊðÇ áÊÝÇÏí ãÔÇßá ÇáãÄÔÑÇÊ
		if (Current->Next == Tail)
			Tail->Next = nullptr;

		else
			Tail->Next = Front;

		delete Current;
		return true;
	}

	bool AtEnd(Node<T>*& Front, Node<T>*& Tail) override
	{
		Validate<T> validate;
		if (validate.IsEmpty(Front, Tail))
			return false;

		else if (Front == Tail)
		{
			delete Front;
			Front = Tail = nullptr;
			return true;
		}

		Node<T>* deleteTailNode = Tail;
		Node<T>* Previous = Front;

		while (Previous->Next != Tail)
			Previous = Previous->Next;

		Tail = Previous;

		// áÒíÇÏÉ ÇáÇãÇä æÇáÍãÇíÉ ÍÊì ãÇäÌÚá ãÄÔÑ ÇáÚÞÏÉ íÄÔÑ Úáì ãßÇä ÛíÑ ãæÌæÏ Ýí ÇáÐÇßÑÉ
		if (Front == Tail)
			Front->Next = nullptr;

		else
			Tail->Next = Front;

		delete deleteTailNode;

		return true;
	}

	bool AtNode(Node<T>*& Front, Node<T>*& Tail, T ValueNode) override
	{
		Find<T> find;
		Node<T>* Current = find._Node(Front, Tail, ValueNode);
		
		if (Current != nullptr)
		{
			if (Front->Data == ValueNode)
			{
				AtBeginning(Front, Tail);
				return true;
			}
			
			else if (Tail->Data == ValueNode)
			{
				AtEnd(Front, Tail);
				return true;
			}

			Node<T>* Previous = Front;
			while (Previous->Next != Current)
				Previous = Previous->Next;

			Previous->Next = Current->Next;
			delete Current;
			return true;
		}

		return false;
	}
};