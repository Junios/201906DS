#include "Map.h"
<<<<<<< HEAD
#include "Util.h"
=======
>>>>>>> 0a7ee8af185bcf25429f98853235b5b80e75a83c



Map::Map()
{
}


Map::~Map()
{
}
<<<<<<< HEAD

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
=======
>>>>>>> 0a7ee8af185bcf25429f98853235b5b80e75a83c
