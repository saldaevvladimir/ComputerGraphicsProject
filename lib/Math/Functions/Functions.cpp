#include "Functions.h"
#include "../Accuracy/Accuracy.h"
#include "../../Exceptions/MathExceptions/MathException.h"



float BilinearForm(Matrix mat, Vector vec1, Vector vec2)
{
	if (!mat.IsInitialized())
		throw MatrixException::NotInitialized(mat.height, mat.width);
	if (!vec1.IsInitialized())
		throw VectorException::NotInitialized(vec1.height, vec1.width);
	if (!vec2.IsInitialized())
		throw VectorException::NotInitialized(vec2.height, vec2.width);
	if (mat.height != vec1.Dim() || mat.width != vec2.Dim())
		throw FunctionsException::IncorrectBilinearFormArguments(mat.height, mat.width, vec1.Dim(), vec2.Dim());

	float res = 0.0f;

	for (int i = 0; i < mat.height; i++)
		for (int j = 0; j < mat.width; j++)
			res += mat[i][j] * vec1[i] * vec2[j];

	return Round(res);
}

Vector Column(Matrix mat, int colIndex)
{
	if (!mat.CorrectIndexes(0, colIndex))
		throw MatrixException::IncorrectElementIndexes(mat.height, mat.width, 0, colIndex);

	Vector column(mat.height);

	for (int r = 0; r < mat.height; r++)
		column[r] = mat[colIndex][r];

	return column;
}