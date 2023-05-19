#include "pch.h"
#define _USE_MATH_DEFINES
#include "CppUnitTest.h"
#include "..\Engine\Constants.h"
#include "..\Engine\EngineException.h"
#include "..\Engine\Matrix.h"
#include "..\Engine\Vector.h"
#include "..\Engine\Point.h"
#include "..\Engine\VectorSpace.h"
#include "..\Engine\Functions.h"
#include "..\Engine\CoordinateSystem.h"
#include <vector>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;


namespace EngineTests
{
	TEST_CLASS(MatrixTests)
	{
	public:

		TEST_METHOD(DefaultConstructorTest)
		{
			Matrix mat;

			bool correctSizes = (mat.height == 0 && mat.width == 0);

			Assert::IsTrue(correctSizes, L"");
		}

		TEST_METHOD(ParameterConstructor1Test1)
		{
			const int SIZE = 3;

			Matrix mat(SIZE);

			bool correctSizes = (mat.height == SIZE && mat.width == SIZE);

			Assert::IsTrue(correctSizes, L"");
		}

		TEST_METHOD(ParameterConstructor1Test2)
		{
			const int SIZE = 3;

			Matrix mat(SIZE);

			bool correctElements = (mat.elements != NULL);

			for (int r = 0; r < mat.height && correctElements; r++)
				for (int c = 0; c < mat.width && correctElements; c++)
					correctElements = (fabs(mat[r][c]) < PRECISION);

			Assert::IsTrue(correctElements, L"");
		}

		TEST_METHOD(ParameterConstructor2Test1)
		{
			const int HEIGHT = 3, WIDTH = 4;

			Matrix mat(HEIGHT, WIDTH);

			bool correctSizes = (mat.height == HEIGHT && mat.width == WIDTH);

			Assert::IsTrue(correctSizes, L"");
		}

		TEST_METHOD(ParameterConstructor2Test2)
		{
			const int HEIGHT = 3, WIDTH = 4;

			Matrix mat(HEIGHT, WIDTH);

			bool correctElements = (mat.elements != NULL);

			for (int r = 0; r < mat.height && correctElements; r++)
				for (int c = 0; c < mat.width && correctElements; c++)
					correctElements = (fabs(mat[r][c]) < PRECISION);

			Assert::IsTrue(correctElements, L"");
		}

		TEST_METHOD(ParameterConstructor3Test1)
		{
			const int HEIGHT = 2, WIDTH = 3;

			Matrix mat({
				{1.0, 2.0, 3.0},
				{4.0, 5.0, 6.0} });

			bool correctSizes = (mat.height == HEIGHT && mat.width == WIDTH);

			Assert::IsTrue(correctSizes, L"");
		}

		TEST_METHOD(ParameterConstructor3Test2)
		{
			const int HEIGHT = 2, WIDTH = 3;

			const float matrix[HEIGHT][WIDTH] = {
				{1.0, 2.0, 3.0},
				{4.0, 5.0, 6.0} };

			Matrix mat({
				{1.0, 2.0, 3.0},
				{4.0, 5.0, 6.0} });

			bool correctElements = (mat.elements != NULL);

			for (int r = 0; r < HEIGHT && correctElements; r++)
				for (int c = 0; c < WIDTH && correctElements; c++)
					correctElements = (fabs(mat[r][c] - matrix[r][c]) < PRECISION);

			Assert::IsTrue(correctElements, L"");
		}

		TEST_METHOD(EqualityTest1)
		{
			Matrix mat1({ { 1.0, 2.0 } });
			Matrix mat2 = mat1;

			bool areEqual = (Matrix::AreEqual(mat1, mat2));

			Assert::IsTrue(areEqual, L"");
		}

		TEST_METHOD(EqualityTest2)
		{
			Matrix mat1({ { 1.0, 2.0 } });
			Matrix mat2({ {1.0}, {2.0} });

			bool areEqual = (Matrix::AreEqual(mat1, mat2));

			Assert::IsFalse(areEqual, L"");
		}

		TEST_METHOD(EqualityTest3)
		{
			Matrix mat1({ { 1.0, 2.0 } });
			Matrix mat2({ { 3.0, 4.0 } });

			bool areEqual = (Matrix::AreEqual(mat1, mat2));

			Assert::IsFalse(areEqual, L"");
		}

		TEST_METHOD(IdentityTest1)
		{
			const int SIZE = 3;

			Matrix identity = Matrix::Identity(SIZE);

			bool correctSizes = (identity.height == SIZE && identity.width == SIZE);
			
			Assert::IsTrue(correctSizes, L"");
		}

		TEST_METHOD(IdentityTest2)
		{
			const int SIZE = 3;

			Matrix identity = Matrix::Identity(SIZE);

			bool correctElements = (identity.elements != NULL);

			for (int r = 0; r < identity.height && correctElements; r++)
				for (int c = 0; c < identity.width && correctElements; c++)
					if (r == c)
						correctElements = (fabs(identity[r][c] - 1.0) < PRECISION);
					else
						correctElements = (fabs(identity[r][c]) < PRECISION);

			Assert::IsTrue(correctElements, L"");
		}


		TEST_METHOD(MinorTest)
		{
			Matrix mat({
				{ 1.0, 0.0, 0.0 },
				{ 0.0, 1.0, 2.0 },
				{ 0.0, 3.0, 1.0 } });

			int rowIndex = 0, colIndex = 0;

			Matrix minor({
				{ 1.0, 2.0 },
				{ 3.0, 1.0 } });

			Matrix testMinor = mat.Minor(rowIndex, colIndex);

			bool minorIsCorrect = (minor == testMinor);

			Assert::IsTrue(minorIsCorrect, L"");
		}

		TEST_METHOD(DeterminantTest1)
		{
			const int SIZE = 3;

			Matrix mat(SIZE, SIZE);

			float det = 0.0;
			float testDet = mat.Determinant();

			bool determinantIsCorrect = (fabs(testDet - det) < PRECISION);

			Assert::IsTrue(determinantIsCorrect, L"");
		}

		TEST_METHOD(DeterminantTest2)
		{
			const int SIZE = 3;

			Matrix mat = Matrix::Identity(SIZE);

			float det = 1.0;
			float testDet = mat.Determinant();

			bool determinantIsCorrect = (fabs(testDet - det) < PRECISION);

			Assert::IsTrue(determinantIsCorrect, L"");
		}

		TEST_METHOD(DeterminantTest3)
		{
			Matrix mat({
				{ 8.0, 2.0, 0.0 },
				{ 3.0, 4.0, 5.0 },
				{ 1.0, 8.0, 6.0 } });

			float det = (-154.0);
			float testDet = mat.Determinant();

			bool determinantIsCorrect = (fabs(testDet - det) < PRECISION);

			Assert::IsTrue(determinantIsCorrect, L"");
		}

		TEST_METHOD(DeterminantTest4)
		{
			Matrix mat({
					{ 3.0, 6.0, 9.0, 5.0, 1.0, 4.0, 5.0 },
					{ 0.0, 1.0, 8.0, 6.0, 3.0, 9.0, 6.0 },
					{ 7.0, 5.0, 5.0, 1.0, 0.0, 7.0, 3.0 },
					{ 3.0, 9.0, 1.0, 7.0, 8.0, 0.0, 5.0 },
					{ 6.0, 7.0, 4.0, 3.0, 0.0, 6.0, 1.0 },
					{ 5.0, 1.0, 8.0, 1.0, 4.0, 5.0, 5.0 },
					{ 1.0, 9.0, 6.0, 5.0, 3.0, 1.0, 6.0 } });

			float det = (-146202.0);
			float testDet = mat.Determinant();

			bool determinantIsCorrect = (fabs(testDet - det) < PRECISION);

			Assert::IsTrue(determinantIsCorrect, L"");
		}

		TEST_METHOD(DeterminantTest5)
		{
			Matrix mat({
				{ 1.0, 2.0, 3.0, 4.0, 5.0 },
				{ 2.0, 3.0, 4.0, 5.0, 6.0 },
				{ 3.0, 4.0, 5.0, 6.0, 7.0 },
				{ 4.0, 5.0, 6.0, 7.0, 1.0 },
				{ 5.0, 6.0, 7.0, 1.0, 2.0 } });

			float det = (0.0);
			float testDet = mat.Determinant();

			bool determinantIsCorrect = (fabs(testDet - det) < PRECISION);

			Assert::IsTrue(determinantIsCorrect, L"");
		}

		TEST_METHOD(DeterminantTest6)
		{
			Matrix mat({
				{ 3.0, 4.0, 5.0, 6.0, 7.0 },
				{ 4.0, 5.0, 6.0, 7.0, 1.0 },
				{ 5.0, 6.0, 7.0, 1.0, 2.0 },
				{ 6.0, 7.0, 1.0, 2.0, 3.0 },
				{ 7.0, 1.0, 2.0, 3.0, 4.0 } });

			float det = (10633.0);
			float testDet = mat.Determinant();

			bool determinantIsCorrect = (fabs(testDet - det) < PRECISION);

			Assert::IsTrue(determinantIsCorrect, L"");
		}

		TEST_METHOD(TransposeTest1)
		{
			const int HEIGHT = 1, WIDTH = 2;

			Matrix mat({ {1.0, 2.0} });

			Matrix transposed = mat.Transpose();

			bool correctSizes = (transposed.height == WIDTH && transposed.width == HEIGHT);

			Assert::IsTrue(correctSizes, L"");
		}

		TEST_METHOD(TransposeTest2)
		{
			const int HEIGHT = 1, WIDTH = 2;

			Matrix mat({ {1.0, 2.0} });

			Matrix transposed = mat.Transpose();

			bool correctElements = (transposed.elements != NULL);

			for (int r = 0; r < mat.height && correctElements; r++)
				for (int c = 0; c < mat.width && correctElements; c++)
					correctElements = (fabs(mat[r][c] - transposed[c][r]) < PRECISION);

			Assert::IsTrue(correctElements, L"");
		}

		TEST_METHOD(NormTest)
		{
			Matrix mat({
				{ 1, -2, 3 },
				{ 4, 5, -6 },
				{ -7, 8, -9 } });

			float norm = 24;
			float testNorm = mat.Norm();

			bool normIsCorrect = (fabs(testNorm - norm) < PRECISION);

			Assert::IsTrue(normIsCorrect, L"");
		}

		TEST_METHOD(InverseTest)
		{
			Matrix mat({
				{ 2.0, 5.0, 7.0 },
				{ 6.0, 3.0, 4.0 },
				{ 5.0, -2.0, -3.0} });

			Matrix inverse({
				{ 1.0, -1.0, 1.0},
				{ -38.0, 41.0, -34.0},
				{27.0, -29.0, 24.0} });

			Matrix testInverse = mat.Inverse();

			bool inverseIsCorrect = (inverse == testInverse);

			Assert::IsTrue(inverseIsCorrect, L"");
		}

		TEST_METHOD(RotationMatrixTest1)
		{
			int size = 3, axisIndex1 = 0, axisIndex2 = 1;
			float angle = M_PI / 2;

			Matrix rotationMatrix({
				{ cos(angle), -sin(angle), 0},
				{ sin(angle), cos(angle), 0},
				{ 0, 0, 1 } });

			Matrix testRotationMatrix = Matrix::RotationMatrix(size, axisIndex1, axisIndex2, angle);

			bool correctRotationMatrix = (testRotationMatrix == rotationMatrix);

			Assert::IsTrue(correctRotationMatrix, L"");
		}

		TEST_METHOD(RotationMatrixTest2)
		{
			int size = 3, axisIndex1 = 0, axisIndex2 = 1;
			float angle = -M_PI / 2;

			Matrix rotationMatrix({
				{ cos(angle), -sin(angle), 0},
				{ sin(angle), cos(angle), 0},
				{ 0, 0, 1 } });

			Matrix testRotationMatrix = Matrix::RotationMatrix(size, axisIndex1, axisIndex2, angle);

			bool correctRotationMatrix = (testRotationMatrix == rotationMatrix);

			Assert::IsTrue(correctRotationMatrix, L"");
		}

		TEST_METHOD(TaitBryanMatrixTest)
		{
			float angle1 = M_PI / 4, angle2 = M_PI / 4, angle3 = M_PI / 4;

			/*Matrix TaitBryanMatrix({
				{ 0.500005, -0.500005, 0.70711 },
				{ 0.853563, 0.146446, -0.500005},
				{ 0.146446, 0.853563, 0.500005 } });*/

			Matrix rotation1({
				{ 1, 0, 0 },
				{ 0, cos(angle1), -sin(angle1) },
				{ 0, sin(angle1), cos(angle1) } });

			Matrix rotation2({
				{ cos(angle2), 0, sin(angle2)},
				{ 0, 1, 0 },
				{ -sin(angle2), 0, cos(angle2) } });

			Matrix rotation3({
				{ cos(angle3), -sin(angle3), 0 },
				{ sin(angle3), cos(angle3), 0 },
				{ 0, 0, 1 } });

			Matrix TaitBryanMatrix = rotation1 * rotation2 * rotation3;

			Matrix testTaitBryanMatrix = Matrix::TaitBryanMatrix(angle1, angle2, angle3);

			bool TaitBryanMatrixIsCorrect = (testTaitBryanMatrix == TaitBryanMatrix);

			Assert::IsTrue(TaitBryanMatrixIsCorrect, L"");
		}

		TEST_METHOD(AssignTest)
		{
			const int SIZE = 3;

			Matrix mat1 = Matrix::Identity(SIZE);
			Matrix mat2 = mat1;

			bool assignIsCorrect = (mat1 == mat2);

			Assert::IsTrue(assignIsCorrect, L"");
		}

		TEST_METHOD(AdditionTest)
		{
			Matrix mat({
				{ 1.0, 2.0 },
				{ 3.0, 4.0} });

			Matrix sum({
				{ 2.0, 4.0 },
				{ 6.0, 8.0 } });

			Matrix testSum = mat + mat;

			bool additionIsCorrect = (testSum == sum);

			Assert::IsTrue(additionIsCorrect, L"");
		}

		TEST_METHOD(SubtractionTest)
		{
			Matrix mat({
				{ 1.0, 2.0 },
				{ 3.0, 4.0} });

			Matrix sub({
				{ 0.0, 0.0 },
				{ 0.0, 0.0 } });

			Matrix testSub = mat - mat;

			bool subtractionIsCorrect = (testSub == sub);

			Assert::IsTrue(subtractionIsCorrect, L"");
		}

		TEST_METHOD(MulByScalarTest)
		{
			Matrix mat({
				{ 1.0, 2.0 },
				{ 3.0, 4.0 } });

			Matrix mul({
				{ 3.0, 6.0 },
				{ 9.0 , 12.0 } });

			Matrix testMul = mat * 3.0;

			bool mulByScalarIsCorrect = (testMul == mul);

			Assert::IsTrue(mulByScalarIsCorrect, L"");
		}

		TEST_METHOD(DivisionTest)
		{
			Matrix mat({
				{ 3.0, 6.0 },
				{ 9.0, 12.0 } });

			Matrix div({
				{ 1.0, 2.0 },
				{ 3.0, 4.0 } });

			Matrix testDiv = mat / 3.0;

			bool divisionIsCorrect = (testDiv == div);

			Assert::IsTrue(divisionIsCorrect, L"");
		}

		TEST_METHOD(MatrixMulTest)
		{
			Matrix mat1({ {1.0}, {2.0} });
			Matrix mat2({ { 3.0, 4.0} });

			Matrix mul({
			{ 3.0, 4.0 },
			{ 6.0, 8.0 } });

			Matrix testMul = Matrix::MatrixMul(mat1, mat2);

			bool matrixMulIsCorrect = (testMul == mul);

			Assert::IsTrue(matrixMulIsCorrect, L"");
		}
	};
	
