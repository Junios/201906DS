#pragma once
class MyVector
{
public:
	MyVector();
	virtual ~MyVector();

	void PushBack(int NewValue);

	int operator[](size_t GetPos);
	int GetSize();
private:
	int* Data;
	size_t Size;
	size_t Pos;
};

