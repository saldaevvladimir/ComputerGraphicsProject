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

// MatrixException

MathException MatrixException::IncorrectSizes(int height, int width)
{
	return MathException("incorrect matrix sizes: " + std::to_string(height) + "x" + std::to_string(width));
}

MathException MatrixException::NotInitialized(int height, int width)
{
	return MathException("matrix is not initialized (matrix sizes: " + std::to_string(height) + "x" + std::to_string(width) + ")");
}

MathException MatrixException::IncorrectElementIndexes(int matHeight, int matWidth, int rowIndex, int colIndex)
{
	return MathException("incorrect indexes of matrix element (matrix sizes: " + std::to_string(matHeight) + "x" + std::to_string(matWidth) + 
	" element indexes: " + std::to_string(rowIndex) + " " + std::to_string(colIndex) + ")");
}

MathException MatrixException::EmptyArray()
{
	return MathException("array of matrix elements is empty (= NULL)");
}

MathException MatrixException::NonSquareMatrixMinor(int height, int width)
{
	return MathException("non-square matrix has no minors (matrix sizes: " + std::to_string(height) + "x" + std::to_string(width) + ")");
}

MathException MatrixException::SingletonMatrixMinor()
{
	return MathException("singleton matrix has no minors (matrix sizes: 1x1)");
}

MathException MatrixException::NonSquareMatrixDeterminant(int height, int width)
{
	return MathException("non-square matrix has no determinant (matrix sizes: " + std::to_string(height) + "x" + std::to_string(width) + ")");
}

MathException MatrixException::NonSquareMatrixInverse(int height, int width)
{
	return MathException("non-square matrix has no inverse (matrix sizes: " + std::to_string(height) + "x" + std::to_string(width) + ")");
}

MathException MatrixException::SingularMatrixInverse(float det)
{
	return MathException("singular matrix has no inverse (matrix determinant: " + std::to_string(det) + ")");
}

MathException MatrixException::IncorrectAxisIndexes(int axisIndex1, int axisIndex2)
{
	return MathException("incorrect axis indexes: " + std::to_string(axisIndex1) + " " + std::to_string(axisIndex2));
}

MathException MatrixException::DifferentDimensions(int mat1Height, int mat1width, int mat2Height, int mat2Width)
{
	return MathException("matrices have different dimensions: " 
	+ std::to_string(mat1Height) + "x" + std::to_string(mat1width) + " " 
	+ std::to_string(mat2Height) + "x" + std::to_string(mat2Width));
}

MathException MatrixException::MatricesCannotBeMultiplied(int mat1Height, int mat1width, int mat2Height, int mat2Width)
{
	return MathException("matrices cannot be multiplied (matrix sizes: " 
	+ std::to_string(mat1Height) + "x" + std::to_string(mat1width) + " " 
	+ std::to_string(mat2Height) + "x" + std::to_string(mat2Width) + ")");
}

// VectorException

MathException VectorException::IncorrectSize(int height, int width)
{
	return MathException("incorrect vector size (vector sizes: " + std::to_string(height) + "x" + std::to_string(width) + ")");
}

MathException VectorException::NotInitialized(int height, int width)
{
	return MathException("vector is not initialized (vector sizes: " + std::to_string(height) + "x" + std::to_string(width) + ")");
}

MathException VectorException::IncorrectElementIndex(int vecHeight, int vecWidth, int index)
{
	return MathException("incorrect index of vector element (vector sizes: " + std::to_string(vecHeight) + "x" + std::to_string(vecWidth) + " "
	+ "element index: " + std::to_string(index) + ")");
}

MathException VectorException::EmptyArray()
{
	return MathException("array of vectors elements is empty (= NULL)");
}

MathException VectorException::DifferentDimensions(int vec1Dim, int vec2Dim)
{
	return MathException("vectors have different dimensions: method is defined for vectors, which dimensions are equal (given vectors dimensions: "
	+ std::to_string(vec1Dim) + " " + std::to_string(vec2Dim) +  ")");
}

