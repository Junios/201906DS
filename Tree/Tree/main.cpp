#include <iostream>

using namespace std;
class Node
{
public:
	Node* Parent;

	Node* Left;
	Node* Right;

	int Data;
};

class BinaryTree
{
public:
	BinaryTree()
	{
		Root = new Node();
		Root->Data = 1;
	}

	Node* Root;

	void Traversal()
	{
		Traversal(Root);
	}

	Node* Search(int Data)
	{
		return Search(Root, Data);
	}

	void InsertLeft(int SearchData, int Data)
	{
		Node* InsertPoint = Search(SearchData);

		if (InsertPoint)
		{
			InsertPoint->Left = new Node();
			InsertPoint->Left->Data = Data;
			InsertPoint->Left->Parent = InsertPoint;
		}
	}

	void InsertRight(int SearchData, int Data)
	{
		Node* InsertPoint = Search(SearchData);

		if (InsertPoint)
		{
			InsertPoint->Right = new Node();
			InsertPoint->Right->Data = Data;
			InsertPoint->Right->Parent = InsertPoint;
		}
	}


protected:
	Node* Search(Node* Current, int Data)
	{
		if (Current == nullptr)
		{
			return nullptr;
		}

		if (Current->Data == Data)
		{
			return Current;
		}

		Node* Temp;

		Temp = Search(Current->Left, Data);

		if (Temp)
		{
			return Temp;
		}

		Temp = Search(Current->Right, Data);
		if (Temp)
		{
			return Temp;
		}

		return nullptr;
		
	}

	void Traversal(Node* Current)
	{
		if (Current == nullptr)
		{
			return;
		}

		cout << Current->Data << endl; //PreOrder
		Traversal(Current->Left);
		//cout << Current->Data << endl; //InOrder
		Traversal(Current->Right);
		//cout << Current->Data << endl; //PostOrder
	}
};

class BinarySearchTree : public BinaryTree
{
public:
	BinarySearchTree(int Data = 100)
	{
		Root = new Node();
		Root->Data = Data;
		Root->Parent = nullptr;
	}

	void Insert(int Data)
	{
		InsertNode(Root->Parent, Root, Data);
	}

	void InsertNode(Node* Parent, Node* Current, int Data)
	{
		if (Current == nullptr)
		{
			Current = new Node();
			Current->Data = Data;
			Current->Parent = Parent;

			if (Data < Parent->Data)
			{
				Parent->Left = Current;
			}
			else
			{
				Parent->Right = Current;
			}

			return;
		}

		if (Data < Current->Data)
		{
			InsertNode(Current, Current->Left, Data);
		}
		else
		{
			InsertNode(Current, Current->Right, Data);
		}
	}

};

int main()
{
	//BinaryTree Number;

	//Number.InsertLeft(1, 2);
	//Number.InsertRight(1, 3);
	//Number.InsertLeft(2, 4);
	//Number.InsertRight(2, 5);
	//Number.InsertLeft(3, 6);
	//Number.InsertRight(3, 7);

	//Number.Root->Left = new Node();
	//Number.Root->Left->Data = 2;
	//Number.Root->Left->Parent = Number.Root;

	//Number.Root->Right = new Node();
	//Number.Root->Right->Data = 3;
	//Number.Root->Right->Parent = Number.Root;


	//Number.Root->Left->Left = new Node();
	//Number.Root->Left->Left->Data = 4;
	//Number.Root->Left->Left->Parent = Number.Root->Left;

	//Number.Root->Left->Right = new Node();
	//Number.Root->Left->Right->Data = 5;
	//Number.Root->Left->Right->Parent = Number.Root->Left;

	//Number.Root->Right->Left = new Node();
	//Number.Root->Right->Left->Data = 6;
	//Number.Root->Right->Left->Parent = Number.Root->Right;


	//Number.Root->Right->Right = new Node();
	//Number.Root->Right->Right->Data = 7;
	//Number.Root->Right->Right->Parent = Number.Root->Right;

	////Number.Traversal();
	//Node* Temp = Number.Search(3);

	BinarySearchTree SearchTree(10);

	SearchTree.Insert(20);
	SearchTree.Insert(3);
	SearchTree.Insert(34);
	SearchTree.Insert(40);
	SearchTree.Insert(100);
	SearchTree.Insert(25);
	SearchTree.Insert(7);
	SearchTree.Insert(5);
	SearchTree.Insert(6);

	return 0;
}