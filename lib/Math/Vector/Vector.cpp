#include "..\Accuracy\Accuracy.h"
#include "..\..\Exceptions\MathExceptions\MathException.h"
#include "Vector.h"
#include <cmath>
#include <ostream>
#include <iostream>


Vector::Vector()
{
	this->height = 0;
	this->width = 0;
	this->isTransposed = false;
}

Vector::Vector(int height)
{
	if (!CorrectSizes(height, 1))
		throw VectorException::IncorrectSize(height, 1);

	this->height = height;
	this->width = 1;
	this->isTransposed = false;
	this->elements = new float* [this->height];

	for (int r = 0; r < this->height; r++)
	{
		this->elements[r] = new float[this->width];
		this->elements[r][0] = 0.0f;
	}
}

Vector::Vector(std::initializer_list<float> vector)
{
	if (!CorrectSizes(vector.size(), 1))
		throw VectorException::IncorrectSize(vector.size(), 1);

	this->height = vector.size();
	this->width = 1;
	this->isTransposed = false;
	this->elements = new float* [this->height];

	int i = 0;
	
	for (const auto& el : vector)
	{
		this->elements[i] = new float[this->width];
		this->elements[i++][0] = Round(el);
	}
}


int Vector::Dim()
{
	Vector& vec = *this;
	
	if (!vec.IsInitialized())
		throw VectorException::NotInitialized(vec.height, vec.width);

	return (vec.IsTransposed() ? vec.width : vec.height);
}

bool Vector::IsTransposed()
{
	Vector& vec = *this;

	return (vec.isTransposed);
}

bool Vector::SameDim(Vector vec1, Vector vec2)
{
	if (!vec1.IsInitialized())
		throw VectorException::NotInitialized(vec1.height, vec1.width);
	if (!vec2.IsInitialized())
		throw VectorException::NotInitialized(vec2.height, vec2.width);

	return (vec1.Dim() == vec2.Dim());
}


Vector Vector::Transpose()
{
	Vector& vec = *this;

	if (!vec.IsInitialized())
		throw VectorException::NotInitialized(vec.height, vec.width);

	Vector transposedVec;
	transposedVec = vec.Matrix::Transpose();

	return transposedVec;
}

Vector Vector::Rotate(int axisIndex1, int axisIndex2, float angle)
{
	Vector& self = *this;
	Vector tmp = self;

	if (!self.IsInitialized())
		throw VectorException::NotInitialized(self.height, self.width);

	Matrix rotationMatrix = Matrix::RotationMatrix(tmp.Dim(), axisIndex1, axisIndex2, angle);

	if (!tmp.IsTransposed())
		tmp = tmp.Transpose();

	Matrix tmpMatrix = (tmp * rotationMatrix);

	Vector resultVector;

	if (self.IsTransposed())
		resultVector = tmpMatrix;
	else
		resultVector = tmpMatrix.Transpose();

	return resultVector;
}

Vector Vector::Rotate3D(float angle1, float angle2, float angle3)
{
	Vector& self = *this;
	Vector tmp = self;

	if (!self.IsInitialized())
		throw VectorException::NotInitialized(self.height, self.width);

	Matrix rotationMatrix = Matrix::TaitBryanMatrix(angle1, angle2, angle3);

	if (!tmp.IsTransposed())
		tmp = tmp.Transpose();

	Matrix tmpMatrix = tmp * rotationMatrix;
	
	Vector resultVector;

	if (self.IsTransposed())
		resultVector = tmpMatrix;
	else
		resultVector = tmpMatrix.Transpose();

	return resultVector;
}

float Vector::ScalarProduct(Vector vec1, Vector vec2)
{
	if (!vec1.IsInitialized())
		throw VectorException::NotInitialized(vec1.height, vec1.width);
	if (!vec2.IsInitialized())
		throw VectorException::NotInitialized(vec2.height, vec2.width);
	if (!SameDim(vec1, vec2))
		throw VectorException::DifferentDimensions(vec1.Dim(), vec2.Dim());

	float product = 0.0f;

	for (int i = 0; i < vec1.Dim(); i++)
		product += vec1[i] * vec2[i];

	return Round(product);
}

Vector Vector::VectorProduct(Vector vec1, Vector vec2)
{
	if (!vec1.IsInitialized())
		throw VectorException::NotInitialized(vec1.height, vec1.width);
	if (!vec2.IsInitialized())
		throw VectorException::NotInitialized(vec2.height, vec2.width);
	if (vec1.Dim() != 3 || vec2.Dim() != 3)
		throw VectorException::VectorsAreNotThreeDimensional(vec1.Dim(), vec2.Dim());

	Vector product(3);

	product[0] = Round(vec1[1] * vec2[2] - vec1[2] * vec2[1]);
	product[1] = Round(vec1[2] * vec2[0] - vec1[0] * vec2[2]);
	product[2] = Round(vec1[0] * vec2[1] - vec1[1] * vec2[0]);

	return product;
}

float Vector::Length()
{
	Vector& self = *this;

	if (!self.IsInitialized())
		throw VectorException::NotInitialized(self.height, self.width);

	return Round(sqrt(fabs(Vector::ScalarProduct(self, self))));
}

Vector Vector::Normalize()
{
	Vector& self = *this;

	if (!self.IsInitialized())
		throw VectorException::NotInitialized(self.height, self.width);

	float selfLength = self.Length();

	Vector normalized = self;

	if (fabs(selfLength) < PRECISION)
		return normalized;

	normalized = self / selfLength;

	return normalized;
}


