#include "stdafx.h"

using namespace std;

const int SIZE_MATRIX = 3;

struct Matrix3x3 {
	double coefficients[SIZE_MATRIX][SIZE_MATRIX];
};

struct Matrix2x2 {
	double coefficients[SIZE_MATRIX - 1][SIZE_MATRIX - 1];
};

bool ReadMatrix(istream &inputFileName, Matrix3x3 &matrix)
{
	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < SIZE_MATRIX; ++j)
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
		cout << "Входной файл не удалось открыть для чтения" << endl;;
		return false;
	}

	if (!ReadMatrix(inputFile, matrix))
	{
		cout << "Не удалось считать матрицу с файла" << endl;
		return false;
	}
	return true;
}

double GetDeterminant(Matrix3x3 &matrix)
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

Matrix2x2 CreateTwoByTwoMatrix(const Matrix3x3 &matrix, int amountRows, int amountColumns)
{
	Matrix2x2 twoByTwoMatrix;
	int twoByTwoMatrixCol = 0;
	int twoByTwoMatrixRow = 0;

	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		twoByTwoMatrixCol = 0;
		if (i != amountColumns)
		{
			for (int j = 0; j < SIZE_MATRIX; ++j)
			{
				if (j != amountRows)
				{
					twoByTwoMatrix.coefficients[twoByTwoMatrixRow][twoByTwoMatrixCol] = matrix.coefficients[j][i];
					twoByTwoMatrixCol++;
				}
			}
			twoByTwoMatrixRow++;
		}
	}
	return twoByTwoMatrix;
}

double GetDeterminantTwoByTwoMatrix(const Matrix2x2 &matrix)
{
	return matrix.coefficients[0][0] * matrix.coefficients[1][1] - matrix.coefficients[0][1] * matrix.coefficients[1][0];
}


Matrix3x3 FindMatrixMinors(Matrix3x3 &matrix)
{
	Matrix3x3 minorMatrix;

	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < SIZE_MATRIX; ++j)
		{
			Matrix2x2 twoByTwoMatrix = CreateTwoByTwoMatrix(matrix, j, i);
			minorMatrix.coefficients[i][j] = GetDeterminantTwoByTwoMatrix(twoByTwoMatrix);
		}
	}
	return minorMatrix;
}

Matrix3x3 FindMatrixAlgebraicComplements(Matrix3x3 &matrix)
{
	matrix.coefficients[0][1] = -matrix.coefficients[0][1];
	matrix.coefficients[1][0] = -matrix.coefficients[1][0];
	matrix.coefficients[1][2] = -matrix.coefficients[1][2];
	matrix.coefficients[2][1] = -matrix.coefficients[2][1];
	return matrix;
}

Matrix3x3 CreateTransposeMatrix(const Matrix3x3 &matrix)
{
	Matrix3x3 transposeMatrix;

	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < SIZE_MATRIX; ++j)
		{
			transposeMatrix.coefficients[i][j] = matrix.coefficients[j][i];
		}
	}
	return transposeMatrix;
}

Matrix3x3 GetInverseMatrix(const Matrix3x3 &matrix, double det)
{
	Matrix3x3 inverseMatrix;

	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < SIZE_MATRIX; ++j)
		{
			inverseMatrix.coefficients[i][j] = matrix.coefficients[i][j] / det;
		}
	}
	return inverseMatrix;
}

void PrintMatrix(Matrix3x3 const &matrix)
{
	cout << fixed;
	cout.precision(3);

	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < SIZE_MATRIX; ++j)
		{
			cout << matrix.coefficients[i][j];

			if (!(i == SIZE_MATRIX - 1 && j == SIZE_MATRIX - 1))
			{
				cout << ' ';
			}
		}
		if (i != SIZE_MATRIX - 1)
		{
			cout << endl;	
		}
	}
}

bool FindInverseMatrix(Matrix3x3 &matrix, Matrix3x3 &inverseMatrix)
{
	double determinant = GetDeterminant(matrix);
	if (determinant == 0)
	{
		return false;
	}

	Matrix3x3 matrixMinors = FindMatrixMinors(matrix);
	Matrix3x3 matrixAlgebraicComplements = FindMatrixAlgebraicComplements(matrixMinors);
	Matrix3x3 transposeMatrix = CreateTransposeMatrix(matrixAlgebraicComplements);
	inverseMatrix = GetInverseMatrix(transposeMatrix, determinant);
	return true;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc < 2)
	{
		cout << "Неверно указаны аргументы командной строки! Пожалуйста укажите входной файл" << endl;
		return 1;
	}

	Matrix3x3 matrix;
	if (!ReadMatrixFromFile(argv[1], matrix))
	{
		return 1;
	}

	Matrix3x3 inverseMatrix;
	if (!FindInverseMatrix(matrix, inverseMatrix))
	{
		cout << "Определитель матрицы равен нулю. Обратной матрицы не существует" << endl;
		return 1;
	}
	else
	{
		PrintMatrix(inverseMatrix);
	}

    return 0;
}