#pragma once
#include "stdafx.h"

using namespace std;

const int SIZE_MATRIX = 3;

struct Matrix3x3
{
	double coefficients[SIZE_MATRIX][SIZE_MATRIX];
};

struct Matrix2x2
{
	double coefficients[SIZE_MATRIX - 1][SIZE_MATRIX - 1];
};

bool ReadMatrixFromFile(const string &inputFileName, Matrix3x3 &matrix);
bool FindInverseMatrix(const Matrix3x3 &matrix, Matrix3x3 &inverseMatrix);
void PrintMatrix(const Matrix3x3 &matrix);