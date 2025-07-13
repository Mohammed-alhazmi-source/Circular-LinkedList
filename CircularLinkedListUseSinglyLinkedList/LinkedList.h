#pragma once
#include "Node.h"
#include "Clear.h"

template <typename T>
class LinkedList
{
public:
	Node<T>* Front;
	Node<T>* Tail;

	LinkedList() : Front(nullptr), Tail(nullptr) {}

	~LinkedList()
	{
		Clear<T> clear;
		clear.AllNodes(Front, Tail);
	}
};