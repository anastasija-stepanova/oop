#include "stdafx.h"

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc < 2)
	{
		cout << "Неверно указан аргумент командной строки! Пожалуйста укажите верхнюю границу предела" << endl;
		return 1;
	}

	int rangeLimit = stoi(argv[1]);

	cout << 0;
	unsigned lastNumber = 0;
	unsigned currentNumber = 1;
	unsigned i = 0;
	const unsigned MAX_NUMBER_ELEMENTS = 5;
	while (i < rangeLimit)
	{
		if (i != rangeLimit)
		{
			cout << ',';
		}
		if ((i + 1) % MAX_NUMBER_ELEMENTS == 0)
		{
			cout << "\n";
		}
		cout << currentNumber;
		unsigned tempVar = currentNumber;
		if (currentNumber + lastNumber < UINT_MAX)
		{
			currentNumber = currentNumber + lastNumber;
			lastNumber = tempVar;
			++i;
		}
		else
		{
			cout << "Произошло переполнение" << endl;
			return 1;
		}
	}

    return 0;
}

