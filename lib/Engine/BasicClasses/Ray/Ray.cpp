#include "Ray.h"
#include "../../../Exceptions/MathExceptions/MathException.h"


namespace Engine
{
	Ray::Ray(CoordinateSystem cs)
	{
		if (!cs.IsInitialized())
			throw CoordinateSystemException::NotInitialized();

		this->cs = cs;
		this->initialPoint = cs.initialPoint;
		this->direction = cs.space.basis[0];
	}

	Ray::Ray(CoordinateSystem cs, Point initialPoint, Vector direction)
	{
		if (!cs.IsInitialized())
			throw CoordinateSystemException::NotInitialized();
		
		this->cs = cs;
		this->initialPoint = initialPoint;
		this->direction = direction;
	}

	void Ray::Normalize()
	{
		this->direction = this->direction.Normalize();
	}
}