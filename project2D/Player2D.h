#pragma once
#include "Entity.h"
#include "Debris.h"

class Player2D : public Entity
{
public:
	Player2D();
	~Player2D();
	void Update(float deltaTime);
	void Collision();
	bool isAlive;
	bool isDead;
	Debris *mDebris;
};