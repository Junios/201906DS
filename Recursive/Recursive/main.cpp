//#include <iostream>
//
//using namespace std;
//
////Sum
//// 1+ 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + 10;
//// 10 + Sum(10-1)
//// 10 + 9 + Sum(9-1)....
//// 10 + 9 + Sum(9-1)...... 1 + Sum(0)
//
//int Sum(int n)
//{
//	return n == 0 ? 0 : n + Sum(n - 1);
//	//if (n == 0)
//	//{
//	//	return 0;
//	//}
//	//else
//	//{
//	//	return n + Sum(n - 1);
//	//}
//}
//
//
//// 1 1 2 3 5 8 13 21 34 55
//int Fibo(int n)
//{
//	if (n == 0)
//	{
//		return 0;
//	}
//	else if (n == 1)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fibo(n - 1) + Fibo(n - 2);
//	}
//}
//
//void Binary(int n)
//{
//	if (n < 2)
//	{
//		cout << n;
//	}
//	else
//	{
//		Binary(n / 2);
//		cout << (n % 2);
//	}
//}
//
//void ReversePrint(const char* s)
//{
//	if (s[0] == '\0')
//	{
//		return;
//	}
//	else
//	{
//		//ReversePrint(&s[1]);
//		ReversePrint(s + 1);
//		cout << s[0];
//	}
//}
//
//
//int gcd(int a, int b)
//{
//	return b ? gcd(b, a%b) : a;
//}
//
////찾으면 찾은 인덱스
////없으면 -1
////for
//int Search(int* Data, int Begin, int End, int Target)
//{
//	for (int i = Begin; i < End; ++i)
//	{
//		if (Data[i] == Target)
//		{
//			return i;
//		}
//	}
//
//	return -1;
//}
//
////Recursive
//int Search2(int* Data, int Begin, int End, int Target)
//{
//	if (Data[Begin] == Target)
//	{
//		return Begin;
//	}
//	else if (Begin > End)
//	{
//		return -1;//	}
//	else
//	{
//		return Search2(Data, Begin + 1, End, Target);
//	}
//}
//
//int Search3(int* Data, int Begin, int End, int Target)
//{
//	if (Data[End] == Target)
//	{
//		return End;
//	}
//	else if (Begin > End)
//	{
//		return -1;
//	}
//	else
//	{
//		return Search3(Data, Begin, End - 1, Target);
//	}
//}
//
////정렬 되어 있는 데이터를 찾을떄 
//int BinarySearch(int* Data, int Begin, int End, int Target)
//{
//	if (Begin > End)
//	{
//		return -1;
//	}
//	else
//	{
//		int Middle = (Begin + End) / 2; //가운데에 검색 숫자 있으면
//		if (Data[Middle] == Target)
//		{
//			return Middle;
//		}
//		else if (Data[Middle] > Target)
//		{
//			return BinarySearch(Data, Begin, Middle - 1, Target); //Middle보다 작은수 찾을때
//		}
//		else
//		{
//			return BinarySearch(Data, Middle + 1, End, Target); //Middle보다 큰수 찾을때
//		}
//	}
//}
//
//
//
//int main()
//{
//	int Data[10] = { 1,2,3,4,5,6,7,8,9,10 };
//
//	cout << BinarySearch(Data, 0, 9, 3) << endl;
//
//
//	return 0;
//}

#include <iostream>

using namespace std;

#define MAX 10
#define WAY 0
#define WALL 1
#define BLOCK 2
#define PATH 3

int maze[MAX][MAX] =
{
	{0, 0, 0, 0, 0, 0, 0, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 0, 1, 1, 0, 1, 1, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 1, 1},
	{1, 0, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 0, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 0, 0, 0, 0, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
};

bool FindMaze(int x, int y)
{
	if (x < 0 || y < 0 || x > MAX - 1 || y > MAX - 1) //배열 범위 체크
	{
		return false;
	}
	else if (maze[y][x] != WAY) //길이 아님
	{
		return false;
	}
	else if (x == MAX - 1 && y == MAX - 1) //목적지면
	{
		maze[y][x] = PATH;
		return true;
	}
	else //이동
	{
		maze[y][x] = PATH;
		if (FindMaze(x + 1, y)) //오른쪽 이동
		{
			//cout << "(" << x << ", " << y << ")" << endl;
			return true;
		}
		else if (FindMaze(x, y + 1)) //아래
		{
			//cout << "(" << x << ", " << y << ")" << endl;
			return true;
		}
		else if (FindMaze(x - 1, y))	 //왼쪽
		{
			//cout << "(" << x << ", " << y << ")" << endl;
			return true;
		}
		else if (FindMaze(x, y - 1))	 //위
		{
			//cout << "(" << x << ", " << y << ")" << endl;
			return true;
		}
		else
		{
			maze[y][x] = BLOCK; //못 가는길
			return false;
		}
	}


	return true;
}

void PrintMap()
{
	for (int y = 0; y < MAX; ++y)
	{
		for (int x = 0; x < MAX; ++x)
		{
			cout << maze[y][x] << " ";
		}
		cout << endl;
	}
}

int main()
{
	FindMaze(0, 0);

	PrintMap();
}