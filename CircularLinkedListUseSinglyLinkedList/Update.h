#pragma once
#include "Node.h"

class Update
{
public:
	template <typename T>
	static bool Node(Node<T>*& NodeSpecific, T Value)
	{
		if (NodeSpecific == nullptr)
			return false;

		NodeSpecific->Data = Value;
		return true;
	}
};