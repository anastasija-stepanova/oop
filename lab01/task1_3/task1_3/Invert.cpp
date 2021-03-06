#include "stdafx.h"

using namespace std;

const int MATRIX_SIZE = 3;

struct Matrix3x3
{
	double coefficients[MATRIX_SIZE][MATRIX_SIZE];
};

struct Matrix2x2
{
	double coefficients[MATRIX_SIZE - 1][MATRIX_SIZE - 1];
};

bool ReadMatrix(istream &inputFileName, Matrix3x3 &matrix)
{
	for (int i = 0; i < MATRIX_SIZE; ++i)
	{
		for (int j = 0; j < MATRIX_SIZE; ++j)
		{
			if (!(inputFileName >> matrix.coefficients[j][i]))
			{
				return false;
			}
		}
	}
	return true;
}

bool ReadMatrixFromFile(const string &inputFileName, Matrix3x3 &matrix)
{
	ifstream inputFile(inputFileName);
	if (!inputFile.is_open())
	{
		cout << "������� ���� �� ������� ������� ��� ������" << endl;;
		return false;
	}

	if (!ReadMatrix(inputFile, matrix))
	{
		cout << "�� ������� ������� ������� � �����" << endl;
		return false;
	}
	return true;
}

double GetDeterminant(const Matrix3x3 &matrix)
{
	double det =
		matrix.coefficients[0][0] * matrix.coefficients[1][1] * matrix.coefficients[2][2] +
		matrix.coefficients[2][0] * matrix.coefficients[0][1] * matrix.coefficients[1][2] +
		matrix.coefficients[1][0] * matrix.coefficients[2][1] * matrix.coefficients[0][2] -
		matrix.coefficients[2][0] * matrix.coefficients[1][1] * matrix.coefficients[0][2] -
		matrix.coefficients[0][0] * matrix.coefficients[2][1] * matrix.coefficients[1][2] -
		matrix.coefficients[1][0] * matrix.coefficients[0][1] * matrix.coefficients[2][2];
	return det;
}

Matrix2x2 CreateTwoByTwoMatrix(const Matrix3x3 &matrix, int row, int column)
{
	Matrix2x2 matrix2x2;
	int matrix2x2Row = 0;

	for (int i = 0; i < MATRIX_SIZE; ++i)
	{
		int matrix2x2Col = 0;
		if (i != column)
		{
			for (int j = 0; j < MATRIX_SIZE; ++j)
			{
				if (j != row)
				{
					matrix2x2.coefficients[matrix2x2Row][matrix2x2Col] = matrix.coefficients[j][i];
					matrix2x2Col++;
				}
			}
			matrix2x2Row++;
		}
	}
	return matrix2x2;
}

double GetDeterminantTwoByTwoMatrix(const Matrix2x2 &matrix)
{
	return matrix.coefficients[0][0] * matrix.coefficients[1][1] - matrix.coefficients[0][1] * matrix.coefficients[1][0];
}

Matrix3x3 FindMinorsMatrix(const Matrix3x3 &matrix)
{
	Matrix3x3 minorMatrix;

	for (int i = 0; i < MATRIX_SIZE; ++i)
	{
		for (int j = 0; j < MATRIX_SIZE; ++j)
		{
			Matrix2x2 twoByTwoMatrix = CreateTwoByTwoMatrix(matrix, j, i);
			minorMatrix.coefficients[i][j] = GetDeterminantTwoByTwoMatrix(twoByTwoMatrix);
		}
	}
	return minorMatrix;
}

void GetMatrixWithOppositeCoefficientsInOddDegree(Matrix3x3 &matrix)
{
	matrix.coefficients[0][1] = -matrix.coefficients[0][1];
	matrix.coefficients[1][0] = -matrix.coefficients[1][0];
	matrix.coefficients[1][2] = -matrix.coefficients[1][2];
	matrix.coefficients[2][1] = -matrix.coefficients[2][1];
}

Matrix3x3 FindAlgebraicComplementsMatrix(const Matrix3x3 &matrix)
{
	Matrix3x3 minorsMatrix = FindMinorsMatrix(matrix);
	GetMatrixWithOppositeCoefficientsInOddDegree(minorsMatrix);
	return minorsMatrix;
}

Matrix3x3 CreateTransposeMatrix(const Matrix3x3 &matrix)
{
	Matrix3x3 transposeMatrix;

	for (int i = 0; i < MATRIX_SIZE; ++i)
	{
		for (int j = 0; j < MATRIX_SIZE; ++j)
		{
			transposeMatrix.coefficients[i][j] = matrix.coefficients[j][i];
		}
	}
	return transposeMatrix;
}

Matrix3x3 GetMatrixWithCoefficientsDividedByNumber(const Matrix3x3 &matrix, double number)
{
	Matrix3x3 resultMatrix;

	for (int i = 0; i < MATRIX_SIZE; ++i)
	{
		for (int j = 0; j < MATRIX_SIZE; ++j)
		{
			resultMatrix.coefficients[i][j] = matrix.coefficients[i][j] / number;
		}
	}
	return resultMatrix;
}

void PrintMatrix(const Matrix3x3 &matrix)
{
	cout << fixed;
	cout.precision(3);

	for (int i = 0; i < MATRIX_SIZE; ++i)
	{
		for (int j = 0; j < MATRIX_SIZE; ++j)
		{
			cout << matrix.coefficients[i][j];

			if (!(i == MATRIX_SIZE - 1 && j == MATRIX_SIZE - 1))
			{
				cout << ' ';
			}
		}
		if (i != MATRIX_SIZE - 1)
		{
			cout << endl;
		}
	}
}

bool FindInverseMatrix(const Matrix3x3 &matrix, Matrix3x3 &inverseMatrix)
{
	double determinant = GetDeterminant(matrix);
	if (determinant == 0)
	{
		return false;
	}

	Matrix3x3 algebraicComplementsMatrix = FindAlgebraicComplementsMatrix(matrix);
	Matrix3x3 transposeMatrix = CreateTransposeMatrix(algebraicComplementsMatrix);
	inverseMatrix = GetMatrixWithCoefficientsDividedByNumber(transposeMatrix, determinant);
	return true;
}