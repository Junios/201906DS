#include "MyVector.h"



MyVector::MyVector()
{
	Size = 100;
	Pos = 0;
	Data = new int[Size];
}


MyVector::~MyVector()
{
	delete[] Data;
}

void MyVector::PushBack(int NewValue)
{
	if (Pos == Size)
	{
		//����� ���� ����, �߰�
		int* T = new int[Size * 2];
		for (int i = 0; i < Size; ++i)
		{
			T[i] = Data[i];
		}
		//������ ���� ����� ����
		delete[] Data;
		Data = T;
		Size = Size * 2;
		Data[Pos++] = NewValue;
	}
	else
	{
		//����� ���
		Data[Pos++] = NewValue;
	}
}

int MyVector::operator[](size_t GetPos)
{
	return Data[GetPos];
}

int MyVector::GetSize()
{
	return Pos;
}
