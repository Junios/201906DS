#include <stdio.h>
#include "Engine.h"

int main()
{
	Engine* engine = new Engine();

	delete engine;
	engine = nullptr;

	return 0;
}