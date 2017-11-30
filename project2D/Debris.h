#pragma once
#include "Entity.h"

class Debris : public Entity
{
public:
	Debris();
	~Debris();
	bool Move(float deltaTime);
	void RockPos();
	bool didCrash;
};