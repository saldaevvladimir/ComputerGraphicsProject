#define _USE_MATH_DEFINES

#include "../../lib/Math/Accuracy/Accuracy.h"
#include "../../lib/Math/Matrix/Matrix.h"
#include "../../lib/Math/Vector/Vector.h"
#include "../../lib/Math/Point/Point.h"
#include "../../lib/Math/Functions/Functions.h"
#include "../../lib/Math/VectorSpace/VectorSpace.h"
#include "../../lib/Math/CoordinateSystem/CoordinateSystem.h"

//#include <gtest/gtest.h>
#include "../../googletest/include/gtest/gtest.h"
#include <vector>
#include <cmath>

using namespace std;


// Matrix 

TEST(MatrixTests, DefaultConstructorTest)
{
    Matrix mat;

    bool correctSizes = (mat.height == 0 && mat.width == 0);

    ASSERT_TRUE(correctSizes);
}

TEST(MatrixTests, ParameterConstructor1Test1)
{
    const int SIZE = 3;

    Matrix mat(SIZE);

    bool correctSizes = (mat.height == SIZE && mat.width == SIZE);

    ASSERT_TRUE(correctSizes);
}

TEST(MatrixTests, ParameterConstructor1Test2)
{
    const int SIZE = 3;

    Matrix mat(SIZE);

    bool correctElements = (mat.elements != NULL);

    for (int r = 0; r < mat.height && correctElements; r++)
        for (int c = 0; c < mat.width && correctElements; c++)
            correctElements = (fabs(mat[r][c]) < PRECISION);

    ASSERT_TRUE(correctElements);
}

TEST(MatrixTests, ParameterConstructor2Test1)
{
    const int HEIGHT = 3, WIDTH = 4;

    Matrix mat(HEIGHT, WIDTH);

    bool correctSizes = (mat.height == HEIGHT && mat.width == WIDTH);

    ASSERT_TRUE(correctSizes);
}

TEST(MatrixTests, ParameterConstructor2Test2)
{
    const int HEIGHT = 3, WIDTH = 4;

    Matrix mat(HEIGHT, WIDTH);

    bool correctElements = (mat.elements != NULL);

    for (int r = 0; r < mat.height && correctElements; r++)
        for (int c = 0; c < mat.width && correctElements; c++)
            correctElements = (fabs(mat[r][c]) < PRECISION);

    ASSERT_TRUE(correctElements);
}

TEST(MatrixTests, ParameterConstructor3Test1)
{
    const int HEIGHT = 2, WIDTH = 3;

    Matrix mat({
        {1.0, 2.0, 3.0},
        {4.0, 5.0, 6.0} });

    bool correctSizes = (mat.height == HEIGHT && mat.width == WIDTH);

    ASSERT_TRUE(correctSizes);
}

TEST(MatrixTests, ParameterConstructor3Test2)
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

    ASSERT_TRUE(correctElements);
}

TEST(MatrixTests, EqualityTest1)
{
    Matrix mat1({ { 1.0, 2.0 } });
    Matrix mat2 = mat1;

    bool areEqual = (Matrix::AreEqual(mat1, mat2));

    ASSERT_TRUE(areEqual);
}

TEST(MatrixTests, EqualityTest2)
{
    Matrix mat1({ { 1.0, 2.0 } });
    Matrix mat2({ {1.0}, {2.0} });

    bool areEqual = (Matrix::AreEqual(mat1, mat2));

    ASSERT_FALSE(areEqual);
}

TEST(MatrixTests, EqualityTest3)
{
    Matrix mat1({ { 1.0, 2.0 } });
    Matrix mat2({ { 3.0, 4.0 } });

    bool areEqual = (Matrix::AreEqual(mat1, mat2));

    ASSERT_FALSE(areEqual);
}

TEST(MatrixTests, IdentityTest1)
{
    const int SIZE = 3;

    Matrix identity = Matrix::Identity(SIZE);

    bool correctSizes = (identity.height == SIZE && identity.width == SIZE);
    
    ASSERT_TRUE(correctSizes);
}

