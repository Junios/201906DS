#pragma once
class MyVector
{
public:
	MyVector();
	virtual ~MyVector();

	void PushBack(int i);

//private:
	int* Data;
	unsigned int Size;
};

