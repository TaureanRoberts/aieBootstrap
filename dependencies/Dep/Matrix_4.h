#pragma once
#include <iostream>
using namespace std;
class Matrix4
{
public:
	float mMat[16];
	Matrix4();
	Matrix4(float mat[]);
	Matrix4(float indexA, float indexB, float indexC, float indexD, float indexE, float indexF, float indexG, float indexH, float indexI, float indexJ, float indexK, float indexL, float indexM, float indexN, float indexO, float indexP);
	Matrix4 operator +(Matrix4 &other);
	Matrix4 operator -(Matrix4 &other);
	Matrix4 operator *(Matrix4 &other);
	bool operator == (Matrix4 &other);
	friend ostream& operator << (ostream &output, Matrix4 &other);
	friend istream& operator >> (istream &input, Matrix4 &other);
};