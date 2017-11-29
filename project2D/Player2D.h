#pragma once
#include "Entity.h"
#include "Debris.h"

class Player2D : public Entity
{
public:
	Player2D();
	~Player2D();
	void Update(float deltaTime);
	void Collision(float deltaTime);
	bool isAlive;
	int mRock;
	Debris *mDebris;
};