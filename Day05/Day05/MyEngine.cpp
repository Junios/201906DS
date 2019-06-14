#include "MyEngine.h"
#include <stdio.h>


MyEngine::MyEngine()
{
	Engine::Init();
	Init();
}


MyEngine::~MyEngine()
{
	Term();
	Engine::Term();
}

bool MyEngine::Init()
{
	return true;
}

bool MyEngine::Term()
{
	return true;
}

bool MyEngine::Run()
{
	Engine::GameLoop();

	return false;
}

void MyEngine::Input()
{
	printf("MyEngine Input()\n");
}
