// task1_1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

bool CopyFile(istream &inputFile, ostream &outputFile) 
{
    char symbol;
	while (inputFile.get(symbol)) 
	{
		if (!outputFile.put(symbol)) 
		{
			cout << "Не удалось скопировать файл" << endl;
			return false;
		}
	}
	return true;
}

bool Copy(string input, string output)
{
	ifstream inputFile(input);
	if (!inputFile.is_open()) 
	{
		cout << "Входной файл не открыт!" << endl;
		return false;
	}

	ofstream outputFile(output);
	if (!outputFile.is_open()) 
	{
		cout << "Выходной файл не открыт!" << endl;
		return false;
	}

	if (!CopyFile(inputFile, outputFile) && !outputFile.flush()) 
	{
		cout << "Не удалось скопировать файл" << endl;
		return false;
	}

  return true;
}

int main(int argc, char *argv[]) 
{
	setlocale(LC_ALL, "Russian");
	if (argc < 3) 
	{
		cout << "Неверно указаны аргументы командной строки! Пожалуйста укажите имена входного и выходного файлов" << endl;
		return 1;
	}

	if (!Copy(argv[1], argv[2])) 
	{
		return 1;
	}

  return 0;
}