TEST(MatrixTests, IdentityTest2)
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

    ASSERT_TRUE(correctElements);
}


TEST(MatrixTests, MinorTest)
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

    ASSERT_TRUE(minorIsCorrect);
}

TEST(MatrixTests, DeterminantTest1)
{
    const int SIZE = 3;

    Matrix mat(SIZE, SIZE);

    float det = 0.0;
    float testDet = mat.Determinant();

    bool determinantIsCorrect = (fabs(testDet - det) < PRECISION);

    ASSERT_TRUE(determinantIsCorrect);
}

TEST(MatrixTests, DeterminantTest2)
{
    const int SIZE = 3;

    Matrix mat = Matrix::Identity(SIZE);

    float det = 1.0;
    float testDet = mat.Determinant();

    bool determinantIsCorrect = (fabs(testDet - det) < PRECISION);

    ASSERT_TRUE(determinantIsCorrect);
}

TEST(MatrixTests, DeterminantTest3)
{
    Matrix mat({
        { 8.0, 2.0, 0.0 },
        { 3.0, 4.0, 5.0 },
        { 1.0, 8.0, 6.0 } });

    float det = (-154.0);
    float testDet = mat.Determinant();

    bool determinantIsCorrect = (fabs(testDet - det) < PRECISION);

    ASSERT_TRUE(determinantIsCorrect);
}

TEST(MatrixTests, DeterminantTest4)
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

    ASSERT_TRUE(determinantIsCorrect);
}

TEST(MatrixTests, DeterminantTest5)
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

    ASSERT_TRUE(determinantIsCorrect);
}

TEST(MatrixTests, DeterminantTest6)
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

    ASSERT_TRUE(determinantIsCorrect);
}

TEST(MatrixTests, TransposeTest1)
{
    const int HEIGHT = 1, WIDTH = 2;

    Matrix mat({ {1.0, 2.0} });

    Matrix transposed = mat.Transpose();

    bool correctSizes = (transposed.height == WIDTH && transposed.width == HEIGHT);

    ASSERT_TRUE(correctSizes);
}

TEST(MatrixTests, TransposeTest2)
{
    const int HEIGHT = 1, WIDTH = 2;

    Matrix mat({ {1.0, 2.0} });

    Matrix transposed = mat.Transpose();

    bool correctElements = (transposed.elements != NULL);

    for (int r = 0; r < mat.height && correctElements; r++)
        for (int c = 0; c < mat.width && correctElements; c++)
            correctElements = (fabs(mat[r][c] - transposed[c][r]) < PRECISION);

    ASSERT_TRUE(correctElements);
}

TEST(MatrixTests, NormTest)
{
    Matrix mat({
        { 1, -2, 3 },
        { 4, 5, -6 },
        { -7, 8, -9 } });

    float norm = 24;
    float testNorm = mat.Norm();

    bool normIsCorrect = (fabs(testNorm - norm) < PRECISION);

    ASSERT_TRUE(normIsCorrect);
}

TEST(MatrixTests, InverseTest)
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

    ASSERT_TRUE(inverseIsCorrect);
}

TEST(MatrixTests, RotationMatrixTest1)
{
    int size = 3, axisIndex1 = 0, axisIndex2 = 1;
    float angle = M_PI / 2;

    Matrix rotationMatrix({
        { cos(angle), -sin(angle), 0},
        { sin(angle), cos(angle), 0},
        { 0, 0, 1 } });

    Matrix testRotationMatrix = Matrix::RotationMatrix(size, axisIndex1, axisIndex2, angle);

    bool correctRotationMatrix = (testRotationMatrix == rotationMatrix);

    ASSERT_TRUE(correctRotationMatrix);
}

