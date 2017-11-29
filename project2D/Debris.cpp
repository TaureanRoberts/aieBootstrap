#include "Debris.h"

Debris::Debris()
{
	mPos.mX = 600;
	mPos.mY = 450;
	mScale.mX = 100;
	mScale.mY = 100;
	didCrash = true;
}

Debris::~Debris()
{
}

void Debris::Move(float deltaTime)
{
	Vector2 playerPos(mPos.mX, mPos.mY);
	for (int i = 0; i < 20; i++)
		mPos.mX -= 4.0f * deltaTime;
}

void Debris::RockPos()
{
	float setX = 450;
	float setY = 600;
	for (int i = 0; i < 50; i++)
	{
		mPos.mX = setX;
		mPos.mY = setY;
		setX += 100;
		if (setX == 950)
		{
			setX = 450;
			setY -= 100;
		}
	}
}
