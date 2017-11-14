#pragma once
#include <iostream>
using namespace std;
class Vector2
{
public:
	float mX;
	float mY;
	Vector2();
	Vector2(float x, float y);
	Vector2 operator +(Vector2 &other);
	Vector2 operator -(Vector2 &other);
	Vector2 operator *(float &other);
	bool operator ==(Vector2 &other);
	float Dot(Vector2 &other);
	float Magnitude();
	Vector2 Normalize();
	friend ostream& operator << (ostream &output, Vector2 &other);
	friend istream& operator >> (istream &input, Vector2 &other);
};