TEST(MatrixTests, RotationMatrixTest2)
{
    int size = 3, axisIndex1 = 0, axisIndex2 = 1;
    float angle = -M_PI / 2;

    Matrix rotationMatrix({
        { cos(angle), -sin(angle), 0},
        { sin(angle), cos(angle), 0},
        { 0, 0, 1 } });

    Matrix testRotationMatrix = Matrix::RotationMatrix(size, axisIndex1, axisIndex2, angle);

    bool correctRotationMatrix = (testRotationMatrix == rotationMatrix);

    ASSERT_TRUE(correctRotationMatrix);
}

TEST(MatrixTests, TaitBryanMatrixTest)
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

    ASSERT_TRUE(TaitBryanMatrixIsCorrect);
}

TEST(MatrixTests, AssignTest)
{
    const int SIZE = 3;

    Matrix mat1 = Matrix::Identity(SIZE);
    Matrix mat2 = mat1;

    bool assignIsCorrect = (mat1 == mat2);

    ASSERT_TRUE(assignIsCorrect);
}

TEST(MatrixTests, AdditionTest)
{
    Matrix mat({
        { 1.0, 2.0 },
        { 3.0, 4.0} });

    Matrix sum({
        { 2.0, 4.0 },
        { 6.0, 8.0 } });

    Matrix testSum = mat + mat;

    bool additionIsCorrect = (testSum == sum);

    ASSERT_TRUE(additionIsCorrect);
}

TEST(MatrixTests, SubtractionTest)
{
    Matrix mat({
        { 1.0, 2.0 },
        { 3.0, 4.0} });

    Matrix sub({
        { 0.0, 0.0 },
        { 0.0, 0.0 } });

    Matrix testSub = mat - mat;

    bool subtractionIsCorrect = (testSub == sub);

    ASSERT_TRUE(subtractionIsCorrect);
}

TEST(MatrixTests, MulByScalarTest)
{
    Matrix mat({
        { 1.0, 2.0 },
        { 3.0, 4.0 } });

    Matrix mul({
        { 3.0, 6.0 },
        { 9.0 , 12.0 } });

    Matrix testMul = mat * 3.0;

    bool mulByScalarIsCorrect = (testMul == mul);

    ASSERT_TRUE(mulByScalarIsCorrect);
}

TEST(MatrixTests, DivisionTest)
{
    Matrix mat({
        { 3.0, 6.0 },
        { 9.0, 12.0 } });

    Matrix div({
        { 1.0, 2.0 },
        { 3.0, 4.0 } });

    Matrix testDiv = mat / 3.0;

    bool divisionIsCorrect = (testDiv == div);

    ASSERT_TRUE(divisionIsCorrect);
}

TEST(MatrixTests, MatrixMulTest)
{
    Matrix mat1({ {1.0}, {2.0} });
    Matrix mat2({ { 3.0, 4.0} });

    Matrix mul({
    { 3.0, 4.0 },
    { 6.0, 8.0 } });

    Matrix testMul = Matrix::MatrixMul(mat1, mat2);

    bool matrixMulIsCorrect = (testMul == mul);

    ASSERT_TRUE(matrixMulIsCorrect);
}


// Vector

TEST(VectorTests, DefaultConstructorTest1)
{
    Vector vec;

    bool correctSizes = (vec.height == 0 && vec.width == 0);

    ASSERT_TRUE(correctSizes);
}

TEST(VectorTests, DefaultConstructorTest2)
{
    Vector vec;

    bool correctOrientation = (!vec.IsTransposed());

    ASSERT_TRUE(correctOrientation);
}

TEST(VectorTests, ParameterConstructor1Test1)
{
    const int HEIGHT = 3;

    Vector vec(HEIGHT);

    bool correctSizes = (vec.height == HEIGHT && vec.width == 1);

    ASSERT_TRUE(correctSizes);
}

TEST(VectorTests, ParameterConstructor1Test2)
{
    const int HEIGHT = 3;

    Vector vec(HEIGHT);

    bool correctOrientation = (!vec.IsTransposed());

    ASSERT_TRUE(correctOrientation);
}

TEST(VectorTests, ParameterConstructor1Test3)
{
    const int HEIGHT = 3;

    Vector vec(HEIGHT);

    bool correctElements = (vec.elements != NULL);

    for (int i = 0; i < vec.Dim() && correctElements; i++)
        correctElements = (fabs(vec[i]) < PRECISION);

    ASSERT_TRUE(correctElements);
}

