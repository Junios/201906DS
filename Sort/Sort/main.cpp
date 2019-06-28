#include <iostream>

using namespace std;

template<typename T>
void Swap(T& a, T& b)
{
	T Temp = a;
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


template<typename T>
int partition(T* data, int begin, int end, bool (*fp)(T, T))
{
	T pivot = data[end];
	int min = begin - 1;
	for (int cursor = begin; cursor <= end - 1; ++cursor)
	{
		if (fp(data[cursor], pivot))
		{
			min++;
			Swap(data[min], data[cursor]);
		}
	}

	Swap(data[min + 1], data[end]);

	return min + 1;
}

template<typename T>
void QuickSort(T* Data, int begin, int end, bool(*fp)(T, T))
{
	if (begin < end)
	{
		//ÇÇº¿ ¸¸µé±â
		int pivot = partition(Data, begin, end, fp);
		QuickSort(Data, begin, pivot - 1, fp);
		QuickSort(Data, pivot + 1, end, fp);
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

	QuickSort<int>(Data, 0, 9, cmp2);

	for (int i = 0; i < 10; ++i)
	{
		cout << Data[i] << ", ";
	}
	cout << endl;

}