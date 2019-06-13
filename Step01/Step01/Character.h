#pragma once
class Character
{
public:
	Character();
	~Character();

	int Attack;
	int HP;
	int Speed;

	virtual void Move();
};

