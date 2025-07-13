#pragma once

template <typename T>
class Node
{
public:
	T Data;
	Node* Next;

	Node() : Data(T()), Next(nullptr) {}
};

