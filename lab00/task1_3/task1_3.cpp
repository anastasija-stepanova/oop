// task1_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int StringToInt(const char * str, bool & err)
{
	char * pLastChar = NULL;
	int param = strtol(str, &pLastChar, 10);
	err = ((*str == '\0') || (*pLastChar != '\0'));
	return param;

}

int GetFibonacciNumber(int number)
{
	if (number < 1)
	{
		return 0;
	}
	else if(number == 1)
	{
		return 1;
	}
	else
	{
		return (GetFibonacciNumber(number - 1) + GetFibonacciNumber(number - 2));
	}
}

int main(int argc, char* argv[])
{
	const int MAX_NUMBER_ELEMENTS = 5;
	const int MAX_INT = 2147483647;
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
		cout << "Введенный верхний предел диапазона не является целым числом. Пожалуйста введите положительное целое число." << endl;
		return 1;
	}

	if (rangeLimit < 0)
	{
		cout << "Верхний предел диапазона введен неверно. Пожалуйста введите положительное целое число." << endl;
		return 1;
	}

	if (rangeLimit >= MAX_INT)
	{
		cout << "Переполнение. Пожалуйста введите число от 2 до 2147483647." << endl;
		return 1;
	}

	for (int i = 0; i < rangeLimit; i++)
	{
		if (i != 0)
		{
			cout << ',';
		} 
		if ((i % MAX_NUMBER_ELEMENTS == 0) && (i != 0))
		{
			cout << endl;
		}
		
		cout << GetFibonacciNumber(i);
	}
    return 0;
}

