#pragma once
#include "Entity.h"
#include "Player2D.h"


class Debris : public Entity
{
public:
	Debris();
	Debris(Vector2 pos, Vector2 scale);
	~Debris();
	bool Move(float deltaTime);
	bool didCrash;
	void resetRock(float deltaTime);
};
