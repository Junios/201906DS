#include <iostream>

using namespace std;

void Swap(int& a, int& b)
{
	int Temp = a;
	a = b;
	b = Temp;
}

void SelectionSort(int* Data, int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = i; j < size; ++j)
		{
			if (Data[i] > Data[j])
			{
				Swap(Data[i], Data[j]);
			}
		}
	}
}

void BubbleSort(int* Data, int size, bool(*fp)(int, int))
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - 1; ++j)
		{
			if (fp(Data[j], Data[j + 1]))
			{
				Swap(Data[j], Data[j + 1]);
			}
		}
	}
}

bool cmp(int a, int b)
{
	return a > b;
}

bool cmp2(int a, int b)
{
	return a < b;
}

void HelloWorld()
{
	cout << "Hello World" << endl;
}

void HelloWorld2()
{
	cout << "¾È³çÇÏ¼¼¿ä." << endl;
}


int partition(int* Data, int begin, int end)
{
	int pivot = Data[end];
	//

	return //pivotÀÇ ÀÎµ¦½º;
}

void QuickSort(int* Data, int begin, int end)
{
	if (begin < end)
	{
		//ÇÇº¿ ¸¸µé±â
		int pivot = partition(Data, begin, end);
		QuickSort(Data, begin, pivot - 1);
		QuickSort(Data, pivot + 1, end);
	}
}



int main()
{
	void(*fp)();

	fp = HelloWorld;
	fp = HelloWorld2;

	fp();

	int Data[10] = { 10, 2, 25, 18,	16,	20,	60,	30,	3, 12 };

	for (int i = 0; i < 10; ++i)
	{
		cout << Data[i] << ", ";
	}
	cout << endl;

	BubbleSort(Data, 10, cmp);

	for (int i = 0; i < 10; ++i)
	{
		cout << Data[i] << ", ";
	}
	cout << endl;

}