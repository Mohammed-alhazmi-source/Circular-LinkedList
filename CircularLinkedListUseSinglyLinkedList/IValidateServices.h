#pragma once
#include "Node.h"

template <typename T>
class IValidateServices
{
public:
	bool virtual IsEmpty(Node<T>*& Front, Node<T> *& Tail) const = 0;
	bool virtual IsCircular(Node<T>*&Front,Node<T>*& Current) const = 0;
};