#include "MyVector.h"



MyVector::MyVector()
{
	Size = 0;
	Data = nullptr;
}


MyVector::~MyVector()
{
}

void MyVector::PushBack(int NewValue)
{
	Size++;
	if (Data == nullptr)
	{
		Data = new int[1];
		Data[0] = NewValue;
		return;
	}

	int* T = nullptr;

	T = new int[Size];

	for (int i = 0; i < Size - 1; ++i)
	{
		T[i] = Data[i];
	}
	delete[] Data;

	Data = T;
	Data[Size-1] = NewValue;
}
