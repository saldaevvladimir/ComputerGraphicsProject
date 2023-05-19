#pragma once

#include "..\Matrix\Matrix.h"
#include "..\Vector\Vector.h"


Matrix Gram(Vector* vectors, int numOfVectors);

float BilinearForm(Matrix mat, Vector vec1, Vector vec2);

Vector Column(Matrix mat, int colIndex);

