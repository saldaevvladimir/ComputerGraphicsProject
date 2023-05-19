#include "Ray.h"


namespace Engine
{
	Ray::Ray(CoordinateSystem cs)
	{
		this->cs = cs;
		this->initialPoint = cs.initialPoint;
		this->direction = cs.space.basis[0];
	}

	Ray::Ray(CoordinateSystem cs, Point initialPoint, Vector direction)
	{
		this->cs = cs;
		this->initialPoint = initialPoint;
		this->direction = direction;
	}

	void Ray::Normalize()
	{
		this->direction = this->direction.Normalize();
	}
}