#pragma once
class Engine
{
public:
	Engine();
	virtual ~Engine();

	bool Init();
	bool Term();
	bool Run();


private:
	bool bIsRunning;

	void Input();
	void Tick();
	void Render();

	bool GameLoop();
};

