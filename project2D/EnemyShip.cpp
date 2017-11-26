#include "EnemyShip.h"

EnemyShip::EnemyShip()
{
	mPos.mX = 0;
	mPos.mY = 0;
	mScale.mX = 50;
	mScale.mY = 50;
	noCrash = true;
}

EnemyShip::~EnemyShip()
{
}

void EnemyShip::mMove(float mTime)
{
    mPos.mX -= 50.0f * mTime;
}
