#pragma once
#include <exception>
#include <string>
#include <iostream>


class MathException : public std::exception
{
public:
	MathException() noexcept;
	MathException(const std::string& message = "...") noexcept;
	virtual const char* what() const throw();
	virtual ~MathException() noexcept;

	static MathException ZeroDivision();

private:
	std::string m_message = "...";
};

class MatrixException : public MathException
{
public:
	static MathException IncorrectSizes();
	static MathException IncorrectElementIndexes();
	static MathException NotInitialized();
	static MathException EmptyArray();
	static MathException NonSquareMatrixMinor();
	static MathException SingletonMatrixMinor();
	static MathException NonSquareMatrixDeterminant();
	static MathException NonSquareMatrixInverse();
	static MathException SingularMatrixInverse();
	static MathException IncorrectAxisIndexes();
	static MathException DifferentDimensions();
	static MathException MatricesCannotBeMultiplied();
};

class VectorException : public MathException
{
public:
	static MathException IncorrectSize();
	static MathException NotInitialized();
	static MathException IncorrectElementIndex();
	static MathException EmptyArray();
	static MathException DifferentDimensions();
	static MathException VectorsAreNotThreeDimensional(); // vector product (orthonormal)

};

class VectorSpaceException : public MathException
{
public:
	static MathException EmptyVectorList();
	static MathException NotInitialized();
	static MathException ZeroBasisSize();
	static MathException BasisSizeIsNotEqualToVectorsDimension();
	static MathException BasisDimensionIsNotEqualToThree(); // vector product
	static MathException VectorsAreNotThreeDimensional();   // vector product
};

class FunctionsException : public MathException
{
public:
	static MathException InvalidVectorsNumber();
	static MathException EmptyArray();
	static MathException VectorsNumberIsNotEqualToVectorsDimension();
	static MathException IncorrectBilinearFormArguments();
};

class PointException : public MathException
{
public:
	static MathException NotInitialized();
	static MathException IncorrectCoordinatesNumber();
	static MathException EmptyArray();
	static MathException IncorrectElementIndex();
	static MathException DifferentDimensions();
};

class CoordinateSystemException : public MathException
{
public:
	static MathException DifferentDimension();
};