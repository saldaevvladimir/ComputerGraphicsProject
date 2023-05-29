#include "../Accuracy/Accuracy.h"
#include "../../Exceptions/MathExceptions/MathException.h"
#include "../CoordinateSystem/CoordinateSystem.h"


CoordinateSystem::CoordinateSystem()
{
	this->initialPoint = Point();
	this->space = VectorSpace();
}

CoordinateSystem::CoordinateSystem(Point initial, VectorSpace basis)
{
	if (!basis.IsInitialized())
		throw VectorSpaceException::NotInitialized(basis.Dim());
	if (!initial.IsInitialized())
		throw PointException::NotInitialized(initial.Dim());

	if (basis.Dim() != initial.Dim())
		throw CoordinateSystemException::DifferentDimension(basis.Dim(), initial.Dim());

	this->initialPoint = initial;
	this->space = basis;
}

bool CoordinateSystem::IsInitialized()
{
	return (this->initialPoint.IsInitialized() && this->space.IsInitialized());
}


void CoordinateSystem::operator = (CoordinateSystem cs)
{
	CoordinateSystem& self = *this;

	self.initialPoint = cs.initialPoint;
	self.space = cs.space;
}
