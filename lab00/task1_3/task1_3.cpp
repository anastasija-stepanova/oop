#include "stdafx.h"

using namespace std;

bool PrintFibonacci(const unsigned int maxNumber)
{
	unsigned int previousNumber = 0;
	unsigned int currentNumber = 1;
	unsigned int counterElements = 0;

	cout << previousNumber;
	while (currentNumber < maxNumber)
	{
		cout << ", ";
		const unsigned int LINE_ITEM_COUNT = 5;
		if ((counterElements + 1) % LINE_ITEM_COUNT == 0)
		{
			cout << "\n";
			counterElements = 0;
		}
		else
		{
			++counterElements;
		}
		cout << currentNumber;

		if (currentNumber + previousNumber < UINT_MAX)
		{
			currentNumber = currentNumber + previousNumber;
			previousNumber = currentNumber - previousNumber;
		}
		else
		{
			return false;
		}
	}

	return true;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc < 2)
	{
		cout << "Неверно указан аргумент командной строки! Пожалуйста укажите верхнюю границу предела" << endl;
		return 1;
	}

	unsigned int maxNumber;
	try
	{
		maxNumber = stoi(argv[1]);
	}
	catch (exception &e)
	{
		cout << e.what();
		return 1;
	}

	if (!PrintFibonacci(maxNumber))
	{
		cout << "Fibonacci number overflow";
		return 1;
	}

    return 0;
}

