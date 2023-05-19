#include "Functions.h"
#include "..\Accuracy\Accuracy.h"
#include "..\..\Exceptions\MathExceptions\MathException.h"

Matrix Gram(Vector* vectors, int numOfVectors)
{
	if (numOfVectors <= 0)
		throw FunctionsException::InvalidVectorsNumber();
	if (vectors == NULL)
		throw FunctionsException::EmptyArray();

	bool sameDim = true;

	for (int i = 1; i < numOfVectors && sameDim; i++)
		if (!Vector::SameDim(vectors[i - 1], vectors[i]))
			sameDim = false;

	if (!sameDim)
		throw VectorException::DifferentDimensions();
	if (numOfVectors != vectors[0].Dim())
		throw FunctionsException::VectorsNumberIsNotEqualToVectorsDimension();

	Matrix gram(numOfVectors);

	for (int i = 0; i < numOfVectors; i++)
		for (int j = 0; j < numOfVectors; j++)
			gram[i][j] = Vector::ScalarProduct(vectors[i], vectors[j]);

	return gram;
}

float BilinearForm(Matrix mat, Vector vec1, Vector vec2)
{
	if (!mat.IsInitialized())
		throw MatrixException::NotInitialized();
	if (!vec1.IsInitialized() || !vec2.IsInitialized())
		throw VectorException::NotInitialized();
	if (mat.height != vec1.Dim() || mat.width != vec2.Dim())
		throw FunctionsException::IncorrectBilinearFormArguments();

	float res = 0.0f;

	for (int i = 0; i < mat.height; i++)
		for (int j = 0; j < mat.width; j++)
			res += mat[i][j] * vec1[i] * vec2[j];

	return res;
}

Vector Column(Matrix mat, int colIndex)
{
	if (!mat.CorrectIndexes(0, colIndex))
		throw MatrixException::IncorrectElementIndexes();

	Vector column(mat.height);

	for (int r = 0; r < mat.height; r++)
		column[r] = mat[colIndex][r];

	return column;
}