TEST(VectorTests, ParameterConstructor2Test1)
{
    const int SIZE = 3;

    Vector vec({ 1.0, 2.0, 3.0 });

    bool correctSize = (vec.Dim() == SIZE);

    ASSERT_TRUE(correctSize);
}

TEST(VectorTests, ParameterConstructor2Test2)
{
    const int SIZE = 3;

    float elements[SIZE] = { 1.0, 2.0, 3.0 };

    Vector vec({ 1.0, 2.0, 3.0 });

    bool correctElements = (vec.elements != NULL);

    for (int i = 0; i < vec.Dim() && correctElements; i++)
        correctElements = (fabs(vec[i] - elements[i]) < PRECISION);

    ASSERT_TRUE(correctElements);
}


TEST(VectorTests, ParameterConstructor2Test3)
{
    const int SIZE = 3;

    Vector vec({ 1.0, 2.0, 3.0 });

    bool correctOrientation = !vec.IsTransposed();

    ASSERT_TRUE(correctOrientation);
}

TEST(VectorTests, DimTest1)
{
    const int DIM = 3;

    Vector vec(DIM);

    bool correctDim = (vec.Dim() == DIM);

    ASSERT_TRUE(correctDim);
}

TEST(VectorTests, DimTest2)
{
    const int DIM = 3;

    Vector vec(DIM);

    bool correctDim = (vec.Transpose().Dim() == DIM);

    ASSERT_TRUE(correctDim);
}

TEST(VectorTests, RotateTest1)
{
    int axisIndex1 = 0, axisIndex2 = 1;
    float angle = M_PI / 2;

    Vector vec({ 9, 0, 0 });

    Vector rotated({ 0, -9, 0 });
    Vector testRotated = vec.Rotate(axisIndex1, axisIndex2, angle);

    bool rotatedVectorIsCorrect = (testRotated == rotated);

    ASSERT_TRUE(rotatedVectorIsCorrect);
}

TEST(VectorTests, RotateTest2)
{
    int axisIndex1 = 0, axisIndex2 = 1;
    float angle = -M_PI / 2;

    Vector vec({ 9, 0, 0 });

    Vector rotated({ 0, 9, 0 });
    Vector testRotated = vec.Rotate(axisIndex1, axisIndex2, angle);

    bool rotatedVectorIsCorrect = (testRotated == rotated);

    ASSERT_TRUE(rotatedVectorIsCorrect);
}

TEST(VectorTests, SclalarProductTest)
{
    Vector vec1({ 1.0, 2.0, 3.0 });
    Vector vec2({ 4.0, 5.0, 6.0 });

    float product = 32.0;
    float testProduct = Vector::ScalarProduct(vec1, vec2);

    bool scalarProductIsCorrect = (fabs(testProduct - product) < PRECISION);

    ASSERT_TRUE(scalarProductIsCorrect);
}

TEST(VectorTests, VectorProductTest)
{
    Vector vec1({ 1.0, 2.0, 3.0 });
    Vector vec2({ 4.0, 5.0, 6.0 });

    Vector product({ -3.0, 6.0, -3.0 });
    Vector testProduct = Vector::VectorProduct(vec1, vec2);

    bool vectorProductIsCorrect = (testProduct == product);

    ASSERT_TRUE(vectorProductIsCorrect);
}

TEST(VectorTests, LengthTest1)
{
    Vector vec({ 1.0, 0.0, 0.0 });

    float length = 1.0;
    float testLength = vec.Length();

    bool lengthIsCorrect = (fabs(testLength - length) < PRECISION);

    ASSERT_TRUE(lengthIsCorrect);
}

TEST(VectorTests, LengthTest2)
{
    Vector vec({ 3.0, 4.0, 0.0 });

    float length = 5.0;
    float testLength = vec.Length();

    bool lengthIsCorrect = (fabs(testLength - length) < PRECISION);

    ASSERT_TRUE(lengthIsCorrect);
}

