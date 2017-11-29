#pragma once
#include "Entity.h"

class Enemy2D : public Entity
{
public:
	Enemy2D();
	~Enemy2D();
	void Move(float deltaTime);
	void Wreck();
	bool didCrash;
};