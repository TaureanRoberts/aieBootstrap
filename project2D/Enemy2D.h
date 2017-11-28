#pragma once
#include "Entity.h"

class Enemy2D : public Entity
{
public:
	Enemy2D();
	~Enemy2D();
	void mMove(float deltaTime);
	bool didCrash;
};