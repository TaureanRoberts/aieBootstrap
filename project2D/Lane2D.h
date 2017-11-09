#pragma once
#include <Input.h>
#include "Application2D.h"
#include <Renderer2D.h>

class Lane2D
{
public:
	float mLane[3][7];
	float mX;
	float mY;
	Lane2D();
	Lane2D(float x, float y);
	Lane2D GetX(Lane2D &other);
	Lane2D GetY(Lane2D &other);
};