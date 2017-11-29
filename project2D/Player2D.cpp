#include "Player2D.h"
#include <Input.h>
#include "Debris.h"
#include "Application2D.h"

Player2D::Player2D()
{
	mPos.mX = 120;
	mPos.mY = 400;
	mScale.mX = 100;
	mScale.mY = 100;
	isAlive = true;
	mDebris = new Debris[15];
	
}

Player2D::~Player2D()
{ 
}

void Player2D::Update(float deltaTime)
{
	aie::Input* input = aie::Input::getInstance();
	Vector2 playerPos(mPos.mX, mPos.mY);
	// use arrow keys to move ship
	if (input->isKeyDown(aie::INPUT_KEY_UP))
		mPos.mY += 500.0f * deltaTime;
	if (input->isKeyDown(aie::INPUT_KEY_DOWN))
		mPos.mY -= 500.0f * deltaTime;

	//Ship Boundries
	if (mPos.mY > 690)
		mPos.mY = 689;
	if (mPos.mY < 30)
		mPos.mY = 29;

}

void Player2D::Collision()
{
	mDebris[15];
	for (int i = 0; i < 2; i++)
	{
		if (mDebris[i].mPos.mY < 0)
			isAlive = false;
		if (mDebris[i].mPos.mY > mPos.mY - (mScale.mY / 2) && mDebris[i].mPos.mY < mPos.mY + (mScale.mY / 2))
		{
			if (mDebris[i].mPos.mX > mPos.mX - (mScale.mX / 2) && mDebris[i].mPos.mX < mPos.mX + (mScale.mX / 2))
				isAlive = false;
		}
	}
}