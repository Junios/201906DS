#include "MyVector.h"
#include <memory.h>



MyVector::MyVector()
{
	StorageSize = 100;
	Pos = 0;
	Data = new int[StorageSize];
}


MyVector::~MyVector()
{
	delete[] Data;
}

void MyVector::PushBack(int NewValue)
{
	if (Pos == StorageSize)
	{
		//����� ���� ����, �߰�
		int* T = new int[StorageSize * 2];
		//for (int i = 0; i < Size; ++i)
		//{
		//	T[i] = Data[i];
		//}
		memcpy(T, Data, Pos * sizeof(int));
		//������ ���� ����� ����
		delete[] Data;
		Data = T;
		StorageSize = StorageSize * 2;
		Data[Pos++] = NewValue;
	}
	else
	{
		//����� ���
		Data[Pos++] = NewValue;
	}
}

int MyVector::GetData(size_t GetPos)
{
	return Data[GetPos];
}

int MyVector::operator[](size_t GetPos)
{
	return Data[GetPos];
}

int MyVector::GetSize()
{
	return Pos;
}
