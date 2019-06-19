#include "LList.h"



LList::LList()
{
	Head = new Node();
	Tail = new Node();
	Head->Next = Tail;
}


LList::~LList()
{
}

//1. 자료 없을때
//2. 자료 있을때
void LList::Insert(int NewValue)
{
	Node* NewNode = new Node();
	NewNode->Value = NewValue;

	//if (Head->Next == Tail)
	//{
	//	Head->Next = NewNode;
	//	NewNode->Next = Tail;
	//}
	//else
	//{
		Node* Find;
		for (Find = Head; Find->Next != Tail; Find = Find->Next)
		{
		}

		Find->Next = NewNode;
		NewNode->Next = Tail;
		
	//}
}
