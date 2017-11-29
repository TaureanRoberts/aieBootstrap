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

void Enemy2D::Move(float deltaTime)
{
	Vector2 playerPos(mPos.mX, mPos.mY);
	for (int i = 0; i < 20; i++)
		mPos.mX -= 20.0f * deltaTime;
		
}

void Enemy2D::Wreck()
{

}