	TEST_CLASS(VectorTests)
	{
	public:

		TEST_METHOD(DefaultConstructorTest1)
		{
			Vector vec;

			bool correctSizes = (vec.height == 0 && vec.width == 0);

			Assert::IsTrue(correctSizes, L"");
		}

		TEST_METHOD(DefaultConstructorTest2)
		{
			Vector vec;

			bool correctOrientation = (!vec.IsTransposed());

			Assert::IsTrue(correctOrientation, L"");
		}

		TEST_METHOD(ParameterConstructor1Test1)
		{
			const int HEIGHT = 3;

			Vector vec(HEIGHT);

			bool correctSizes = (vec.height == HEIGHT && vec.width == 1);

			Assert::IsTrue(correctSizes, L"");
		}

		TEST_METHOD(ParameterConstructor1Test2)
		{
			const int HEIGHT = 3;

			Vector vec(HEIGHT);

			bool correctOrientation = (!vec.IsTransposed());

			Assert::IsTrue(correctOrientation, L"");
		}

		TEST_METHOD(ParameterConstructor1Test3)
		{
			const int HEIGHT = 3;

			Vector vec(HEIGHT);

			bool correctElements = (vec.elements != NULL);

			for (int i = 0; i < vec.Dim() && correctElements; i++)
				correctElements = (fabs(vec[i]) < PRECISION);

			Assert::IsTrue(correctElements, L"");
		}

		TEST_METHOD(ParameterConstructor2Test1)
		{
			const int SIZE = 3;

			Vector vec({ 1.0, 2.0, 3.0 });

			bool correctSize = (vec.Dim() == SIZE);

			Assert::IsTrue(correctSize, L"");
		}

		TEST_METHOD(ParameterConstructor2Test2)
		{
			const int SIZE = 3;

			float elements[SIZE] = { 1.0, 2.0, 3.0 };

			Vector vec({ 1.0, 2.0, 3.0 });

			bool correctElements = (vec.elements != NULL);

			for (int i = 0; i < vec.Dim() && correctElements; i++)
				correctElements = (fabs(vec[i] - elements[i]) < PRECISION);

			Assert::IsTrue(correctElements, L"");
		}


		TEST_METHOD(ParameterConstructor2Test3)
		{
			const int SIZE = 3;

			Vector vec({ 1.0, 2.0, 3.0 });

			bool correctOrientation = !vec.IsTransposed();

			Assert::IsTrue(correctOrientation, L"");
		}

		TEST_METHOD(DimTest1)
		{
			const int DIM = 3;

			Vector vec(DIM);

			bool correctDim = (vec.Dim() == DIM);

			Assert::IsTrue(correctDim, L"");
		}

		TEST_METHOD(DimTest2)
		{
			const int DIM = 3;

			Vector vec(DIM);

			bool correctDim = (vec.Transpose().Dim() == DIM);

			Assert::IsTrue(correctDim, L"");
		}

		TEST_METHOD(RotateTest1)
		{
			int axisIndex1 = 0, axisIndex2 = 1;
			float angle = M_PI / 2;

			Vector vec({ 9, 0, 0 });

			Vector rotated({ 0, -9, 0 });
			Vector testRotated = vec.Rotate(axisIndex1, axisIndex2, angle);

			bool rotatedVectorIsCorrect = (testRotated == rotated);

			Assert::IsTrue(rotatedVectorIsCorrect, L"");
		}

		TEST_METHOD(RotateTest2)
		{
			int axisIndex1 = 0, axisIndex2 = 1;
			float angle = -M_PI / 2;

			Vector vec({ 9, 0, 0 });

			Vector rotated({ 0, 9, 0 });
			Vector testRotated = vec.Rotate(axisIndex1, axisIndex2, angle);

			bool rotatedVectorIsCorrect = (testRotated == rotated);

			Assert::IsTrue(rotatedVectorIsCorrect, L"");
		}

		TEST_METHOD(SclalarProductTest)
		{
			Vector vec1({ 1.0, 2.0, 3.0 });
			Vector vec2({ 4.0, 5.0, 6.0 });

			float product = 32.0;
			float testProduct = Vector::ScalarProduct(vec1, vec2);

			bool scalarProductIsCorrect = (fabs(testProduct - product) < PRECISION);

			Assert::IsTrue(scalarProductIsCorrect, L"");
		}

		TEST_METHOD(VectorProductTest)
		{
			Vector vec1({ 1.0, 2.0, 3.0 });
			Vector vec2({ 4.0, 5.0, 6.0 });

			Vector product({ -3.0, 6.0, -3.0 });
			Vector testProduct = Vector::VectorProduct(vec1, vec2);

			bool vectorProductIsCorrect = (testProduct == product);

			Assert::IsTrue(vectorProductIsCorrect, L"");
		}

		TEST_METHOD(LengthTest1)
		{
			Vector vec({ 1.0, 0.0, 0.0 });

			float length = 1.0;
			float testLength = vec.Length();

			bool lengthIsCorrect = (fabs(testLength - length) < PRECISION);

			Assert::IsTrue(lengthIsCorrect, L"");
		}

		TEST_METHOD(LengthTest2)
		{
			Vector vec({ 3.0, 4.0, 0.0 });

			float length = 5.0;
			float testLength = vec.Length();

			bool lengthIsCorrect = (fabs(testLength - length) < PRECISION);

			Assert::IsTrue(lengthIsCorrect, L"");
		}

		TEST_METHOD(LengthTest3)
		{
			Vector vec({ 1.0, 1.0, 1.0 });

			float length = sqrt(3.0);
			float testLength = vec.Length();

			bool lengthIsCorrect = (fabs(testLength - length) < PRECISION);

			Assert::IsTrue(lengthIsCorrect, L"");
		}

		TEST_METHOD(NormalizationTest1)
		{
			Vector vec({ 2.0, 2.0, 1.0 });

			Vector normalized({ (2.0 / 3.0), (2.0 / 3.0), (1.0 / 3.0) });
			Vector testNormalized = vec.Normalize();

			bool normalizedIsCorrect = (testNormalized == normalized);

			Assert::IsTrue(normalizedIsCorrect, L"");
		}

		TEST_METHOD(NormalizationTest2)
		{
			Vector vec({ 0.0, 0.0, 0.0 });

			Vector normalized({ 0.0, 0.0, 0.0 });
			Vector testNormalized = vec.Normalize();

			bool normalizedIsCorrect = (testNormalized == normalized);

			Assert::IsTrue(normalizedIsCorrect, L"");
		}
	};

