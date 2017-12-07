#include "Debris.h"


Debris::Debris()
{
	mPos.mX = 600;
	mPos.mY = 450;
	mScale.mX = 100;
	mScale.mY = 100;
}

Debris::Debris(Vector2 pos, Vector2 scale)
{
	mPos = pos;
	mScale = scale;
}

Debris::~Debris()
{

}

bool Debris::Move(float deltaTime)
{	
	float someSpeed;
	for (int i = 0; i < 20; i++)
	{
		someSpeed = (rand() % ((35+1) - 10)+ 10);
		mPos.mX -= someSpeed * deltaTime;
	}

	return true;
}

void Debris::resetRock(float deltaTime)
{	
	mPos.mX = 1280;
	mPos.mY = rand() % 720;
}