#pragma once
#include "Entity.h"

class Debris : public Entity
{
public:
	Debris();
	~Debris();
	void mMove(float deltaTime);
	bool didCrash;
};