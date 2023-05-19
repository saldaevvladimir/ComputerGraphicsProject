#pragma once

#include "..\Point\Point.h"
#include "..\VectorSpace\VectorSpace.h"

class CoordinateSystem
{
public:
	Point initialPoint;
	VectorSpace space;

	CoordinateSystem();
	CoordinateSystem(Point initial, VectorSpace basis);

	void operator = (CoordinateSystem cs);
};