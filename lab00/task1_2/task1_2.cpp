// task1_2.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int SumDigits(int i)
{
	int sum = 0;
	// цикл продолжается до тех пор, пока число не станет равным 0
	while (i != 0)
	{
		sum += i % 10;
		i /= 10;
	}
	return sum;
}

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc < 2)
	{
		cout << "Неверно указан аргумент командной строки! Пожалуйста укажите верхнюю границу предела" << endl;
		return 1;
	}

	bool err;
	int rangeLimit = StringToInt(argv[1], err);
	if (err)
	{
		cout << "Введенный верхний предел диапазона не является числом" << endl;
		return 1;
	}

	for (int i = 1; i <= rangeLimit; ++i)
	{
		int sum = SumDigits(i);
		int mod = i % sum;
		if (mod == 0)
		{
			cout << i << endl;
		}
	}
	return 0;
}