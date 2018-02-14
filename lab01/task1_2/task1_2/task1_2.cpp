// task1_2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc < 5)
	{
		cout << "Неверно указаны аргументы командной строки! Пожалуйста укажите имена входного и выходного файлов, а так же искомую строку и заменяющую строку" << endl;
		return 1;
	}

	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);

	if (!inputFile.is_open())
	{
		cout << "Входной файл не открыт!" << endl;
		return 1;
	}
    return 0;
}

