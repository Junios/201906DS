#pragma once
//--------
//| 1  | |
//--------
//--------
//| 2  | |
//--------
//--------
//| 3  | |
//--------
class Node
{
public:
	int Value;

	Node* Next;
};

class LList
{
public:
	LList();
	virtual ~LList();

	void Insert(int NewValue);

	Node* Tail;
	Node* Head;
};

