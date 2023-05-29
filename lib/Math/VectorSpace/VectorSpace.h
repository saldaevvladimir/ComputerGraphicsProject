#pragma once

#include "../Matrix/Matrix.h"
#include "../Vector/Vector.h"
#include "../Point/Point.h"


class VectorSpace
{
public:
	Vector* basis;
	int dim;

	VectorSpace();
	VectorSpace(Vector* basis, int dim);

	int Dim();
	bool IsInitialized();

	float ScalarProduct(Vector vec1, Vector vec2);
	Vector VectorProduct(Vector vec1, Vector vec2);

	float Length(Vector vec);
	Vector Normalize(Vector vec);

	Vector AsVector(Point p);

	void operator = (VectorSpace vs);
};