#include <iostream>
#include <stack>
#include <queue>
#include <conio.h>

using namespace std;

#define MAX 10
#define WAY 0
#define WALL 1
#define BLOCK 2
#define PATH 3

class Vector2
{
public:
	Vector2() : x(0), y(0) {}
	Vector2(int _x, int _y ) : x(_x), y(_y) {}
	int x;
	int y;

	Vector2 operator+(const Vector2& RightHandSide)
	{
		Vector2 Result;
		Result.x = this->x + RightHandSide.x;
		Result.y = this->y + RightHandSide.y;

		return Result;
	}
};

enum class Direction
{
	Right	= 0,
	Down	= 1,
	Left	= 2,
	Up		= 3
};

Vector2 Dir[4];


int maze[MAX][MAX] =
{
	{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 1, 1},
	{1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 0, 1, 1, 0, 1, 1},
	{1, 1, 0, 0, 0, 1, 1, 0, 1, 1},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
};

//������ġ���� ������ ������� �̸� �̵� �غ��� 
//�̵� �������� �˷���
bool CanMove(Vector2& Current) 
{
	Vector2 Next;

	//4���� �����̱�
	for(int dir = (int)Direction::Right; dir <= (int)Direction::Up; ++dir)
	{
		Next = Current; // ������ ����
		Next = Next + Dir[dir]; //���� �̵�. Right->Down->Left->Up
		if (Next.x < 0 || Next.y < 0 || Next.x >= MAX || Next.y >= MAX) //�̵� �Ұ��� ��Ȯ����
		{
			continue;//���� ���� ���� ���� �̵�
		}

		if (maze[Next.y][Next.x] == WAY) //�̸� �����°��� ���� �ִ���?
		{
			Current = Next;
			return true;
		}
	}

	return false; //���� ������ ����
}

#define LEVEL			100

bool CanMoveQ(Vector2& NewPosition)
{
	if (NewPosition.x < 0 || NewPosition.y < 0 ||
		NewPosition.x >= MAX || NewPosition.y >= MAX)
	{
		return false;
	}

	if (maze[NewPosition.y][NewPosition.x] == WAY) //���� �����Ƿ� ť�� �ְ� ���� ����
	{
		return true;
	}

	return false;
}


bool TraceMoveQ(Vector2& NewPosition, int Level)
{
	if (NewPosition.x < 0 || NewPosition.y < 0 ||
		NewPosition.x >= MAX || NewPosition.y >= MAX)
	{
		return false;
	}

	if (maze[NewPosition.y][NewPosition.x] == Level) //���� �����Ƿ� ť�� �ְ� ���� ����
	{
		return true;
	}

	return false;
}

int main()
{
	queue<Vector2> Q;
	Vector2 Current;

	Q.push(Current);
	maze[Current.y][Current.x] = LEVEL;
	bool found = false;

	while (!Q.empty())
	{
		Current = Q.front();
		Q.pop();

		int CurrentLevel = maze[Current.y][Current.x];
		Vector2 NewPosition;
		NewPosition = Current + Vector2(1, 0); //Right
		if (CanMoveQ(NewPosition))
		{
			maze[NewPosition.y][NewPosition.x] = CurrentLevel + 1;
			Q.push(NewPosition);
		}

		NewPosition = Current + Vector2(0, 1); //Down
		if (CanMoveQ(NewPosition))
		{
			maze[NewPosition.y][NewPosition.x] = CurrentLevel + 1;
			Q.push(NewPosition);
		}


		NewPosition = Current + Vector2(-1, 0); //Left
		if (CanMoveQ(NewPosition))
		{
			maze[NewPosition.y][NewPosition.x] = CurrentLevel + 1;
			Q.push(NewPosition);
		}


		NewPosition = Current + Vector2(0, -1); //Up
		if (CanMoveQ(NewPosition))
		{
			maze[NewPosition.y][NewPosition.x] = CurrentLevel + 1;
			Q.push(NewPosition);
		}

		if (Current.x == (MAX - 1) && Current.y == (MAX - 1)) //Ż��
		{
			cout << "Ż��" << endl;
			found = true;
			break;
		}
	}

	if (found == false)
	{
		cout << "Ż��Ұ�" << endl;
	}

	//for (int y = 0; y < MAX; ++y)
	//{
	//	for (int x = 0; x < MAX; ++x)
	//	{
	//		cout << maze[y][x] << "  ";
	//	}
	//	cout << endl;
	//}

	int maze_escape[MAX][MAX] = {
		{1,}
	};

	for (int y = 0; y < MAX; ++y)
	{
		for (int x = 0; x < MAX; ++x)
		{
			maze_escape[y][x] = 1;
		}
	}


	Vector2 TracePosition(MAX - 1, MAX - 1);
	maze_escape[TracePosition.y][TracePosition.x] = 0;
	while (true)
	{
		//system("cls");
		//for (int y = 0; y < MAX; ++y)
		//{
		//	for (int x = 0; x < MAX; ++x)
		//	{
		//		cout << maze_escape[y][x] << "  ";
		//	}
		//	cout << endl;
		//}
		//getch();


		int MaxLevel = maze[TracePosition.y][TracePosition.x];

		if (TracePosition.x == 0 && TracePosition.y == 0)
		{
			maze_escape[TracePosition.y][TracePosition.x] = 0;
			break;
		}

		Vector2 Next;
		Next = TracePosition + Vector2(1, 0);
		if (TraceMoveQ(Next, MaxLevel-1))
		{
			TracePosition = Next;
			maze_escape[Next.y][Next.x] = 0;
			continue;
		}

		Next = TracePosition + Vector2(0, 1);
		if (TraceMoveQ(Next, MaxLevel - 1))
		{
			TracePosition = Next;
			maze_escape[Next.y][Next.x] = 0;
			continue;
		}

		Next = TracePosition + Vector2(-1, 0);
		if (TraceMoveQ(Next, MaxLevel - 1))
		{
			TracePosition = Next;
			maze_escape[Next.y][Next.x] = 0;
			continue;
		}

		Next = TracePosition + Vector2(0, -1);
		if (TraceMoveQ(Next, MaxLevel - 1))
		{
			TracePosition = Next;
			maze_escape[Next.y][Next.x] = 0;
			continue;
		}
	}


	for (int y = 0; y < MAX; ++y)
	{
		for (int x = 0; x < MAX; ++x)
		{
			cout << maze_escape[y][x] << "  ";
		}
		cout << endl;
	}


	return 0;
}