#pragma once
#include "Entity.h"

class Player2D : public Entity
{
public:
	Player2D();
	~Player2D();
	void Update(float deltaTime);
	bool isAlive;
};