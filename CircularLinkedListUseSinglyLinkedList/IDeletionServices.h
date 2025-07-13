#pragma once
#include "Node.h"

template <typename T>
class IDeletionServices
{
public:
	bool virtual AtBeginning(Node<T>*& Front, Node<T>*& Tail) = 0;
	bool virtual AtEnd(Node<T>*& Front, Node<T>*& Tail) = 0;
	bool virtual AtNode(Node<T>*& Front, Node<T>*& Tail, T ValueNode) = 0;
};