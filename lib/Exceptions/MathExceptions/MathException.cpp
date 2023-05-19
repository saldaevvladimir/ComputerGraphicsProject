#include "MathException.h"
#include <string>


MathException::MathException() noexcept {};

MathException::MathException(const std::string& message) noexcept
{
	m_message = message;
}

const char* MathException::what() const throw()
{
	return m_message.c_str();
}

MathException::~MathException() noexcept {};

MathException MathException::ZeroDivision()
{
	return MathException("division by zero");
}



MathException MatrixException::IncorrectSizes()
{
	return MathException("incorrect matrix sizes");
}

MathException MatrixException::NotInitialized()
{
	return MathException("matrix is not initialized");
}

MathException MatrixException::IncorrectElementIndexes()
{
	return MathException("invalid indexes of matrix element");
}

MathException MatrixException::EmptyArray()
{
	return MathException("array of matrix elements is empty");
}

MathException MatrixException::NonSquareMatrixMinor()
{
	return MathException("non-square matrix has no minors");
}

MathException MatrixException::SingletonMatrixMinor()
{
	return MathException("singleton (1x1) matrix has no minors");
}

MathException MatrixException::NonSquareMatrixDeterminant()
{
	return MathException("non-square matrix has no determinant");
}

MathException MatrixException::NonSquareMatrixInverse()
{
	return MathException("non-square matrix has no inverse");
}

MathException MatrixException::SingularMatrixInverse()
{
	return MathException("singular matrix has no inverse");
}

MathException MatrixException::IncorrectAxisIndexes()
{
	return MathException("invalid axis indexes");
}

MathException MatrixException::DifferentDimensions()
{
	return MathException("matrices have different dimensions: method defined for matrices with equal dimensions");
}

MathException MatrixException::MatricesCannotBeMultiplied()
{
	return MathException("matrices cannot be multiplied");
}


MathException VectorException::IncorrectSize()
{
	return MathException("invalid vector size");
}

MathException VectorException::NotInitialized()
{
	return MathException("vector is not initialized");
}

MathException VectorException::IncorrectElementIndex()
{
	return MathException("invalid index of vector element");
}

MathException VectorException::EmptyArray()
{
	return MathException("array of vectors elements is empty");
}

MathException VectorException::DifferentDimensions()
{
	return MathException("vectors have different dimensions: method is defined for vectors, which dimensions are equal");
}

MathException VectorException::VectorsAreNotThreeDimensional()
{
	return MathException("vector product (orthonormal) is only for three-dimensional vectors");
}


MathException VectorSpaceException::EmptyVectorList()
{
	return MathException("list of vectors is empty");
}

MathException VectorSpaceException::NotInitialized()
{
	return MathException("vector is not initialized");
}

MathException VectorSpaceException::ZeroBasisSize()
{
	return MathException("basis size is equal to zero");
}

MathException VectorSpaceException::BasisSizeIsNotEqualToVectorsDimension()
{
	return MathException("number of vectors in basis is not equal to vectors dimension");
}

MathException VectorSpaceException::BasisDimensionIsNotEqualToThree()
{
	return MathException("vector product (not orthonormal) is only for three dimensional basis");
}

MathException VectorSpaceException::VectorsAreNotThreeDimensional()
{
	return MathException("vector product (not orthonormal) is only for three-dimensional vectors");
}


MathException FunctionsException::InvalidVectorsNumber()
{
	return MathException("invalid number of vectors");
}

MathException FunctionsException::EmptyArray()
{
	return MathException("array of vectors is empty");
}

MathException FunctionsException::VectorsNumberIsNotEqualToVectorsDimension()
{
	return MathException("vectors number is not equal to vectors dimension");
}

MathException FunctionsException::IncorrectBilinearFormArguments()
{
	return MathException("matrix height (width) is not equal to dimension of the first (second) vector");
}


MathException PointException::NotInitialized()
{
	return MathException("point is not initialized");
}

MathException PointException::IncorrectCoordinatesNumber()
{
	return MathException("invalid coordinates number");
}

MathException PointException::EmptyArray()
{
	return MathException("array of point coordinates is empty");
}

MathException PointException::IncorrectElementIndex()
{
	return MathException("invalid index of point coordinate");
}

MathException PointException::DifferentDimensions()
{
	return MathException("point and vector have different dimensions");
}


MathException CoordinateSystemException::DifferentDimension()
{
	return MathException("point and vector have different dimension");
}

