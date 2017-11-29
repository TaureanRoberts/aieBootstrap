#pragma once
#include "Entity.h"

class Debris : public Entity
{
public:
	Debris();
	~Debris();
	void Move(float deltaTime);
	void RockPos();
	bool didCrash;
};