	TEST_CLASS(FunctionsTests)
	{
	public:

		TEST_METHOD(GramMatrixTest)
		{
			const int SIZE = 2;

			Vector* vec = new Vector[SIZE];
			vec[0] = Vector({ 1.0, 2.0 }), vec[1] = Vector({ 3.0, 4.0 });

			Matrix gram({
				{5.0,  11.0},
				{11.0, 25.0}
				});

			Matrix testGram = Gram(vec, SIZE);

			bool correctGramMatrix = (testGram == gram);

			Assert::IsTrue(correctGramMatrix, L"");
		}

		TEST_METHOD(BilinearFormTest)
		{
			Matrix mat({
				{1.0, 2.0},
				{3.0, 4.0} });

			Vector vec1({ 1.0, 2.0 });
			Vector vec2({ 3.0, 4.0 });

			float bForm = 61.0;
			float testBForm = BilinearForm(mat, vec1, vec2);

			bool correctBilinearForm = (fabs(testBForm - bForm) < PRECISION);

			Assert::IsTrue(correctBilinearForm, L"");
		}

	};

	TEST_CLASS(VectorSpaceTests)
	{
	public:

		TEST_METHOD(DefaultConstructorTest1)
		{
			VectorSpace vs;

			bool correctSize = (vs.Dim() == 0);
			
			Assert::IsTrue(correctSize, L"");
		}

		TEST_METHOD(DefaultConstructorTest2)
		{
			VectorSpace vs;

			bool correctVectorList = (vs.basis == NULL);

			Assert::IsTrue(correctVectorList, L"");
		}

		TEST_METHOD(ParameterConstructorTest1)
		{
			const int SIZE = 2;

			Vector* basis = new Vector[SIZE];
			basis[0] = Vector({ 1, 2 }), basis[1] = Vector({ 3, 4 });

			VectorSpace vs(basis, SIZE);

			bool correctSize = (vs.Dim() == SIZE);

			Assert::IsTrue(correctSize, L"");
		}

		TEST_METHOD(ParameterConstructorTest2)
		{
			const int SIZE = 2;

			Vector* basis = new Vector[SIZE];
			basis[0] = Vector({ 1, 2 }), basis[1] = Vector({ 3, 4 });

			VectorSpace vs(basis, SIZE);

			bool correctVectors = (vs.basis != NULL);

			for (int i = 0; i < vs.Dim() && correctVectors; i++)
				correctVectors = (vs.basis[i] == basis[i]);

			Assert::IsTrue(correctVectors, L"");
		}

		TEST_METHOD(ScalarProductTest)
		{
			const int SIZE = 2;

			Vector* basis = new Vector[SIZE];
			basis[0] = Vector({ 1, 0 }), basis[1] = Vector({ 0, 1 });

			VectorSpace vs(basis, SIZE);

			Vector vec1({ 1.0, 2.0 });
			Vector vec2({ 3.0, 4.0 });

			float prod = 11.0;
			float testProd = vs.ScalarProduct(vec1, vec2);

			bool ScalarProductIsCorrect = (fabs(testProd - prod) < PRECISION);

			Assert::IsTrue(ScalarProductIsCorrect, L"");
		}

		TEST_METHOD(VectorProductTest)
		{
			const int SIZE = 3;

			Vector* basis = new Vector[SIZE];
			basis[0] = Vector({ 1.0, 0.0, 1.0 });
			basis[1] = Vector({ 2.0, 3.0, 0.0 });
			basis[2] = Vector({ 0.0, 2.0, 3.0 });

			VectorSpace vs(basis, SIZE);

			Vector vec1({ 1.0, 2.0, 3.0 });
			Vector vec2({ 4.0, 5.0, 6.0 });

			Vector product({ 9.0, 12.0, -12.0 });
			Vector testProduct = vs.VectorProduct(vec1, vec2);

			bool vectorProductIsCorrect = (testProduct == product);

			Assert::IsTrue(vectorProductIsCorrect, L"");
		}

		TEST_METHOD(AsVectorTest)
		{
			const int SIZE = 2;

			Point p({ 4.0, 5.0 });

			Vector* basis = new Vector[SIZE];
			basis[0] = Vector({ 1, 0 }), basis[1] = Vector({ 0, 1 });

			VectorSpace vs = VectorSpace(basis, SIZE);

			Vector vector({ 4.0, 5.0 });
			Vector testVector = vs.AsVector(p);

			bool correctVector = (testVector == vector);

			Assert::IsTrue(correctVector, L"");
		}
	};

