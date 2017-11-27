#include "Enemy2D.h"

Enemy2D::Enemy2D()
{
	mPos.mX = 0;
	mPos.mY = 0;
	mScale.mX = 50;
	mScale.mY = 50;
	didCrash = true;
}

Enemy2D::~Enemy2D()
{
}

void Enemy2D::mMove(float mTime)
{
	mPos.mX -= 80.0f * mTime;
}