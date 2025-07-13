#pragma once
#include "Node.h"

template <typename T>
class IFindServices
{
	virtual Node<T>* _Node(Node<T>*& Front, Node<T>*& Tail , T Item) const = 0;
	virtual Node<T>* PreviousNode(Node<T>*& Front, Node<T>*& Tail , T Item) const = 0;
};