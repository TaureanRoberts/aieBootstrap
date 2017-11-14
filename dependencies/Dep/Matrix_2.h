#pragma once
#include <iostream>
using namespace std;
class Matrix2
{
public:
	float mMat[4];
	Matrix2();
	Matrix2(float mat[]);
	Matrix2(float indexA, float indexB, float indexC, float indexD);
	Matrix2 operator +(Matrix2 &other);
	Matrix2 operator -(Matrix2 &other);
	Matrix2 operator *(Matrix2 &other);
	bool operator == (Matrix2 &other);
	friend ostream& operator << (ostream &output, Matrix2 &other);
	friend istream& operator >> (istream &input, Matrix2 &other);
};
