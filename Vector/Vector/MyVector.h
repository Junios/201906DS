#pragma once
#include <memory.h>

template<typename T>
class MyVector
{
public:
	MyVector();
	virtual ~MyVector();

	void PushBack(T NewValue);
	T operator[](size_t GetPos);

	int GetSize();
private:
	T* Data;
	size_t StorageSize;
	size_t Pos;
};

template<typename T>
MyVector<T>::MyVector()
{
	StorageSize = 100;
	Pos = 0;
	Data = new T[StorageSize];
}

template<typename T>
MyVector<T>::~MyVector()
{
	delete[] Data;
}

template<typename T>
void MyVector<T>::PushBack(T NewValue)
{
	if (Pos == StorageSize)
	{
		//저장소 새로 생성, 추가
		T* Temp = new T[StorageSize * 2];
		memcpy(Temp, Data, Pos * sizeof(T));

		//예전에 작은 저장소 삭제
		delete[] Data;
		Data = Temp;
		StorageSize = StorageSize * 2;
		Data[Pos++] = NewValue;
	}
	else
	{
		//저장소 충분
		Data[Pos++] = NewValue;
	}
}

template<typename T>
T MyVector<T>::operator[](size_t GetPos)
{
	return Data[GetPos];
}

template<typename T>
int MyVector<T>::GetSize()
{
	return Pos;
}


