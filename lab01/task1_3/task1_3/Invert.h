#pragma once
const int MATRIX_SIZE = 3;

struct Matrix3x3
{
	double coefficients[MATRIX_SIZE][MATRIX_SIZE];
};

struct Matrix2x2
{
	double coefficients[MATRIX_SIZE - 1][MATRIX_SIZE - 1];
};

bool ReadMatrixFromFile(const std::string &inputFileName, Matrix3x3 &matrix);
bool FindInverseMatrix(const Matrix3x3 &matrix, Matrix3x3 &inverseMatrix);
void PrintMatrix(const Matrix3x3 &matrix);