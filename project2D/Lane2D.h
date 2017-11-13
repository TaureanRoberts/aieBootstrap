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
	Lane2D SetX(Lane2D &other);
	Lane2D SetY(Lane2D &other);
};