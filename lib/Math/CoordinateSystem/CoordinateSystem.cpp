#include "..\Accuracy\Accuracy.h"
#include "..\..\Exceptions\MathExceptions\MathException.h"
#include "..\CoordinateSystem\CoordinateSystem.h"


CoordinateSystem::CoordinateSystem()
{
	this->initialPoint = Point();
	this->space = VectorSpace();
}

CoordinateSystem::CoordinateSystem(Point initial, VectorSpace basis)
{
	if (!basis.IsInitialized() || !initial.IsInitialized())
		throw VectorSpaceException::NotInitialized();

	if (basis.Dim() != initial.Dim())
		throw CoordinateSystemException::DifferentDimension();

	this->initialPoint = initial;
	this->space = basis;
}


void CoordinateSystem::operator = (CoordinateSystem cs)
{
	CoordinateSystem& self = *this;

	self.initialPoint = cs.initialPoint;
	self.space = cs.space;
}
