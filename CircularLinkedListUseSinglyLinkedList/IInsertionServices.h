#pragma once
#include "Node.h"

template <typename T>
class IInsertionServices
{
public:
	bool virtual AtBeginning(Node<T>*& Front, Node<T>*& Tail, T Item) = 0;
	bool virtual AtEnd(Node<T>*& Front, Node<T>*& Tail, T Item) = 0;
	bool virtual AtAfter(Node<T>*& Front, Node<T>*& Tail, T ValueNode, T Item) = 0;
	bool virtual AtBefore(Node<T>*& Front, Node<T>*& Tail, T ValueNode, T Item) = 0;
};

