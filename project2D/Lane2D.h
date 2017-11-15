#pragma once
#include <Input.h>
#include <Application.h>
#include "Application2D.h"
#include <Renderer2D.h>

class Lane2D 
{
public:
	float mLane[5][5];
	float mX;
	float mY;
	Lane2D();
	Lane2D(float x, float y);
	void DrawGrid(float vert, float hori);
};