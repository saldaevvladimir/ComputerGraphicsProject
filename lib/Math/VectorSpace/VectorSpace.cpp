#include "../Accuracy/Accuracy.h"
#include "../../Exceptions/MathExceptions/MathException.h"
#include "VectorSpace.h"
#include "../Functions/Functions.h"

#include <cmath>


VectorSpace::VectorSpace()
{
	this->basis = NULL;
	this->dim = 0;
}

VectorSpace::VectorSpace(Vector* basis, int dim)
{
	if (dim <= 0)
		throw VectorSpaceException::ZeroBasisSize(dim);
	if (basis == NULL)
		throw VectorSpaceException::EmptyVectorList();

	for (int i = 1; i < dim; i++)
		if (!Vector::SameDim(basis[i - 1], basis[i]))
			throw VectorException::DifferentDimensions(basis[i - 1].Dim(), basis[i].Dim());

	if (basis[0].Dim() != dim)
		throw VectorSpaceException::BasisSizeIsNotEqualToVectorsDimension(basis[0].Dim(), dim);

	this->basis = new Vector[dim];
	this->dim = dim;

	for (int i = 0; i < dim; i++)
		this->basis[i] = (basis[i]);
}

int VectorSpace::Dim()
{
	return this->dim;
}

bool VectorSpace::IsInitialized()
{
	VectorSpace& self = *this;

	return (self.Dim() > 0);
}

float VectorSpace::ScalarProduct(Vector vec1, Vector vec2)
{
	if (!vec1.IsInitialized())
		throw VectorException::NotInitialized(vec1.height, vec1.width);
	if (!vec2.IsInitialized())
		throw VectorException::NotInitialized(vec2.height, vec2.width);
	if (!Vector::SameDim(vec1, vec2))
		throw VectorException::DifferentDimensions(vec1.Dim(), vec2.Dim());

	Matrix gram;
	gram = Vector::Gram(this->basis, this->dim);

	Matrix prodMatrix = vec1.Transpose() * gram * vec2;

	return prodMatrix.elements[0][0];
}

Vector VectorSpace::VectorProduct(Vector vec1, Vector vec2)
{
	VectorSpace& vs = *this;

	if (vs.Dim() != 3)
		throw VectorSpaceException::BasisDimensionIsNotEqualToThree(vs.Dim());
	if (!vec1.IsInitialized())
		throw VectorException::NotInitialized(vec1.height, vec1.width);
	if (!vec2.IsInitialized())
		throw VectorException::NotInitialized(vec2.height, vec2.width);
	if (vec1.Dim() != 3 || vec2.Dim() != 3)
		throw VectorSpaceException::VectorsAreNotThreeDimensional(vec1.Dim(), vec2.Dim());

	Vector product =
		vs.basis[0] * (vec1[1] * vec2[2] - vec1[2] * vec2[1])
		+ vs.basis[1] * (vec1[2] * vec2[0] - vec1[0] * vec2[2])
		+ vs.basis[2] * (vec1[0] * vec2[1] - vec1[1] * vec2[0]);

	return product;
}

float VectorSpace::Length(Vector vec)
{
	VectorSpace& vs = *this;

	if (!vs.IsInitialized())
		throw VectorSpaceException::NotInitialized(vs.Dim());
	if (!vec.IsInitialized())
		throw VectorException::NotInitialized(vec.height, vec.width);

	return Round(sqrt(fabs(vs.ScalarProduct(vec, vec))));
}

Vector VectorSpace::Normalize(Vector vec)
{
	VectorSpace& vs = *this;

	if (!vs.IsInitialized())
		throw VectorSpaceException::NotInitialized(vs.Dim());
	if (!vec.IsInitialized())
		throw VectorException::NotInitialized(vec.height, vec.width);

	float vecLength = vs.Length(vec);

	Vector normalized = vec;

	if (fabs(vecLength) < PRECISION)
		return normalized;

	normalized = vec / vecLength;

	return normalized;
}

Vector VectorSpace::AsVector(Point p)
{
	VectorSpace& vs = *this;

	if (!p.IsInitialized())
		throw PointException::NotInitialized(p.Dim());
	if (!vs.IsInitialized())
		throw VectorSpaceException::NotInitialized(vs.Dim());

	Vector result(p.Dim());
	Vector tmp;

	for (int i = 0; i < result.Dim(); i++)
	{
		tmp = vs.basis[i];
		result = result + (tmp * p[i]);
	}

	return result;
}


void VectorSpace::operator = (VectorSpace vs)
{
	VectorSpace& self = *this;

	self.dim = vs.Dim();

	if (vs.IsInitialized())
	{
		self.basis = new Vector[self.dim];

		for (int i = 0; i < self.Dim(); i++)
			self.basis[i] = vs.basis[i];
	}
	else
	{
		self.basis = NULL;
	}
}

