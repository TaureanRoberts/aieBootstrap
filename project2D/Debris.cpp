#include "Debris.h"

Debris::Debris()
{
	mPos.mX = 10;
	mPos.mY = 10;
	mScale.mX = 50;
	mScale.mY = 50;
	didCrash = true;
}

Debris::~Debris()
{
}

void Debris::mMove(float mTime)
{
    mPos.mX -= 50.0f * mTime;
}