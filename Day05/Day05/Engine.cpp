#include "Engine.h"



Engine::Engine()
{
	Init();
}


Engine::~Engine()
{
	Term();
}

bool Engine::Init()
{
	bIsRunning = true;

	return true;
}

bool Engine::Term()
{
	return false;
}

bool Engine::Run()
{
	return GameLoop();
}

void Engine::Input()
{
}

void Engine::Tick()
{
}

void Engine::Render()
{
}

bool Engine::GameLoop()
{
	while (bIsRunning)
	{
		Input();
		Tick();
		Render();
	}

	return false;
}