void Vector::operator = (Vector vec)
{
	Vector& self = *this;
	
	self.Matrix::Assign(vec);
	self.isTransposed = vec.isTransposed;
}

void Vector::operator = (Matrix mat)
{
	if (mat.height != 1 && mat.width != 1)
		throw VectorException::IncorrectSize(mat.height, mat.width);

	Vector& self = *this;

	self.Matrix::Assign(mat);
	self.isTransposed = (mat.width == 1 ? false : true);
}

Vector Vector::operator + (Vector vec2)
{
	Vector& vec1 = *this;

	if (!vec1.IsInitialized())
		throw VectorException::NotInitialized(vec1.height, vec1.width);
	if (!vec2.IsInitialized())
		throw VectorException::NotInitialized(vec2.height, vec2.width);
	if (!SameDim(vec1, vec2))
		throw VectorException::DifferentDimensions(vec1.Dim(), vec2.Dim());

	Vector tmpVec2 = vec2;

	if (vec1.IsTransposed() != vec2.IsTransposed())
		tmpVec2 = tmpVec2.Vector::Transpose();

	Vector sum;
	sum = Matrix::Addition(vec1, tmpVec2);

	return sum;
}

Vector Vector::operator - (Vector vec2)
{
	Vector& vec1 = *this;

	if (!vec1.IsInitialized())
		throw VectorException::NotInitialized(vec1.height, vec1.width);
	if (!vec2.IsInitialized())
		throw VectorException::NotInitialized(vec2.height, vec2.width);
	if (!SameDim(vec1, vec2))
		throw VectorException::DifferentDimensions(vec1.Dim(), vec2.Dim());

	Vector tmpVec2 = vec2;

	if (vec1.IsTransposed() != vec2.IsTransposed())
		tmpVec2 = tmpVec2.Vector::Transpose();

	Vector sub;
	sub = Matrix::Subtraction(vec1, tmpVec2);

	return sub;
}

Vector Vector::operator * (float num)
{
	Vector& self = *this;

	if (!self.IsInitialized())
		throw VectorException::NotInitialized(self.height, self.width);

	Vector mul;
	mul = Matrix::MulByScalar(self, num);

	return mul;
}

Vector operator * (float num, Vector vec)
{
	return (vec * num);
}

Vector Vector::operator / (float num)
{
	Vector& self = *this;

	if (!self.IsInitialized())
		throw VectorException::NotInitialized(self.height, self.width);
	if (fabs(num) < PRECISION)
		throw MathException::ZeroDivision();

	Vector div;
	div = Matrix::Division(self, num);

	return div;
}

Vector Vector::operator ~ ()
{
	Vector& self = *this;

	if (!self.IsInitialized())
		throw VectorException::NotInitialized(self.height, self.width);

	return self.Vector::Transpose();
}

float Vector::operator % (Vector vec2)
{
	Vector& vec1 = *this;

	if (!vec1.IsInitialized())
		throw VectorException::NotInitialized(vec1.height, vec1.width);
	if (!vec2.IsInitialized())
		throw VectorException::NotInitialized(vec2.height, vec2.width);
	if (!SameDim(vec2, vec2))
		throw VectorException::DifferentDimensions(vec1.Dim(), vec2.Dim());

	return Vector::ScalarProduct(vec1, vec2);
}

Vector Vector::operator ^ (Vector vec2)
{
	Vector& vec1 = *this;

	if (!vec1.IsInitialized())
		throw VectorException::NotInitialized(vec1.height, vec1.width);
	if (!vec2.IsInitialized())
		throw VectorException::NotInitialized(vec2.height, vec2.width);
	if (vec1.Dim() != 3 || vec2.Dim() != 3)
		throw VectorException::VectorsAreNotThreeDimensional(vec1.Dim(), vec2.Dim());

	return Vector::VectorProduct(vec1, vec2);
}

bool Vector::operator == (Vector vec2)
{
	Vector& vec1 = *this;

	return (Matrix::AreEqual(vec1, vec2) || Matrix::AreEqual(vec1, vec2.Transpose()));
}

bool Vector::operator != (Vector vec2)
{
	Vector& vec1 = *this;

	return (!Matrix::AreEqual(vec1, vec2) && !Matrix::AreEqual(vec1, vec2.Transpose()));
}

std::istream& operator >> (std::istream& input, Vector vec)
{
	if (!vec.IsInitialized())
		throw VectorException::NotInitialized(vec.height, vec.width);

	for (int i = 0; i < vec.Dim(); i++)
	{
		input >> vec[i];
		vec[i] = Round(vec[i]);
	}

	return input;
}

std::ostream& operator << (std::ostream& output, Vector vec)
{
	if (!vec.IsInitialized())
		throw VectorException::NotInitialized(vec.height, vec.width);

	for (int i = 0; i < vec.Dim(); i++)
		output << vec[i] << " ";

	return output;
}

float& Vector::operator [] (int index)
{
	Vector& self = *this;

	if (!self.IsInitialized())
		throw VectorException::NotInitialized(self.height, self.width);
	if (!self.Matrix::CorrectIndexes(0, index) && !self.Matrix::CorrectIndexes(index, 0))
		throw VectorException::IncorrectElementIndex(self.height, self.width, index);

	return (self.IsTransposed() ? self.elements[0][index] : self.elements[index][0]);
}
