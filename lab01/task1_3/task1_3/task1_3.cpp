#include "stdafx.h"
#include "Invert.h"

using namespace std;

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