#include "Point.h"
#include "..\Accuracy\Accuracy.h"
#include "..\..\Exceptions\MathExceptions\MathException.h"


Point::Point()
{
	this->height = 0;
	this->width = 0;
}

Point::Point(int coordsCount)
{
	if (!CorrectSizes(coordsCount, 1))
		throw PointException::IncorrectCoordinatesNumber();

	this->height = coordsCount;
	this->width = 1;
	this->elements = new float* [this->height];

	for (int i = 0; i < coordsCount; i++)
	{
		this->elements[i] = new float[this->width];
		this->elements[i][0] = 0;
	}
}

Point::Point(Vector vec)
{
	if (!vec.IsInitialized())
		throw VectorException::NotInitialized();

	this->height = vec.Dim();
	this->width = 1;
	this->elements = new float* [this->height];

	for (int i = 0; i < this->height; i++)
	{
		this->elements[i] = new float[this->width];
		this->elements[i][0] = vec[i];
	}
}

Point::Point(std::initializer_list<float> coords)
{
	if (!CorrectSizes(coords.size(), 1))
		throw PointException::IncorrectCoordinatesNumber();

	this->height = coords.size();
	this->width = 1;
	this->elements = new float* [this->height];

	int i = 0;

	for (const auto& el : coords)
	{
		this->elements[i] = new float[this->width];
		this->elements[i++][0] = el;
	}
}\

int Point::Dim()
{
	Point& self = *this;

	if (!self.IsInitialized())
		throw PointException::NotInitialized();

	return (self.Vector::Dim());
}


void Point::operator = (Point p)
{
	this->height = p.height;
	this->width = p.width;

	this->elements = new float* [this->height];

	for (int i = 0; i < this->height; i++)
	{
		this->elements[i] = new float[this->width];
		this->elements[i][0] = p[i];
	}
}

Point Point::operator + (Vector vec)
{
	Point& self = *this;

	if (!self.IsInitialized())
		throw PointException::NotInitialized();
	if (!vec.IsInitialized())
		throw VectorException::NotInitialized();
	if (self.Dim() != vec.Dim())
		throw PointException::DifferentDimensions();

	Point sum(self.Dim());

	for (int i = 0; i < sum.Dim(); i++)
		sum[i] = self[i] + vec[i];

	return sum;
}

Point Point::operator - (Vector vec)
{
	Point& self = *this;

	if (!self.IsInitialized())
		throw PointException::NotInitialized();
	if (!vec.IsInitialized())
		throw VectorException::NotInitialized();
	if (self.Dim() != vec.Dim())
		throw PointException::DifferentDimensions();

	Point sub(self.Dim());

	for (int i = 0; i < sub.Dim(); i++)
		sub[i] = self[i] - vec[i];

	return sub;
}
