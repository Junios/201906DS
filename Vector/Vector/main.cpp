#include <iostream>
#include <vector>
#include "MyVector.h"

int main()
{

	//std::vector<int> vInt;

	//vInt[1] = 1;
	//for (int i = 0; i < 1000; ++i)
	//{
	//	vInt.push_back(1);
	//}


	MyVector v;

	for (int i = 0; i < 100; ++i)
	{
		v.PushBack(i);
	}

	for (int i = 0; i < v.GetSize(); ++i)
	{
		std::cout << v[i] << std::endl;
	}




	return 0;
}