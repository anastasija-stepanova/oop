// task1_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc < 2)
	{
		cout << "Неверно указаны аргументы командной строки! Пожалуйста укажите имена входной байт" << endl;
		return 1;
	}

	int number = stoi(argv[1]);

	char * binNumber;
	do
	{
		int temp = number % 2;
		binNumber += char(temp);
		number /= 2;
	} while (number != 0);
	

	cout << binNumber;
    return 0;
}