TEST(VectorTests, LengthTest3)
{
    Vector vec({ 1.0, 1.0, 1.0 });

    float length = sqrt(3.0);
    float testLength = vec.Length();

    bool lengthIsCorrect = (fabs(testLength - length) < PRECISION);

    ASSERT_TRUE(lengthIsCorrect);
}

TEST(VectorTests, NormalizationTest1)
{
    Vector vec({ 2.0, 2.0, 1.0 });

    Vector normalized({ (2.0 / 3.0), (2.0 / 3.0), (1.0 / 3.0) });
    Vector testNormalized = vec.Normalize();

    bool normalizedIsCorrect = (testNormalized == normalized);

    ASSERT_TRUE(normalizedIsCorrect);
}

TEST(VectorTests, NormalizationTest2)
{
    Vector vec({ 0.0, 0.0, 0.0 });

    Vector normalized({ 0.0, 0.0, 0.0 });
    Vector testNormalized = vec.Normalize();

    bool normalizedIsCorrect = (testNormalized == normalized);

    ASSERT_TRUE(normalizedIsCorrect);
}


// Functions

TEST(FunctionsTests, GramMatrixTest)
{
    const int SIZE = 2;

    Vector* vec = new Vector[SIZE];
    vec[0] = Vector({ 1.0, 2.0 }), vec[1] = Vector({ 3.0, 4.0 });

    Matrix gram({
        {5.0,  11.0},
        {11.0, 25.0}
        });

    Matrix testGram = Vector::Gram(vec, SIZE);

    bool correctGramMatrix = (testGram == gram);

    ASSERT_TRUE(correctGramMatrix);
}

TEST(FunctionsTests, BilinearFormTest)
{
    Matrix mat({
        {1.0, 2.0},
        {3.0, 4.0} });

    Vector vec1({ 1.0, 2.0 });
    Vector vec2({ 3.0, 4.0 });

    float bForm = 61.0;
    float testBForm = BilinearForm(mat, vec1, vec2);

    bool correctBilinearForm = (fabs(testBForm - bForm) < PRECISION);

    ASSERT_TRUE(correctBilinearForm);
}


// Point

TEST(PointTests, DefaultConstructorTest)
{
    Point p;

    bool correctSizes = (p.height == 0 && p.width == 0);

    ASSERT_TRUE(correctSizes);
}

TEST(PointTests, ParameterConstructor1Test1)
{
    const int SIZE = 2;

    Point p(SIZE);

    bool correctCoordsCount = (p.Dim() == SIZE && p.width == 1);

    ASSERT_TRUE(correctCoordsCount);
}

TEST(PointTests, ParameterConstructor1Test2)
{
    const int SIZE = 2;

    Point p(SIZE);

    bool correctCoords = (p.elements != NULL);

    ASSERT_TRUE(correctCoords);
}

TEST(PointTests, ParameterConstructor2Test1)
{
    const int SIZE = 3;

    Vector vec({ 1.0, 2.0, 3.0 });

    Point p(vec);

    bool correctCoordsCount = (p.Dim() == SIZE);

    ASSERT_TRUE(correctCoordsCount);
}

TEST(PointTests, ParameterConstructor2Test2)
{
    const int SIZE = 3;

    Vector vec({ 1.0, 2.0, 3.0 });

    Point p(vec);

    bool correctCoords = (p.elements != NULL);

    for (int i = 0; i < p.Dim() && correctCoords; i++)
        correctCoords = (fabs(p[i] - vec[i]) < PRECISION);

    ASSERT_TRUE(correctCoords);
}

TEST(PointTests, ParameterConstructor3Test1)
{
    const int SIZE = 3;

    Point p({ 1.0, 2.0, 3.0 });

    bool correctCoordsCount = (p.Dim() == SIZE);

    ASSERT_TRUE(correctCoordsCount);
}

