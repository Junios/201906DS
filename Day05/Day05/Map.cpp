#include "Map.h"

#include "Util.h"



Map::Map()
{
}


Map::~Map()
{
}

void Map::Tick()
{
}

void Map::Render()
{
	for (int y = 0; y < 10; ++y)
	{
		for (int x = 0; x < 10; ++x)
		{
			Util::SetXY(x, y);
			Util::SetObject(GetMapTile(Data[y][x]));
		}
	}
}

char Map::GetMapTile(int Type)
{
	switch (Type)
	{
		case 0:
			return ' ';
			break;
		case 1:
			return '#';
			break;
		case 2:
			return ' ';
			break;
		case 9:
			return '*';
			break;
	}

	return ' ';
}

