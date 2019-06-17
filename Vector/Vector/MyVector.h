#pragma once
class MyVector
{
public:
	MyVector();
	virtual ~MyVector();

	void PushBack(int NewValue);

	int GetData(size_t GetPos);

	int operator[](size_t GetPos);
	int GetSize();
private:
	int* Data;
	size_t StorageSize;
	size_t Pos;
};

