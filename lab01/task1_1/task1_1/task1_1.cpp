// task1_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc < 3)
	{
		cout << "Неверно указаны аргументы командной строки! Пожалуйста укажите имена входного и выходного файлов" << endl;
		return 1;
	}

	ifstream inputFile(argv[1]);
	ofstream outputFile(argv[2]);

	if (!inputFile.is_open())
	{
		cout << "Входной файл не открыт!" << endl;
		return 1;
	}
	else
	{
		char buffer[256];
		while (!inputFile.eof())
		{
			inputFile >> buffer;
			if (!outputFile.is_open())
			{
				cout << "Выходной файл не открыт!" << endl;
				return 1;
			}
			else
			{
				outputFile << buffer;
			}
		}
		inputFile.close();
		outputFile.close();
	}

    return 0;
}

