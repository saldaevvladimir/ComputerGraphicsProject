#include "..\Accuracy\Accuracy.h"
#include "..\..\Exceptions\MathExceptions\MathException.h"
#include "Matrix.h"
#include <iostream>
#include <cmath>


Matrix::Matrix()
{
	this->height = 0;
	this->width = 0;
}

Matrix::Matrix(int size)
{
	if (!CorrectSizes(size, size))
		throw MatrixException::IncorrectSizes();

	this->height = size;
	this->width = size;
	this->elements = new float* [size];

	for (int r = 0; r < this->height; r++)
	{
		this->elements[r] = new float[size];

		for (int c = 0; c < this->width; c++)
			this->elements[r][c] = 0.0f;
	}
}

Matrix::Matrix(int height, int width)
{
	if (!CorrectSizes(height, width))
		throw MatrixException::IncorrectSizes();

	this->height = height;
	this->width = width;
	this->elements = new float* [this->height];

	for (int r = 0; r < this->height; r++)
	{
		this->elements[r] = new float[this->width];

		for (int c = 0; c < this->width; c++)
			this->elements[r][c] = 0.0f;
	}
}

Matrix::Matrix(std::initializer_list<std::initializer_list<float>> matrix)
{
	int height = matrix.begin()->size();
	int width = 1;

	for (const auto& row : matrix)
		if (row.size() > width)
			width = row.size();

	if (!CorrectSizes(matrix.size(), width))
		throw MatrixException::IncorrectSizes();

	this->height = matrix.size();
	this->width = width;
	this->elements = new float* [this->height];

	for (int i = 0; i < this->height; i++)
		elements[i] = new float[this->width];

	int i = 0, j = 0;

	for (const auto& row : matrix)
	{
		j = 0;

		for (const auto& el : row)
		{
			if (j == this->width) break;

			elements[i][j++] = el;
		}

		for (; j < this->width; j++)
			elements[i][j] = 0.0f;

		i++;
	}
}


bool Matrix::CorrectSizes(int height, int width)
{
	return (height > 0 && width > 0);
}

bool Matrix::CorrectIndexes(int rowIndex, int colIndex)
{
	return (rowIndex >= 0 && rowIndex < this->height)
		&& (colIndex >= 0 && colIndex < this->width);
}

bool Matrix::IsSquare()
{
	return (this->height == this->width);
}

bool Matrix::IsInitialized()
{
	return (CorrectSizes(this->height, this->width));
}

bool Matrix::IsEmpty()
{
	Matrix& self = *this;

	return (self.elements == NULL);
}

bool Matrix::EqualSize(Matrix mat1, Matrix mat2)
{
	return (mat1.height == mat2.height)
		&& (mat1.width == mat2.width);
}

bool Matrix::AreEqual(Matrix mat1, Matrix mat2)
{
	if (!(EqualSize(mat1, mat2)))
		return false;

	for (int r = 0; r < mat1.height; r++)
		for (int c = 0; c < mat1.width; c++)
			if (fabs(mat1[r][c] - mat2[r][c]) > PRECISION)
				return false;

	return true;
}


Matrix Matrix::Identity(int size)
{
	if (!CorrectSizes(size, size))
		throw MatrixException::IncorrectSizes();

	Matrix identity(size, size);
	for (int i = 0; i < size; i++)
		identity[i][i] = 1.0f;

	return identity;
}

Matrix Matrix::Minor(int rowIndex, int colIndex)
{
	Matrix& mat = *this;

	if (!mat.IsInitialized())
		throw MatrixException::NotInitialized();
	if (!mat.IsSquare())
		throw MatrixException::NonSquareMatrixMinor();
	if (!mat.CorrectIndexes(rowIndex, colIndex))
		throw MatrixException::IncorrectElementIndexes();
	if (mat.height == 1)
		throw MatrixException::SingletonMatrixMinor();

	Matrix minor(mat.height - 1, mat.width - 1);

	for (int r = 0; r < mat.height; r++)
	{
		if (r == rowIndex) continue;

		for (int c = 0; c < mat.width; c++)
		{
			if (c == colIndex) continue;

			minor[r - (r > rowIndex ? 1 : 0)][c - (c > colIndex ? 1 : 0)] = mat[r][c];
		}
	}

	return minor;
}