	TEST_CLASS(PointTests)
	{
	public:

		TEST_METHOD(DefaultConstructorTest)
		{
			Point p;

			bool correctSizes = (p.height == 0 && p.width == 0);

			Assert::IsTrue(correctSizes, L"");
		}

		TEST_METHOD(ParameterConstructor1Test1)
		{
			const int SIZE = 2;

			Point p(SIZE);

			bool correctCoordsCount = (p.Dim() == SIZE && p.width == 1);

			Assert::IsTrue(correctCoordsCount, L"");
		}

		TEST_METHOD(ParameterConstructor1Test2)
		{
			const int SIZE = 2;

			Point p(SIZE);

			bool correctCoords = (p.elements != NULL);

			Assert::IsTrue(correctCoords, L"");
		}

		TEST_METHOD(ParameterConstructor2Test1)
		{
			const int SIZE = 3;

			Vector vec({ 1.0, 2.0, 3.0 });

			Point p(vec);

			bool correctCoordsCount = (p.Dim() == SIZE);

			Assert::IsTrue(correctCoordsCount, L"");
		}

		TEST_METHOD(ParameterConstructor2Test2)
		{
			const int SIZE = 3;

			Vector vec({ 1.0, 2.0, 3.0 });

			Point p(vec);

			bool correctCoords = (p.elements != NULL);

			for (int i = 0; i < p.Dim() && correctCoords; i++)
				correctCoords = (fabs(p[i] - vec[i]) < PRECISION);

			Assert::IsTrue(correctCoords, L"");
		}

		TEST_METHOD(ParameterConstructor3Test1)
		{
			const int SIZE = 3;

			Point p({ 1.0, 2.0, 3.0 });

			bool correctCoordsCount = (p.Dim() == SIZE);

			Assert::IsTrue(correctCoordsCount, L"");
		}

		TEST_METHOD(ParameterConstructor3Test2)
		{
			const int SIZE = 3;

			float coords[SIZE] = { 1.0, 2.0, 3.0 };

			Point p({ 1.0, 2.0, 3.0 });

			bool correctCoords = (p.elements != NULL);

			for (int i = 0; i < p.Dim() && correctCoords; i++)
				correctCoords = (fabs(p[i] - coords[i]) < PRECISION);

			Assert::IsTrue(correctCoords, L"");
		}

		TEST_METHOD(AdditionOperatorTest)
		{
			Point p({ 1.0, 2.0 });

			Vector vec({ 1.0, 2.0 });

			Point sum({ 2.0, 4.0 });
			Point testSum = p + vec;

			bool correctSum = (testSum == sum);

			Assert::IsTrue(correctSum, L"");
		}

		TEST_METHOD(SubtractionOperatorTest)
		{
			Point p({ 1.0, 2.0 });

			Vector vec({ 1.0, 2.0 });

			Point sum({ 0.0, 0.0 });
			Point testSub = p - vec;

			bool correctSub = (testSub == sum);

			Assert::IsTrue(correctSub, L"");
		}
	};

