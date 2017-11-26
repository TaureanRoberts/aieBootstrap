#pragma once
#include "Entity.h"

class EnemyShip : public Entity
{
public:
	EnemyShip();
	~EnemyShip();
	void mMove(float mTime);
	bool noCrash;
};