float Matrix::Determinant()
{
	Matrix& self = *this;

	if (!self.IsInitialized())
		throw MatrixException::NotInitialized();
	if (!self.IsSquare())
		throw MatrixException::NonSquareMatrixDeterminant();

	int selfSize = self.height;

	if (selfSize == 1)
		return self[0][0];

	float selfDet = 0.0f;

	for (int c = 0; c < selfSize; c++)
	{
		Matrix submatrix = self.Minor(0, c);
		float submatrixDet = submatrix.Determinant();

		selfDet += submatrixDet * self[0][c] * std::pow(-1, c);
	}

	return std::round(selfDet * DEC) / DEC;
}

Matrix Matrix::Transpose()
{
	Matrix& self = *this;

	if (!self.IsInitialized())
		throw MatrixException::NotInitialized();

	Matrix transposed(self.width, self.height);

	for (int r = 0; r < self.height; r++)
		for (int c = 0; c < self.width; c++)
			transposed[c][r] = self[r][c];

	return transposed;
}

float Matrix::Norm()
{
	Matrix& self = *this;

	if (!self.IsInitialized())
		throw MatrixException::NotInitialized();

	float maxSum = 0.0f;

	for (int r = 0; r < self.height; r++)
	{
		float curSum = 0.0f;

		for (int c = 0; c < self.width; c++)
			curSum += fabs(self[r][c]);

		if (maxSum < curSum)
			maxSum = curSum;
	}

	return maxSum;
}

Matrix Matrix::Inverse()
{
	Matrix& self = *this;

	if (!self.IsInitialized())
		throw MatrixException::NotInitialized();
	if (!self.IsSquare())
		throw MatrixException::NonSquareMatrixInverse();

	float det = self.Determinant();

	if (fabs(det) < PRECISION)
		throw MatrixException::SingularMatrixInverse();

	Matrix inverse(self.height, self.width);

	for (int r = 0; r < self.height; r++)
		for (int c = 0; c < self.width; c++)
		{
			Matrix minor = self.Minor(r, c);
			float d = minor.Determinant();

			inverse[r][c] = std::pow(-1, r + c) * d;
		}

	inverse = inverse.Transpose() / det;

	return inverse;
}

Matrix Matrix::RotationMatrix(int size, int axisIndex1, int axisIndex2, float angle)
{
	if (!CorrectSizes(size, size))
		throw MatrixException::IncorrectSizes();
	if (axisIndex1 < 0 || axisIndex2 < 0 || axisIndex1 == axisIndex2)
		throw MatrixException::IncorrectAxisIndexes();

	Matrix rotationMatrix = Matrix::Identity(size);

	int n = (axisIndex1 + axisIndex2 % 2 == 0);

	rotationMatrix[axisIndex1][axisIndex1] = std::round(DEC * float(cos(angle))) / DEC;
	rotationMatrix[axisIndex2][axisIndex2] = std::round(DEC * float(cos(angle))) / DEC;

	rotationMatrix[axisIndex2][axisIndex1] = std::round(DEC * float(sin(angle) * std::pow(-1, n))) / DEC;
	rotationMatrix[axisIndex1][axisIndex2] = std::round(DEC * float(sin(angle) * std::pow(-1, n + 1))) / DEC;

	return rotationMatrix;
}

Matrix Matrix::TaitBryanMatrix(float angle1, float angle2, float angle3)
{
	int size = 3;

	Matrix TaitBryanMatrix =
		Matrix::RotationMatrix(size, 1, 2, angle3) *
		Matrix::RotationMatrix(size, 0, 2, angle2) *
		Matrix::RotationMatrix(size, 0, 1, angle1);

	return TaitBryanMatrix;
}

void Matrix::Assign(Matrix mat)
{
	this->height = mat.height;
	this->width = mat.width;

	if (mat.IsInitialized())
	{
		this->elements = new float* [this->height];

		for (int r = 0; r < this->height; r++)
		{
			this->elements[r] = new float[this->width];

			for (int c = 0; c < this->width; c++)
			{
				float val = mat.elements[r][c];
				this->elements[r][c] = val;
			}
		}
	}
}

Matrix Matrix::Addition(Matrix mat1, Matrix mat2)
{
	if (!mat1.IsInitialized() || !mat2.IsInitialized())
		throw MatrixException::NotInitialized();
	if (!EqualSize(mat1, mat2))
		throw MatrixException::DifferentDimensions();

	Matrix sum(mat1.height, mat1.width);

	for (int r = 0; r < sum.height; r++)
		for (int c = 0; c < sum.width; c++)
			sum[r][c] = mat1[r][c] + mat2[r][c];

	return sum;
}

