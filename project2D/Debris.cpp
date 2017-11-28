#include "Debris.h"

Debris::Debris()
{
	mPos.mX = 0;
	mPos.mY = 0;
	mScale.mX = 100;
	mScale.mY = 100;
	didCrash = true;
}

Debris::~Debris()
{
}

void Debris::mMove(float deltaTime)
{
	Vector2 playerPos(mPos.mX, mPos.mY);
	for (int i = 0; i < 20; i++)
		mPos.mX -= 4.0f * deltaTime;
}