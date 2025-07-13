#pragma once
#include "Node.h"
#include "IValidateServices.h"

template <typename T>
class Validate : protected IValidateServices<T>
{
public:
	bool IsEmpty(Node<T>*& Front, Node<T>*& Tail) const override
	{
		return (Front == nullptr && Tail == nullptr);
	}

	bool IsCircular(Node<T>*& Front, Node<T>*& Current) const override
	{
		return (Front == Current);
	}
};