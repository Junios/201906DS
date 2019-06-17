#include <iostream>
#include <vector>
#include "MyVector.h"

int main()
{
	MyVector v;

	for (int i = 0; i < 1000000000; ++i)
	{
		v.PushBack(i);
	}

	//for (int i = 0; i < v.Size; ++i)
	//{
	//	std::cout << v.Data[i] << std::endl;
	//}




	return 0;
}