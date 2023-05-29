#include "Point.h"
#include "../Accuracy/Accuracy.h"
#include "../../Exceptions/MathExceptions/MathException.h"


Point::Point()
{
	this->height = 0;
	this->width = 0;
}

Point::Point(int coordsCount)
{
	if (!CorrectSizes(coordsCount, 1))
		throw PointException::IncorrectCoordinatesNumber(coordsCount);

	this->height = coordsCount;
	this->width = 1;
	this->elements = new float* [this->height];

	for (int i = 0; i < coordsCount; i++)
	{
		this->elements[i] = new float[this->width];
		this->elements[i][0] = 0.0f;
	}
}

Point::Point(Vector vec)
{
	if (!vec.IsInitialized())
		throw VectorException::NotInitialized(vec.height, vec.width);

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
		throw PointException::IncorrectCoordinatesNumber(coords.size());

	this->height = coords.size();
	this->width = 1;
	this->elements = new float* [this->height];

	int i = 0;

	for (const auto& el : coords)
	{
		this->elements[i] = new float[this->width];
		this->elements[i++][0] = Round(el);
	}
}\

int Point::Dim()
{
	Point& self = *this;

	if (!self.IsInitialized())
		throw PointException::NotInitialized(self.Dim());

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
		throw PointException::NotInitialized(self.Dim());
	if (!vec.IsInitialized())
		throw VectorException::NotInitialized(vec.height, vec.width);
	if (self.Dim() != vec.Dim())
		throw PointException::DifferentDimensions(self.Dim(), vec.Dim());

	Point sum(self.Dim());

	for (int i = 0; i < sum.Dim(); i++)
		sum[i] = Round(self[i] + vec[i]);

	return sum;
}

Point Point::operator - (Vector vec)
{
	Point& self = *this;

	if (!self.IsInitialized())
		throw PointException::NotInitialized(self.Dim());
	if (!vec.IsInitialized())
		throw VectorException::NotInitialized(vec.height, vec.width);
	if (self.Dim() != vec.Dim())
		throw PointException::DifferentDimensions(self.Dim(), vec.Dim());

	Point sub(self.Dim());

	for (int i = 0; i < sub.Dim(); i++)
		sub[i] = Round(self[i] - vec[i]);

	return sub;
}
