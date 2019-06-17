#pragma once
#include "Engine.h"

class MyEngine : public Engine
{
public:
	MyEngine();
	virtual ~MyEngine();

	virtual bool Init() override;
	virtual bool Term() override;
	virtual bool Run() override;

protected:
	virtual void Input() override;
	virtual void Tick() override;
<<<<<<< HEAD
	virtual void Render() override;
=======
>>>>>>> 0a7ee8af185bcf25429f98853235b5b80e75a83c
};