TEST(PointTests, ParameterConstructor3Test2)
{
    const int SIZE = 3;

    float coords[SIZE] = { 1.0, 2.0, 3.0 };

    Point p({ 1.0, 2.0, 3.0 });

    bool correctCoords = (p.elements != NULL);

    for (int i = 0; i < p.Dim() && correctCoords; i++)
        correctCoords = (fabs(p[i] - coords[i]) < PRECISION);

    ASSERT_TRUE(correctCoords);
}

TEST(PointTests, AdditionOperatorTest)
{
    Point p({ 1.0, 2.0 });

    Vector vec({ 1.0, 2.0 });

    Point sum({ 2.0, 4.0 });
    Point testSum = p + vec;

    bool correctSum = (testSum == sum);

    ASSERT_TRUE(correctSum);
}

TEST(PointTests, SubtractionOperatorTest)
{
    Point p({ 1.0, 2.0 });

    Vector vec({ 1.0, 2.0 });

    Point sum({ 0.0, 0.0 });
    Point testSub = p - vec;

    bool correctSub = (testSub == sum);

    ASSERT_TRUE(correctSub);
}


// VectorSpace

TEST(VectorSpaceTests, DefaultConstructorTest1)
{
    VectorSpace vs;

    bool correctSize = (vs.Dim() == 0);
    
    ASSERT_TRUE(correctSize);
}

TEST(VectorSpaceTests, DefaultConstructorTest2)
{
    VectorSpace vs;

    bool correctVectorList = (vs.basis == NULL);

    ASSERT_TRUE(correctVectorList);
}

TEST(VectorSpaceTests, ParameterConstructorTest1)
{
    const int SIZE = 2;

    Vector* basis = new Vector[SIZE];
    basis[0] = Vector({ 1, 2 }), basis[1] = Vector({ 3, 4 });

    VectorSpace vs(basis, SIZE);

    bool correctSize = (vs.Dim() == SIZE);

    ASSERT_TRUE(correctSize);
}

TEST(VectorSpaceTests, ParameterConstructorTest2)
{
    const int SIZE = 2;

    Vector* basis = new Vector[SIZE];
    basis[0] = Vector({ 1, 2 }), basis[1] = Vector({ 3, 4 });

    VectorSpace vs(basis, SIZE);

    bool correctVectors = (vs.basis != NULL);

    for (int i = 0; i < vs.Dim() && correctVectors; i++)
        correctVectors = (vs.basis[i] == basis[i]);

    ASSERT_TRUE(correctVectors);
}

TEST(VectorSpaceTests, ScalarProductTest)
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

    ASSERT_TRUE(ScalarProductIsCorrect);
}

TEST(VectorSpaceTests, VectorProductTest)
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

    ASSERT_TRUE(vectorProductIsCorrect);
}

TEST(VectorSpaceTests, AsVectorTest)
{
    const int SIZE = 2;

    Point p({ 4.0, 5.0 });

    Vector* basis = new Vector[SIZE];
    basis[0] = Vector({ 1, 0 }), basis[1] = Vector({ 0, 1 });

    VectorSpace vs = VectorSpace(basis, SIZE);

    Vector vector({ 4.0, 5.0 });
    Vector testVector = vs.AsVector(p);

    bool correctVector = (testVector == vector);

    ASSERT_TRUE(correctVector);
}


// CoordinateSystem

TEST(CoordinateSystemTests, DefaultConstructorTest1)
{
    CoordinateSystem cs;

    bool correctInitialPoint = (cs.initialPoint == Point());

    ASSERT_TRUE(correctInitialPoint);
}

TEST(CoordinateSystemTests, DefaultConstructorTest2)
{
    CoordinateSystem cs;

    bool correctVectorSpace = (!cs.space.IsInitialized());

    ASSERT_TRUE(correctVectorSpace);
}

TEST(CoordinateSystemTests, ParameterConstructor1Test1)
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

    ASSERT_TRUE(correctInitialPoint);
}

TEST(CoordinateSystemTests, ParameterConstructor1Test2)
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

    ASSERT_TRUE(correctSpace);
}
