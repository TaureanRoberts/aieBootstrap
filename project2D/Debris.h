#pragma once
#include "Entity.h"

class Debris : public Entity
{
public:
	Debris();
	Debris(Vector2 pos, Vector2 scale);
	~Debris();
	bool Move(float deltaTime);
	bool didCrash;
};