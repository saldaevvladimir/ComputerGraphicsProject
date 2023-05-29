#pragma once

#include "../Vector/Vector.h"

class Point : public Vector
{
public:
	Point();
	Point(int coordsCount);
	Point(Vector vec);
	Point(std::initializer_list<float>);

	int Dim();
	void operator = (Point p);
	Point operator + (Vector vec);
	Point operator - (Vector vec);
};