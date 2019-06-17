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
		//저장소 새로 생성, 추가
		int* T = new int[Size * 2];
		for (int i = 0; i < Size; ++i)
		{
			T[i] = Data[i];
		}
		//예전에 작은 저장소 삭제
		delete[] Data;
		Data = T;
		Size = Size * 2;
		Data[Pos++] = NewValue;
	}
	else
	{
		//저장소 충분
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
