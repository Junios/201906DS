#include <iostream>
#include <stack>

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

int main()
{
	//���� ���� ���� �ʱ�ȭ
	Dir[static_cast<int>(Direction::Right)].x = 1;
	Dir[(int)Direction::Right].y = 0;

	Dir[(int)Direction::Down].x = 0;
	Dir[(int)Direction::Down].y = 1;

	Dir[(int)Direction::Left].x = -1;
	Dir[(int)Direction::Left].y = 0;

	Dir[(int)Direction::Up].x = 0;
	Dir[(int)Direction::Up].y = -1;

	Vector2 Current;

	stack<Vector2> EscapeMap;

	//�˰��� ����
	while (true)
	{
		maze[Current.y][Current.x] = PATH; //���� ��ġ ������ ǥ��
		if (Current.x == MAX - 1 && Current.y == MAX - 1) 
		{
			//������ ���� �ϸ� ��
			break;
		}
		else if (CanMove(Current)) //���� ��ġ �̵� �غ���
		{
			//���� ��ġ�� ������
			//���� ���
			EscapeMap.push(Current);
		}
		else
		{
			if (EscapeMap.empty())
			{
				cout << "Ż��Ұ�" << endl;
				break;
			}
			else
			{
				maze[Current.y][Current.x] = BLOCK; //���� ��ġ�� �� ����
				Current = EscapeMap.top(); //������ġ ����
				EscapeMap.pop();
			}
		}
	}


	for (int y = 0; y < MAX; ++y)
	{
		for (int x = 0; x < MAX; ++x)
		{
			cout << maze[y][x] << " ";
		}
		cout << endl;
	}

	//	{100, 101, 102, 103, 104, 105, 106, 107, 0, 0},
	//	{1, 1, 1, 1, 1, 1, 107, 1, 1, 1},
	//	{1, 1, 1, 1, 1, 1, 108, 1, 1, 1},
	//	{1, 1, 1, 1, 1, 1, 109, 1, 1, 1},
	//	{1, 1, 1, 1, 112, 111, 110, 111, 1, 1},
	//	{1, 1, 1, 1, 113, 1, 1, 112, 1, 1},
	//	{1, 1, 1, 1, 114, 1, 1, 113, 1, 1},
	//	{1, 1, 1, 1, 115, 1, 1, 114, 1, 1},
	//	{1, 1, 0, 0, 116, 1, 1, 115, 1, 1},
	//	{1, 1, 1, 1, 117, 118, 119, 116, 117, 118},


	//1.ť �����
	//ó�� ���� ��ġ�� (���ڸ� ����, 100)
	//ó�� �ʱ�ȭ Ż�ⱸ �� ã��
	//Ž��(ť�� ������� ������)
	//{
	//		ť���� ���� ������(������ġ)
	//		���� ��������
	//		4�����̵�(�ݺ���)
	//		{
	//			�̵�����()
	//			{
	//				������ġ�� ���� ���� + 1 ���ֱ�
	//				������ġ�� ��������?
	//				{
	//					��
	//					Ż�� ����
	//				}
	//				ť�� ���� ��ġ ���
	//			}
	//		}
	//
	//}



	return 0;
}