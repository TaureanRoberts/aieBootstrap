#include "Debris.h"
#include "time.h"

Debris::Debris()
{
	mPos.mX = 600;
	mPos.mY = 450;
	mScale.mX = 100;
	mScale.mY = 100;
	didCrash = true;

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
	srand((unsigned)time(0));
	int someSpeed = 0;
	for (int i = 0; i < 20; i++)
	{
		someSpeed = (rand() % ((20+1) - 10)+ 10 );
		mPos.mX -= someSpeed * deltaTime;
	}

	return true;
}