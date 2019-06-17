#include "MyEngine.h"
#include <stdio.h>
#include "Map.h"
#include "Player.h"
#include "Monster.h"
<<<<<<< HEAD
#include <stdlib.h>
=======
>>>>>>> 0a7ee8af185bcf25429f98853235b5b80e75a83c


MyEngine::MyEngine()
{
//	Engine::Init();
	Init();
}


MyEngine::~MyEngine()
{
	Term();
//	Engine::Term();
}

bool MyEngine::Init()
{
	printf("MyEngine Init().\n");
	MapData = new Map();
	Characters.push_back(new Player());
	Characters.push_back(new Monster());


	return true;
}

bool MyEngine::Term()
{
	for (int i = 0; i < Characters.size(); ++i)
	{
		delete Characters[i];
		Characters[i] = nullptr;
	}

	delete MapData;
	MapData = nullptr;

	printf("MyEngine Term().\n");
	return true;
}

bool MyEngine::Run()
{
	Engine::GameLoop();

	return false;
}

void MyEngine::Input()
{
	Engine::Input();

}

void MyEngine::Tick()
{
	//code here
	//Player, Monster bla bla;
<<<<<<< HEAD
	MapData->Tick();

	Engine::Tick();
}

void MyEngine::Render()
{
	Engine::Render();

	system("cls");

	MapData->Render();
=======

	Engine::Tick();
>>>>>>> 0a7ee8af185bcf25429f98853235b5b80e75a83c
}
