# GRAPHICS ENGINE

This is a ray-casting graphics engine.

---

## Authors

- [@SaldaevVladimir](https://www.github.com/vladsaldaev)

## About project

This is a study project for computer graphics.
 
## Requirements

- C++ 14 standart 
- standart libraries
- MSTests 

---




## Classes


### Class Matrix

This class is responsible for the creation and operations on matrices.

#### Matrix fields

- **height** (int) - number of rows in the matrix
- **width** (int) - number of columns in the matrix
- **elements** (float**) - array of matrix elements


#### Creating matrices

To create objects of the matrix class, we need to connect the appropriate header file:

```C++
#include "Matrix.h"
```

```C++
Matrix mat({
 {1, 2, 3},
 {4, 5, 6} });
```

If we only set the dimensions of the matrix, then all elements of the matrix will be zero.

```C++
int height = 2, width = 3;
Matrix mat(height, width);
```

If the dimensions of the matrix are already set, then we can read its elements from the stream in the following form:

```C++
input >> mat;
```

```Ñ++
[input]:
1 2 3
4 5 6
```

We can display matrix in the following form:

```C++
output << mat;
```

```
[output]:
1 2 3
4 5 6
```


#### Arithmetic operations with matrices

To perform operations with objects of the Matrix class, we need to connect the appropriate header file:

```C++
#include "Matrix.h"
```

Note: _for each method matrix/matrixes should be initialized._

The following arithmetic operations are defined:


- addition

```C++
Matrix mat1({ 
 {3, 5},
 {2, 6} });
Matrix mat2({
 {2, 1}, 
 {0, 4} });

output << mat1 + mat2;
```

```
[output]:
5 6
2 10
```

This method is only for matrixes, which have same dimensions.

If we try to use this method for matrixes, which have different dimensions, then we will get the corresponding Engine Exception.


- subtraction

```C++
Matrix mat1({ 
 {3, 5},
 {2, 6} });
Matrix mat2({
 {2, 1}, 
 {0, 4} });

output << mat1 - mat2;
```

```
[output]:
1 4
2 2
```

This method is only for matrixes, which have same dimensions.

If we try to use this method for matrixes, which have different dimensions, then we will get the corresponding Engine Exception.


- multiplying a matrix by a number

```C++
Matrix mat({
 {1, 2},
 {3, 4} });
float num = 2;

output << mat * num;
```

```
[output]:
2 4
6 8
```


- division a matrix by a number

```C++
Matrix mat({
 {2, 4},
 {6, 8} });
float num = 2;

output << mat / num;
```

```
[output]:
1 2
3 4
```

If we try to use this method with number equal to zero, then we will get the corresponding Engine Exception.


- matrix multiplication

```C++
Matrix mat1({
 {1, 2},
 {3, 4} });
Matrix mat2({
 {5, 6},
 {7, 8} });

output << mat1 * mat2;
```

```
[output]:
19 22
43 50
```

This method is defined for two matrices such that the number of columns in the first matrix is equal to the number of rows in the second matrix.

If we try to use this method for matrices that don't satisfy this condition, we will get the corresponding Engine Exception.


#### Matrix Methods

To use the methods of the matrix class, we need to connect the corresponding header file:

```c++
#include "Matrix.h"
```

Note: _for all methods matrix/matrices should be initialized._


- Identity()

```c++
int size = 2;

output << Matrix::Identity(size);
```

```
[output]:
1 0
0 1
```

This method return identity matrix of given size.

Size should be positive, else we will get the corresponding Engine Exception.


- Minor()

```c++
Matrix mat({
 { 1, 2, 3 }, 
 { 4, 5, 6 }, 
 { 7, 8, 9 } });

 int rowIndex = 0, colIndex = 0;

 output << mat.Minor(rowIndex, colIndex);
```

```
[output]:
5 6
7 8
```

This method return minor for given element indexes of given square matrix.

If matrix is not square / indexes are invalid / matrix sizes are equal to 1, then we will get the corresponding Engine Exceptions.


- Determinant()

```c++
Matrix mat({
 {3, 5, 1},
 {2, 7, 4},
 {1, 3, 2} });

 output << mat.Determinant();
 ```

 ```
 [output]:
 5
 ```

 This method return the determinant of given matrix.

 Given matrix should be square, else we will get the corresponding Engine Exception.


- Transpose()

```c++
Matrix mat({
 {1, 2, 3},
 {4, 5, 6} });

 output << mat.Transpose();
 ```

 ```
 [output]:
 1 4
 2 5
 3 6
 ```

 This method returns the transposed matrix for the given matrix.


- Norm()

```c++
Matrix mat({
  { 1, 2, 3 },
  { 4, -5, -6 },
  { -7, 8, 9 } });

float norm = mat.Norm();

output << norm;
```

```
[output]:
24
```

This method returns the norm (number) of the matrix.

Norm of the matrix - maximum sum of modules of elements in a single row.


- Inverse()

```c++
Matrix mat({
 { 2, 5, 7 },
 { 6, 3, 4 },
 { 5, -2, -3} });

 output << mat.Inverse();
```

```
[output]:
1 -1 1
-38 41 -34
27 -29 24
```

This method return inverse matrix for the given.

If given matrix is not square / is singular, then we will get the corresponding Engine Exceptions.


- RotationMatrix()

```c++
int size = 3, axisIndex1 = 0, axisIndex2 = 1;
float angle = 90;

Matrix rotation = Matrix::RotationMatrix(size, axisIndex1, axisIndex2, angle);

output << rotation;
```

```
[output]:
0 -1 0
1 0 0
0 0 1
```

This method returns rotation matrix of given size for two given axis indexes and angle.

Given size should be positive, else we will get the corresponding Engine Exception.

Given axis indeces should be not equal, positive (or equal to zero), else we will get the corresponding Engine Exception.


- TaitBryanMatrix()

```c++
float angle1 = 30, angle2 = 45, angle3 = 60;

Matrix TaitBryanMatrix = Matrix::TaitBryanMatrix(angle1, angle2, angle3);
```

```
[output]:
0.612378 -0.353555 0.70711
0.780338 0.126826 -0.612378
0.126826 0.926785 0.353555
```

This method returns Tait Bryan matrix (3x3) for three given angles.


---


### Class Vector 

Vector class inherits from the Matrix class.

This class is responsible for the creation and operations on vectors.


#### Vector fields

This class inherits all fields of the matrix class.

But this class has an extra field:

- **isTransposed** (bool) - a variable that contains information about whether the vector is transposed

By default, all vectors are created as columns (width = 1).

The **isTransposed** (bool) field has the value **false** if the vector is a column and **true** if the vector is a row.


#### Creating vectors

To create objects of the vector class, we need to connect the appropriate header file:

```C++
#include "Vector.h"
```

```C++
Vector vec({ 1, 2, 3 });
```

If we set the dimension of the vector, then all elements of the vector will be zero.

```C++
int dim = 3;
Vector vec(dim);
// vec = { 0, 0, 0 }
```

If the dimension of the vector is already set, then we can read its elements from the stream in the following form:

```C++
input >> vec;
```

```C++
[input]:
1 2 3
```

We can display vector in the following form:

```c++
output << vec;
```

```
[output]:
1 2 3
```

#### Arithmetic operations with vectors

To perform operations with objects of the vector class, we need to connect the appropriate header file:

```c++
#include "Vector.h"
```

Note: _for each method vector/vectors should be initialized._

The following arithmetic operations are defined:


- addition

```c++
Vector vec1({ 1, 2, 3 });
Vector vec2({ 2, 3, 4 });

output << vec1 + vec2;
```

```
[output]:
3 5 7
```

This method is only for two vectors which have same dimension.

If we try to use this method for two vectors which have different dimension, then we will get the corresponding Engine Exception.


- subtraction

```c++
Vector vec1({ 1, 2, 3 });
Vector vec2({ 1, 1, 1 });

output << vec1 - vec2;
```

```
[output]:
0 1 2
```

This method is only for two vectors which have same dimension.

If we try to use this method for two vectors which have different dimension, then we will get the corresponding Engine Exception.


- multiplying a vector by a number

```c++
Vector vec({ 1, 2, 3 });
float num = 3.0;

output << vec * num;
```

```
[output]:
3 6 9
```


- division a vector by a number

```c++
Vector vec({ 3, 6, 9 });
float num = 3.0;

output << vec / num;
```

```
[output]:
1 2 3
```

If we try to use this method for number equal to zero, then we will get the corresponding Engine Exception.

- matrix multiplication of vectors

This is a matrix class method, but it also works for vectors.

```c++
Vector vec1({ 1, 2 });
Vector vec2({ 3, 4 });

output << vec1 * vec2.Transpose();
```
```
[output]:
3 4
6 8
```

#### Vector Methods

To use the methods of the vector class, we need to connect the corresponding header file:

```c++
#include "Vector.h"
```

Note: _for all methods vector/vectors should be initialized._

- Dim()

```c++
Vector vec({ 1, 2, 3 });

output << vec.Dim();
```

```
[output]:
3
```

This method return dimension of given vector.

- IsTransposed()

```c++
Vector vec({ 1, 2, 3 });

output << vec.IsTransposed() << " " << vec.Transpose().IsTransposed();
```

```
[output]:
0 1
```

If given vector is a row, then method return _True_, else this method return _False_.

- Transpose()

```c++ 
Vector vec({ 1, 2 });

output << vec.Transpose();
```

```
[output]:
1
2
```

This method returns the transposed vector for the given vector.

- Rotate()

```c++
int axisIndex1 = 0, axisIndex2 = 1;
float angle = 90;

Vector vec({ 1, 2, 3 });

output << vec.Rotate(axisIndex1, axisIndex2, angle);
```

```
[output]:
2 -1 3
```

This method returns the vector obtained as a result of the rotation of given vector by a given angle for given axis indices.

Axis indeces should be not equal, positive (or equal to zero), else we will get the corresponding Engine Exception.

Axis indeces should be less than given vector dimension, else we will get the corresponding Engine Exception.

- ScalarProduct()

```c++
Vector vec1({ 1, 2, 3 });
Vector vec2({ 4, 5, 6 });

output << vec1 % vec2;
```

```
[output]:
32
```

This method returns the scalar product of two given vectors in an orthogonal basis.

If we try to use this method for two vectors, which have different dimension, then we will get the corresponding Engine Exception.

- VectorProduct()

```c++
Vector vec1({ 1.0, 2.0, 3.0 });
Vector vec2({ 4.0, 5.0, 6.0 });

output << vec1 ^ vec2;
```

```
[output]:
-3 6 -3
```

This method returns the vector product (number) of two given vectors in an orthogonal basis.

If we try to use this method for two vectors, which dimension are not equal to 3, then we will get the corresponding Engine Exception.

- Length()

```c++
Vector vec({ 1, 2, 2 });

output << vec.Length();
```

```
[output]:
3
```

This method returns the square root of the scalar product of a vector on itself in an orthogonal basis.

- Normalize()

```c++
Vector vec({ 0, 0, 9 });

output << vec.Normalize();
```

```
[output]:
0 0 1
```

This method returns normalized vector of given vector.

If length of the given vector is equal to zero, then method will return a given vector.

---

### Class VectorSpace 

This class is responsible for the basis vectors and for performing operations in this basis.

#### VectorSpace fields

- **basis** (Vector*)- list of vectors included in the basis

- **dim** (int) - dimension of basis (number of vectors in basis)

Note: _number of vectors in the basis is equal to their dimension_

#### Creating vector space

To create objects of the vectorspace class, we need to connect the appropriate header file:

```c++
#include "VectorSpace.h"
```

```c++
int dim = 2;

Vector* basis = new Vector[dim];
basis[0] = Vector({ 1, 0 }), basis[1] = Vector({ 0, 1 });

VectorSpace vs(basis, dim);
```

#### VectorSpace Methods

To use the methods of the vector space class, we need to connect the corresponding header file:

```c++
#include "VectorSpace.h"
```

Note: _for all methods vector/vectors and point/points should be initialized._

- ScalarProduct()

```c++
int size = 3;

Vector* basis = new Vector[size];
basis[0] = Vector({ 1, 2, 0 });
basis[1] = Vector({ 2, 1, 0 });
basis[2] = Vector({ 1, 0, 1 });

VectorSpace vs(basis, size);

Vector vec1({ 1, 2, 3 });
Vector vec2({ 4, 5, 6 });

output << vs.ScalarProduct(vec1, vec2);
```

```
[output]:
230
```

This method returns the vector obtained as the result of the scalar product of two given vectors in a given basis.

Given vectors should have same dimension with vector space, else we will get the corresponding Engine Exception.


- VectorProduct()

```c++
int size = 3;

Vector* basis = new Vector[size];
basis[0] = Vector({ 1, 2, 0 });
basis[1] = Vector({ 2, 1, 0 });
basis[2] = Vector({ 1, 0, 1 });

VectorSpace vs(basis, size);

Vector vec1({ 1, 2, 3 });
Vector vec2({ 4, 5, 6 });

output << vs.VectorProduct(vec1, vec2);
```

```
[output]:
6 0 -3
```

This method returns the vector obtained as the result of the vector product of two given vectors in a given basis.

Given vectors should have same dimension with vector space, else we will get the corresponding Engine Exception.

- AsVector()

```c++
int size = 3;

Vector* basis = new Vector[size];
basis[0] = Vector({ 1, 2, 0 });
basis[1] = Vector({ 2, 1, 0 });
basis[2] = Vector({ 1, 0, 1 });

VectorSpace vs(basis, size);
```

```
[output]:
8 4 3
```

This method returns a vector obtained by adding the given basis vectors multiplied by the corresponding coordinates of the point.

Given point should have dimension equal to the vector space dimension, else we will get the corresponding Engine Exception.

---

### Class Point

The Point class inherits from the Vector class.

This class is responsible for creation and operations on points, as on geometric objects.


#### Point fields

All point class fields are same as vector class fields.


#### Creating points

To create objects of the point class, we need to connect the appropriate header file:

```C++
#include "Point.h"
```

```C++
Point p({ 1, 2, 3 });
```

If we set the dimension of the point, then all elements of the point will be zero.

```C++
int dim = 3;

Point p(dim);
// p = { 0, 0, 0 }
```

If the dimension of the point is already set, then we can read its elements (coordinates) from the stream in the following form:

```C++
input >> p;
```

```C++
[input]:
1 2 3
```

We can display point in the following form:

```c++
output << p;
```

```
[output]:
1 2 3
```

#### Arithmetic operations with points

To perform operations with objects of the point class, we need to connect the appropriate header file:

```c++
#include "Point.h"
```

Note: _for each method point/points and vector/vectors should be initialized._

The following arithmetic operations are defined:

- adding vector

```c++
Point p({ 1, 2, 3 });

Vector vec({ 4, 5, 6 });

Point sum = p + vec;

output << sum;
```

```
[output]:
5 7 9
```

This method returns the point obtained by adding a given vector to the given point.

This operation is not commutative.

Given point and vector should have same dimension, else we will get the corresponding Engine Exception.


- vector subtraction

```c++
Point p({ 1, 2, 3 });

Vector vec({ 4, 5, 6 });

Point sub = p - vec;

output << sub;
```

```
[output]:
-3 -3 -3
```
This method returns the point obtained by subtracting the given vector from the given point.

This operation is not commutative.

Given point and vector should have same dimension, else we will get the corresponding Engine Exception.

---

### Class CoordinateSystem

This class contains the initial point and the basis of the system.


#### CoordinateSystem fields

- **initialPoint** (Point) - the initial point of the coordinate system
- **space** (VectorSpace) - the basis vectors of the coordinate system


#### Creating coordinate system

To create objects of the coordinate system class, we need to connect the appropriate header file:

```C++
#include "CoordinateSystem.h"
```

```C++
int size = 2;

Point initial({ 0, 0 });

Vector* basis = new Vector[size];
basis[0] = Vector({ 1, 0 }), basis[1] = Vector({ 0, 1 });

VectorSpace vs(basis, size);

CoordinateSystem Oxy(initial, vs);
```


---


## Functions


### Gram Matrix

```c++
int size = 2;

  Vector* vectorList = new Vector[size];
  vectorList[0] = Vector({ 1, 0 });
  vectorList[1] = Vector({ 0, 1 });

  Matrix GramMatrix = Gram(vectorList, size);

  output << GramMatrix;
```

```
[output]:
1 0
0 1
```

This function return Gram matrix for given vectors.

Vectors number should be equal to their dimension, else we will get the corresponding Engine Exception.


---

### Bilinear Form

```c++
Matrix mat({
  { 1, 2, 3 },
  { 4, 5, 6 },
  { 7, 8, 9 } });

Vector vec1({ 1, 2, 3 });
Vector vec2({ 4, 5, 6 });

float bilinearForm = BilinearForm(mat, vec1, vec2);

output << bilinearForm;
```

```
[output]:
552
```

This function returns bilinear form for two given vectors and matrix

Given matrix dimension shoud be equal to vectors dimension, else we will get the corresponding Engine Exception.




---