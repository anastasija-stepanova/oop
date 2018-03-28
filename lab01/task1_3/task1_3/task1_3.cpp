#include "stdafx.h"

using namespace std;

const int SIZE_MATRIX = 3;
struct Matrix
{
	double coefficients[SIZE_MATRIX][SIZE_MATRIX];
};

void ReadMatrix(istream &input, Matrix &matrix)
{
	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < SIZE_MATRIX; ++j)
		{
			input >> matrix.coefficients[j][i];
		}
	}
}

double GetDeterminant(Matrix &matrix)
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

vector<double> CreateTwoByTwoMatrix(Matrix &matrix, int amountRows, int amountColumns)
{
	vector<double> twoByTwoMatrix;

	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < SIZE_MATRIX; ++j)
		{
			if ((i != amountColumns) &&  (j != amountRows))
			{
				twoByTwoMatrix.push_back(matrix.coefficients[j][i]);
			}
		}
	}
	return twoByTwoMatrix;
}

double GetDeterminantTwoByTwoMatrix(vector<double> matrix)
{
	return (matrix[0] * matrix[3]) - (matrix[2] * matrix[1]);
}


Matrix FindMatrixMinors(Matrix &matrix)
{
	Matrix minorMatrix;

	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < SIZE_MATRIX; ++j)
		{
			vector<double> twoByTwoMatrix = CreateTwoByTwoMatrix(matrix, j, i);
			minorMatrix.coefficients[j][i] = GetDeterminantTwoByTwoMatrix(twoByTwoMatrix);
		}
	}
	return minorMatrix;
}

void FindMatrixAlgebraicComplements(Matrix &matrix)
{
	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < SIZE_MATRIX; ++j)
		{
			matrix.coefficients[j][i] = pow(-1, (i + j)) * matrix.coefficients[j][i];
		}
	}
}

Matrix CreateTransposeMatrix(Matrix &matrix)
{
	Matrix transposeMatrix;

	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < SIZE_MATRIX; ++j)
		{
			transposeMatrix.coefficients[i][j] = matrix.coefficients[j][i];
		}
	}
	return transposeMatrix;
}

Matrix GetInverseMatrix(Matrix &matrix, double det)
{
	Matrix inverseMatrix;

	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < SIZE_MATRIX; ++j)
		{
			inverseMatrix.coefficients[j][i] = matrix.coefficients[j][i] / det;
		}
	}
	return inverseMatrix;
}

void PrintMatrix(Matrix const &matrix)
{
	cout << fixed;
	cout.precision(3);

	for (int i = 0; i < SIZE_MATRIX; ++i)
	{
		for (int j = 0; j < SIZE_MATRIX; ++j)
		{
			cout << matrix.coefficients[j][i];

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

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc < 2)
	{
		cout << "Неверно указаны аргументы командной строки! Пожалуйста укажите входной файл" << endl;
		return 1;
	}

	ifstream fileInput(argv[1]);
	Matrix matrix;
	ReadMatrix(fileInput, matrix);
	double determinant = GetDeterminant(matrix);

	if (determinant == 0)
	{
		cout << "Определитель матрицы равен нулю. Обратной матрицы не существует" << endl;
		return 1;
	}

	Matrix matrixMinors = FindMatrixMinors(matrix);
	FindMatrixAlgebraicComplements(matrixMinors);

	Matrix transposeMatrix = CreateTransposeMatrix(matrixMinors);
	Matrix inverseMatrix = GetInverseMatrix(transposeMatrix, determinant);

	PrintMatrix(inverseMatrix);

    return 0;
}

