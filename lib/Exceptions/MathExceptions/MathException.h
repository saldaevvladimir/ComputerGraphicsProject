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
	static MathException IncorrectSizes(int height, int width);
	static MathException NotInitialized(int height, int width);
	static MathException IncorrectElementIndexes(int matHeight, int matWidth, int rowIndex, int colIndex);
	static MathException EmptyArray();
	static MathException NonSquareMatrixMinor(int height, int width);
	static MathException SingletonMatrixMinor();
	static MathException NonSquareMatrixDeterminant(int height, int width);
	static MathException NonSquareMatrixInverse(int height, int width);
	static MathException SingularMatrixInverse(float det);
	static MathException IncorrectAxisIndexes(int axisIndex1, int axisIndex2);
	static MathException DifferentDimensions(int mat1Height, int mat1width, int mat2Height, int mat2Width);
	static MathException MatricesCannotBeMultiplied(int mat1Height, int mat1width, int mat2Height, int mat2Width);
};

class VectorException : public MathException
{
public:
	static MathException IncorrectSize(int height, int width);
	static MathException NotInitialized(int height, int width);
	static MathException IncorrectElementIndex(int vecHeight, int vecWidth, int index);
	static MathException EmptyArray();
	static MathException DifferentDimensions(int vec1Dim, int vec2Dim);
	static MathException VectorsAreNotThreeDimensional(int vec1Dim, int vec2Dim); // vector product (orthonormal)

};

class VectorSpaceException : public MathException
{
public:
	static MathException EmptyVectorList();
	static MathException NotInitialized(int vsDim);
	static MathException ZeroBasisSize(int vsDim);
	static MathException BasisSizeIsNotEqualToVectorsDimension(int basisSize, int vsDim);
	static MathException BasisDimensionIsNotEqualToThree(int vsDim); // vector product
	static MathException VectorsAreNotThreeDimensional(int vec1Dim, int vec2Dim);   // vector product
};

class FunctionsException : public MathException
{
public:
	static MathException IncorrectVectorsNumber(int numOfVectors);
	static MathException EmptyArray();
	static MathException VectorsNumberIsNotEqualToVectorsDimension(int numOfVectors, int dimOfVectors);
	static MathException IncorrectBilinearFormArguments(int matHeight, int matWidth, int vec1Dim, int vec2Dim);
};

class PointException : public MathException
{
public:
	static MathException NotInitialized(int dim);
	static MathException IncorrectCoordinatesNumber(int numOfCoords);
	//static MathException EmptyArray();
	static MathException IncorrectElementIndex(int pointDim, int elementIndex);
	static MathException DifferentDimensions(int pointDim, int vecDim);
};

class CoordinateSystemException : public MathException
{
public:
	static MathException NotInitialized();
	static MathException DifferentDimension(int basisDim, int initialPointDim);
};