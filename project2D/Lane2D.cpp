#include <iostream>
#include "Lane2D.h"
#include <Input.h>
#include <Texture.h>
#include <Renderer2D.h>
#include "Application2D.h"
#include <Vector_2.h>

using namespace std;

Lane2D::Lane2D()
{
	mLane[5][5];
}

Lane2D::Lane2D(float x, float y)
{
	mX = x;
	mY = y;
}

void Lane2D::DrawGrid(float vert, float hori)
{
	cout << mLane[0][0] << mLane[0][1] << mLane[0][2] << mLane[0][3] << mLane[0][4] << endl;
	cout << mLane[1][0] << mLane[1][1] << mLane[1][2] << mLane[1][3] << mLane[1][4] << endl;
	cout << mLane[2][0] << mLane[2][1] << mLane[2][2] << mLane[2][3] << mLane[2][4] << endl;
	cout << mLane[3][0] << mLane[3][1] << mLane[3][2] << mLane[3][3] << mLane[3][4] << endl;
	cout << mLane[4][0] << mLane[4][1] << mLane[4][2] << mLane[4][3] << mLane[4][4] << endl;
}
