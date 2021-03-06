#include "stdafx.h"

using namespace std;

bool CanFitToByte(int number)
{
	const unsigned int MIN_RANGE = 0;
	const unsigned int MAX_RANGE = 255;
	if (number >= MIN_RANGE and number <= MAX_RANGE)
	{
		return true;
	}
	return false;
}

uint8_t FlipByte(uint8_t number)
{
	const uint8_t MASK = 1 << (8 - 1);
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
	if (argc < 2)
	{
		cout << "Неверно указаны аргументы командной строки! Пожалуйста укажите входной байт" << endl;
		return 1;
	}

	int number;
	try
	{
		number = stoi(argv[1]);
	}
	catch (exception &e)
	{
		cout << e.what();
		return 1;
	}

	if (!CanFitToByte(number))
	{
		cout << "Введенное число не входит в диапазон от 0 до 255" << endl;
		return 1;
	}

	uint8_t oneByteNumber = number;

	cout << (int) FlipByte(oneByteNumber);
	
	return 0;
}
