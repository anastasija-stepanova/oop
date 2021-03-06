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
			return false;
		}
	}	
	
	if (!outputFile.flush()) 
	{
		return false;
	}
	return true;
}

bool Copy(const string &inputFileName, const string &outputFileName)
{
	ifstream inputFile(inputFileName);
	if (!inputFile.is_open()) 
	{
		cout << "Входной файл не открыт!" << endl;
		return false;
	}

	ofstream outputFile(outputFileName);
	if (!outputFile.is_open()) 
	{
		cout << "Выходной файл не открыт!" << endl;
		return false;
	}

	if (!CopyFile(inputFile, outputFile)) 
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

	string inputFileName = argv[1];
	string outputFileName = argv[2];
	if (!Copy(inputFileName, outputFileName))
	{
		return 1;
	}

  return 0;
}