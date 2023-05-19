#include "..\Accuracy\Accuracy.h"
#include "..\..\Exceptions\MathExceptions\MathException.h"
#include "VectorSpace.h"
#include "..\Functions\Functions.h"



VectorSpace::VectorSpace()
{
	this->basis = NULL;
	this->dim = 0;
}

VectorSpace::VectorSpace(Vector* basis, int dim)
{
	if (dim <= 0)
		throw VectorSpaceException::ZeroBasisSize();
	if (basis == NULL)
		throw VectorSpaceException::EmptyVectorList();

	bool sameDim = true;

	for (int i = 1; i < dim && sameDim; i++)
		if (!Vector::SameDim(basis[i - 1], basis[i]))
			sameDim = false;

	if (!sameDim)
		throw VectorException::DifferentDimensions();
	if (basis[0].Dim() != dim)
		throw VectorSpaceException::BasisSizeIsNotEqualToVectorsDimension();

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
	if (!vec1.IsInitialized() || !vec2.IsInitialized())
		throw VectorException::NotInitialized();
	if (!Vector::SameDim(vec1, vec2))
		throw VectorException::DifferentDimensions();

	Matrix gram;
	gram = Gram(this->basis, this->dim);

	Matrix prodMatrix = vec1.Transpose() * gram * vec2;

	return prodMatrix.elements[0][0];
}

Vector VectorSpace::VectorProduct(Vector vec1, Vector vec2)
{
	VectorSpace& vs = *this;

	if (vs.Dim() != 3 || vs.basis == NULL)
		throw VectorSpaceException::BasisDimensionIsNotEqualToThree();
	if (!vec1.IsInitialized() || !vec2.IsInitialized())
		throw VectorException::NotInitialized();
	if (vec1.Dim() != 3 || vec2.Dim() != 3)
		throw VectorSpaceException::VectorsAreNotThreeDimensional();

	Vector product =
		vs.basis[0] * (vec1[1] * vec2[2] - vec1[2] * vec2[1])
		+ vs.basis[1] * (vec1[2] * vec2[0] - vec1[0] * vec2[2])
		+ vs.basis[2] * (vec1[0] * vec2[1] - vec1[1] * vec2[0]);

	return product;
}

Vector VectorSpace::AsVector(Point p)
{
	VectorSpace& vs = *this;

	if (!p.IsInitialized())
		throw PointException::NotInitialized();
	if (!vs.IsInitialized())
		throw VectorSpaceException::NotInitialized();

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
}
