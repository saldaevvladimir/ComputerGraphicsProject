#pragma once
#define _USE_MATH_DEFINES

#define RxAxis 1,2
#define RyAxis 0,2
#define RzAxis 0,1

#include <vector>
#include <iostream>



class Matrix
{
public:
	int height;
	int width;
	float** elements;

	Matrix();
	Matrix(int size);
	Matrix(int height, int width);
	Matrix(std::initializer_list<std::initializer_list<float>> matrix);

	static bool CorrectSizes(int height, int width);
	bool CorrectIndexes(int rowIndex, int colIndex);
	bool IsSquare();
	bool IsInitialized();
	bool IsEmpty();
	static bool EqualSize(Matrix mat1, Matrix mat2);
	static bool AreEqual(Matrix mat1, Matrix mat2);

	static Matrix Identity(int size);
	Matrix Minor(int rowIndex, int colIndex);
	float Determinant();
	Matrix Transpose();
	float Norm();
	Matrix Inverse();

	static float ConvertToRadian(float angle);
	static Matrix RotationMatrix(int size, int axisIndex1, int axisIndex2, float angle);
	static Matrix TaitBryanMatrix(float angle1, float angle2, float angle3);
	static Matrix RotationYZ(float angle);
	static Matrix RotationXZ(float angle);
	static Matrix RotationXY(float angle);

	void Assign(Matrix mat);
	static Matrix Addition(Matrix mat1, Matrix mat2);
	static Matrix Subtraction(Matrix mat1, Matrix mat2);
	static Matrix MulByScalar(Matrix mat, float num);
	Matrix Division(Matrix mat, float num);
	static Matrix MatrixMul(Matrix mat1, Matrix mat2);


	void operator = (Matrix mat);
	Matrix operator + (Matrix mat2);
	Matrix operator - (Matrix mat2);
	Matrix operator * (float num);
	Matrix operator / (float num);
	Matrix operator * (Matrix mat2);
	Matrix operator ~ ();
	Matrix operator ! ();
	bool operator == (Matrix mat2);
	bool operator != (Matrix mat2);
	friend std::istream& operator >> (std::istream& input, Matrix mat);
	friend std::ostream& operator << (std::ostream& output, Matrix mat);
	float*& operator [] (int rowIndex);
};

Matrix operator * (float num, Matrix mat);