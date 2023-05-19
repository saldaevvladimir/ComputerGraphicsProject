#pragma once

#include "..\Matrix\Matrix.h"


class Vector : public Matrix
{
public:
	bool isTransposed = false;

	using Matrix::operator *;

	Vector();
	Vector(int height);
	Vector(std::initializer_list<float> vector);

	int Dim();
	bool IsTransposed();
	static bool SameDim(Vector vec1, Vector vec2);

	Vector Transpose();
	Vector Rotate(int axisIndex1, int axisIndex2, float angle);
	Vector Rotate3D(float angle1, float angle2, float angle3);
	static float ScalarProduct(Vector vec1, Vector vec2);
	static Vector VectorProduct(Vector vec1, Vector vec2);
	float Length();
	Vector Normalize();


	void operator = (Vector vec);
	void operator = (Matrix mat);
	Vector operator + (Vector vec2);
	Vector operator - (Vector vec2);
	Vector operator * (float num);

	Vector operator / (float num);
	Vector operator ~ ();
	float operator % (Vector vec2);
	Vector operator ^ (Vector vec2);
	bool operator == (Vector vec2);
	bool operator != (Vector vec2);
	friend std::istream& operator >> (std::istream& input, Vector vec);
	friend std::ostream& operator << (std::ostream& output, Vector vec);
	float& operator [] (int index);
};

Vector operator * (float num, Vector vec);