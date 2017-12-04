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
		mPos.mY = 31;
}