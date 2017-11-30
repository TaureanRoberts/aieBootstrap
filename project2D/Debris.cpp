#include "Debris.h"
#include <time.h>

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

bool Debris::Move(float deltaTime)
{
	Vector2 playerPos(mPos.mX, mPos.mY);
	for (int i = 0; i < 20; i++)
		mPos.mX -= 4.0f * deltaTime;
	return true;
}

void Debris::RockPos()
{
	Debris *setPos = new Debris[255];
	float setX = 900;
	float setY = 450;
	for (int i = 0; i < 50; i++)
	{
		setPos[i].mPos.mX = setX;
		setPos[i].mPos.mY = setY;
		setX += 100;
		if (setX == 950)
		{
			setX = 450;
			setY -= 100;
		}
	}
}
