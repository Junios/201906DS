#pragma once
class Engine
{
public:
	Engine();
	virtual ~Engine();

	virtual bool Init();
	virtual bool Term();
	virtual bool Run();


protected:
	bool bIsRunning;

	virtual void Input();
	virtual void Tick();
	virtual void Render();

	virtual bool GameLoop();
};

