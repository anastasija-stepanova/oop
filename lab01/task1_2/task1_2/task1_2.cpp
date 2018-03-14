// task1_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

bool CanBeNumber(string str)
{
	for (unsigned int i = 0; i < str.length(); i++)
	{
		if (!(str[i] >= '0' and str[i] <= '9'))
		{
			return false;
		}
	}
	return true;
}

bool InRange(int number)
{
	const unsigned int MIN_RANGE = 0;
	const unsigned int MAX_RANGE = 255;
	if (number >= MIN_RANGE and number <= MAX_RANGE)
	{
		return true;
	}
	return false;
}

uint8_t Reordering(uint8_t &number)
{
	const uint8_t MASK = 128;
	uint8_t result = 0;

	for (int i = 0; i < 8; i++)
	{
		result = result >> 1;
		result |= MASK & number;
		number = number << 1;
	}

	return result;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc < 3)
	{
		cout << "Неверно указаны аргументы командной строки! Пожалуйста укажите имена входной байт" << endl;
		return 1;
	}

	ifstream inputFile(argv[1]);

	if (!inputFile.is_open())
	{
		cout << "Входной файл не открыт!" << endl;
		return 1;
	}

	ofstream outputFile(argv[2]);
	if (!outputFile.is_open())
	{
		cout << "Выходной файл не открыт!" << endl;
		return 1;
	}

	string inputString;
	inputFile >> inputString;

	if (!CanBeNumber(inputString))
	{
		outputFile << "Введенная строка не может быть числом" << endl;
		return 1;
	}

	int number = stoi(inputString);
	if (!InRange(number))
	{
		outputFile << "Введенное число не входит в диапазон от 0 до 255" << endl;
		return 1;
	}

	uint8_t oneByteNumber = number;

	outputFile << (int) Reordering(oneByteNumber);

    return 0;
}

