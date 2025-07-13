#pragma once
#include "Delete.h"
#include "Node.h"
#include "Validate.h"

template <typename T>
class Clear
{
public:
	static bool AllNodes(Node<T>*& Front, Node<T>*& Tail)
	{
		Validate<T> validate;
		if (validate.IsEmpty(Front, Tail))
			return false;

		Delete<T> deleteNode;		
		while(Front != nullptr) //!validate.IsEmpty(Front, Tail)
		{
			deleteNode.AtBeginning(Front, Tail);
		}
		return true;
	}
};