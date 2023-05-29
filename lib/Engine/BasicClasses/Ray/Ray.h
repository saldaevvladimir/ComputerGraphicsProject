#pragma once

#include "../../../Math/CoordinateSystem/CoordinateSystem.h"

namespace Engine
{
    class Ray
	{
	public:
		CoordinateSystem cs;
		Point initialPoint;
		Vector direction;

		Ray(CoordinateSystem cs);

		Ray(CoordinateSystem cs, Point inititalPoint, Vector direction);

		void Normalize();
	};
}