MathException VectorException::VectorsAreNotThreeDimensional(int vec1Dim, int vec2Dim)
{
	return MathException("vector product (orthonormal) is only for three-dimensional vectors (given vectors dimensions: " 
	+ std::to_string(vec1Dim) + " " + std::to_string(vec2Dim) + ")");
}

// VectorSpaceException

MathException VectorSpaceException::EmptyVectorList()
{
	return MathException("list of vectors is empty (= NULL)");
}

MathException VectorSpaceException::NotInitialized(int vsDim)
{
	return MathException("vector space is not initialized (vector space dimension: " + std::to_string(vsDim) + ")");
}

MathException VectorSpaceException::ZeroBasisSize(int vsDim)
{
	return MathException("basis size is equal to zero (basis size: " + std::to_string(vsDim) + ")");
}

MathException VectorSpaceException::BasisSizeIsNotEqualToVectorsDimension(int basisSize, int vsDim)
{
	return MathException("number of vectors in basis is not equal to vectors dimension (basis size: " 
	+ std::to_string(basisSize) + "vectors dimension: " + std::to_string(vsDim) + ")");
}

MathException VectorSpaceException::BasisDimensionIsNotEqualToThree(int vsDim)
{
	return MathException("vector product (not orthonormal) is only for three dimensional basis (basis dimension: " + std::to_string(vsDim) + ")");
}

MathException VectorSpaceException::VectorsAreNotThreeDimensional(int vec1Dim, int vec2Dim)
{
	return MathException("vector product (not orthonormal) is only for three-dimensional vectors (vectors dimensions: "
	+ std::to_string(vec2Dim) + " " + std::to_string(vec2Dim) + ")");
}

// FunctionsException

MathException FunctionsException::IncorrectVectorsNumber(int numOfVectors)
{
	return MathException("incorrect number of vectors: " + std::to_string(numOfVectors));
}

MathException FunctionsException::EmptyArray()
{
	return MathException("array of vectors is empty");
}

MathException FunctionsException::VectorsNumberIsNotEqualToVectorsDimension(int numOfVectors, int dimOfVectors)
{
	return MathException("vectors number is not equal to vectors dimension (number of vectors: " 
	+ std::to_string(numOfVectors) + " vectors dimension: " + std::to_string(dimOfVectors) + ")");
}

MathException FunctionsException::IncorrectBilinearFormArguments(int matHeight, int matWidth, int vec1Dim, int vec2Dim)
{
	return MathException("matrix height (width) is not equal to dimension of the first (second) vector (matrix sizes: "
	+ std::to_string(matHeight) + "x" + std::to_string(matWidth) + " vectors dimension: "
	+ std::to_string(vec1Dim) + " " + std::to_string(vec2Dim) + ")");
}

// PointException

MathException PointException::NotInitialized(int dim)
{
	return MathException("point is not initialized (point dimension: " + std::to_string(dim) + ")");
}

MathException PointException::IncorrectCoordinatesNumber(int numOfCoords)
{
	return MathException("incorrect coordinates number: " + std::to_string(numOfCoords));
}

// MathException PointException::EmptyArray()
// {
// 	return MathException("array of point coordinates is empty");
// }

MathException PointException::IncorrectElementIndex(int pointDim, int elementIndex)
{
	return MathException("incorrect index of point coordinate (point dimension: " 
	+ std::to_string(pointDim) + " elementIndex: " + std::to_string(elementIndex) + ")");
}

MathException PointException::DifferentDimensions(int pointDim, int vecDim)
{
	return MathException("point and vector have different dimensions (point dimension: "
	+ std::to_string(pointDim) + " vector dimension: " + std::to_string(vecDim) + ")");
}

// CoordinateSystemException

MathException CoordinateSystemException::NotInitialized()
{
	return MathException("coordinate system is not initialized");
}

MathException CoordinateSystemException::DifferentDimension(int basisDim, int initialPointDim)
{
	return MathException("basis and initial point have different dimension (basis dimension: "
	+ std::to_string(basisDim) + " initial point dimension: " + std::to_string(initialPointDim) + ")");
}

