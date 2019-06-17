#pragma once
<<<<<<< HEAD
#include "Actor.h"

class Map : public Actor
=======
class Map
>>>>>>> 0a7ee8af185bcf25429f98853235b5b80e75a83c
{
public:
	Map();
	~Map();
	enum class TYPE
	{
		EMPTY = 0,
		WALL = 1,
		START = 2,
		GOAL = 9
	};

	int Data[10][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 2, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 9, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	};
<<<<<<< HEAD

	virtual void Tick() override;
	virtual void Render() override;

private:
	char GetMapTile(int Type);
=======
>>>>>>> 0a7ee8af185bcf25429f98853235b5b80e75a83c
};

