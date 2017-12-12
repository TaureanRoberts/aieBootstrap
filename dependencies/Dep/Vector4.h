#pragma once
#include <iostream>
using namespace std;
class Vector4
{
public:
	float mX;
	float mY;
	float mZ;
	float mW;
	Vector4();
	Vector4(float x, float y, float z, float w);
	Vector4 operator +(Vector4 &other);
	Vector4 operator -(Vector4 &other);
	Vector4 operator *(float &other);
	bool operator ==(Vector4 &other);
	float Dot(Vector4 &other);
	float Magnitude();
	Vector4 Normalize();
	friend ostream& operator << (ostream &output, Vector4&other);
	friend istream& operator >> (istream &input, Vector4 &other);
};