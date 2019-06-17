#include "Util.h"
#include <windows.h>
#include <stdio.h>

Util::Util()
{
}


Util::~Util()
{
}

void Util::SetXY(int X, int Y)
{
	COORD Cur;
	Cur.X = X;
	Cur.Y = Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

void Util::SetObject(char C)
{
	printf("%c", C);
}

void Util::SetObject(int C)
{
	printf("%c", (char)C);
}