	TEST_CLASS(CoordinateSystemTests)
	{
	public:

		TEST_METHOD(DefaultConstructorTest1)
		{
			CoordinateSystem cs;

			bool correctInitialPoint = (cs.initialPoint == Point());

			Assert::IsTrue(correctInitialPoint, L"");
		}

		TEST_METHOD(DefaultConstructorTest2)
		{
			CoordinateSystem cs;

			bool correctVectorSpace = (!cs.space.IsInitialized());

			Assert::IsTrue(correctVectorSpace, L"");
		}

		TEST_METHOD(ParameterConstructor1Test1)
		{
			const int SIZE = 3;

			Point initialPoint({ 1, 2, 3 });

			Vector* basis = new Vector[SIZE];
			basis[0] = Vector({ 1, 0, 0 });
			basis[1] = Vector({ 0, 1, 0 });
			basis[2] = Vector({ 0, 0, 1 });

			VectorSpace vs(basis, SIZE);

			CoordinateSystem cs(initialPoint, vs);

			bool correctInitialPoint = (cs.initialPoint == initialPoint);

			Assert::IsTrue(correctInitialPoint, L"");
		}

		TEST_METHOD(ParameterConstructor1Test2)
		{
			const int SIZE = 3;

			Point initialPoint({ 1, 2, 3 });

			Vector* basis = new Vector[SIZE];
			basis[0] = Vector({ 1, 0, 0 });
			basis[1] = Vector({ 0, 1, 0 });
			basis[2] = Vector({ 0, 0, 1 });

			VectorSpace vs(basis, SIZE);

			CoordinateSystem cs(initialPoint, vs);

			bool correctSpace = (cs.space.Dim() == vs.Dim());

			for (int i = 0; i < cs.space.Dim() && correctSpace; i++)
				correctSpace = (vs.basis[i] == cs.space.basis[i]);

			Assert::IsTrue(correctSpace, L"");
		}
	};

}