Matrix Matrix::Subtraction(Matrix mat1, Matrix mat2)
{
	if (!mat1.IsInitialized() || !mat2.IsInitialized())
		throw MatrixException::NotInitialized();
	if (!EqualSize(mat1, mat2))
		throw MatrixException::DifferentDimensions();

	Matrix sub;
	sub = mat1 + MulByScalar(mat2, (-1.0f));

	return sub;
}

Matrix Matrix::MulByScalar(Matrix mat, float num)
{
	if (!mat.IsInitialized())
		throw MatrixException::NotInitialized();

	Matrix mul;
	mul = mat;

	for (int r = 0; r < mul.height; r++)
		for (int c = 0; c < mul.width; c++)
			mul[r][c] *= num;

	return mul;
}

Matrix Matrix::Division(Matrix mat, float num)
{
	if (!mat.IsInitialized())
		throw MatrixException::NotInitialized();
	if (fabs(num) < PRECISION)
		throw MathException::ZeroDivision();

	return MulByScalar(mat, 1 / num);
}

Matrix Matrix::MatrixMul(Matrix mat1, Matrix mat2)
{
	if (!mat1.IsInitialized() || !mat2.IsInitialized())
		throw MatrixException::NotInitialized();
	if (mat1.width != mat2.height)
		throw MatrixException::MatricesCannotBeMultiplied();

	Matrix mul(mat1.height, mat2.width);

	for (int r = 0; r < mul.height; r++)
		for (int c = 0; c < mul.width; c++)
			for (int k = 0; k < mat1.width; k++)
				mul[r][c] += mat1[r][k] * mat2[k][c];

	return mul;
}


void Matrix::operator = (Matrix mat)
{
	Matrix& self = *this;

	self.Matrix::Assign(mat);
}

Matrix Matrix::operator + (Matrix mat2)
{
	Matrix& mat1 = *this;

	return Matrix::Addition(mat1, mat2);
}

Matrix Matrix::operator - (Matrix mat2)
{
	Matrix& mat1 = *this;

	return Matrix::Subtraction(mat1, mat2);
}

Matrix Matrix::operator * (float num)
{
	Matrix& mat = *this;

	return Matrix::MulByScalar(mat, num);
}

Matrix operator * (float num, Matrix mat)
{
	return Matrix::MulByScalar(mat, num);
}

Matrix Matrix::operator / (float num)
{
	Matrix& mat = *this;

	return Matrix::Division(mat, num);
}

Matrix Matrix::operator * (Matrix mat2)
{
	Matrix& mat1 = *this;

	return Matrix::MatrixMul(mat1, mat2);
}

Matrix Matrix::operator ~ ()
{
	Matrix& self = *this;

	return self.Transpose();
}

Matrix Matrix::operator ! ()
{
	Matrix& self = *this;

	return self.Inverse();
}

bool Matrix::operator == (Matrix mat2)
{
	Matrix& mat1 = *this;

	return (Matrix::AreEqual(mat1, mat2));
}

bool Matrix::operator != (Matrix mat2)
{
	Matrix& mat1 = *this;

	return (!Matrix::AreEqual(mat1, mat2));
}

std::istream& operator >> (std::istream& input, Matrix mat)
{
	if (!mat.IsInitialized())
		throw MatrixException::NotInitialized();

	for (int r = 0; r < mat.height; r++)
		for (int c = 0; c < mat.width; c++)
			input >> mat[r][c];

	return input;
}

std::ostream& operator << (std::ostream& output, Matrix mat)
{
	if (!mat.IsInitialized())
		throw MatrixException::NotInitialized();

	for (int r = 0; r < mat.height; r++)
	{
		for (int c = 0; c < mat.width; c++)
			output << mat[r][c] << " ";

		output << std::endl;
	}

	return output;
}

float*& Matrix::operator [] (int rowIndex)
{
	Matrix& self = *this;

	if (!self.IsInitialized())
		throw MatrixException::NotInitialized();
	if (!self.CorrectIndexes(rowIndex, 0))
		throw MatrixException::IncorrectElementIndexes();

	return self.elements[rowIndex];
}
