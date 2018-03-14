// task1_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

void copyFile(ifstream &inputFile, ofstream &outputFile)
{
	char symbol;
	inputFile.get(symbol);
	while (!inputFile.eof())
	{
		outputFile << symbol;
		inputFile.get(symbol);
	}
	inputFile.close();
	outputFile.close();
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Russian");
	if (argc < 3)
	{
		cout << "Неверно указаны аргументы командной строки! Пожалуйста укажите имена входного и выходного файлов" << endl;
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
	
	copyFile(inputFile, outputFile);

    return 0;
}