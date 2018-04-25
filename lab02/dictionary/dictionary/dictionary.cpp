// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

using namespace std;

const string EXIT_LINE = "...";

void ReadDictionaryToMap(string inputFileName, multimap<string, string> &dictionary)
{
	ifstream dictionaryFile(inputFileName);
	string key;
	string value;
	while (dictionaryFile >> key)
	{
		dictionaryFile >> value;
		dictionary.insert(pair<string, string>(key, value));
	}
}

void PrintDictionary(const multimap<string, string> &dictionary)
{
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout << it->first << ' ' << it->second << '\n';
	}
}

void AddWordToDictionary(multimap<string, string> &dictionary, string word, string translation)
{
	dictionary.insert(pair<string, string>(word, translation));
}

void UpdateDictionaryFile(string fileName, const multimap<string, string> &dictionary)
{
	ofstream dictionaryFile(fileName);

	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		dictionaryFile << (*it).first << endl;
		dictionaryFile << (*it).second << endl;
	}
}

void checkUserTranslation(multimap<string, string> &dictionary, string userString, string userTranslation, bool &dictionaryHadChanged)
{
	if (userTranslation != "")
	{
		AddWordToDictionary(dictionary, userString, userTranslation);
		cout << "Слово '" << userString << "' сохранено в словаре как '" << userTranslation << "'." << endl;
		dictionaryHadChanged = true;
	}
	else
	{
		cout << "Слово '" << userString << "' проигнорировано." << endl;
	}
}

void checkUserString(multimap<string, string> &dictionary, string userString, string userTranslation, bool &dictionaryHadChanged)
{
	multimap<string, string>::iterator it = dictionary.find(userString);
	if (it != dictionary.end())
	{
		cout << it->second << endl;
	}
	else
	{
		cout << "Неизвестное слово '" << userString << "'. Введите перевод или пустую строку для отказа." << endl;
		cout << "> ";
		getline(cin, userTranslation);
		checkUserTranslation(dictionary, userString, userTranslation, dictionaryHadChanged);
	}
}

bool DialogWithUser(multimap<string, string> &dictionary)
{
	string userString = "";
	string userTranslation = "";
	bool dictionaryHadChanged = false;

	cout << "Введите слово для перевода. Для выхода введите: '...'" << endl;
	cout << "> ";

	getline(cin, userString);

	if (userString != EXIT_LINE)
	{
		while (userString != EXIT_LINE)
		{
			checkUserString(dictionary, userString, userTranslation, dictionaryHadChanged);
			cout << "> ";
			getline(cin, userString);
		}
    }
	
	if (dictionaryHadChanged)
	{
		cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом." << endl;
	}
	
	return dictionaryHadChanged;
}

bool NeedToSave(string userString)
{
	return ((userString == "Y") || (userString == "y")) ? true : false;
}

void checkForSavingChanges(multimap<string, string> &dictionary, string dictionaryFileName, string userString)
{
	if (NeedToSave(userString))
	{
		UpdateDictionaryFile(dictionaryFileName, dictionary);
		cout << "Изменения сохранены. До свидания.";
	}
	else
	{
		cout << "Изменения не были сохранены. До свидания.";
	}
}

int main(int argc, char *argv[])
{
	SetConsoleOutputCP(1251);
	SetConsoleCP(1251);

	if (argc < 2)
	{
		cout << "Неверно указаны аргументы командной строки! Пожалуйста укажите имя файла словоря" << endl;
		return 1;
	}
	
	string dictionaryFileName = argv[1];

	multimap<string, string> dictionary;
	ReadDictionaryToMap(dictionaryFileName, dictionary);

	bool dialogResult = DialogWithUser(dictionary);

	string userString = "";
	if (dialogResult)
	{
		cout << "> ";
		getline(cin, userString);

		checkForSavingChanges(dictionary, dictionaryFileName, userString);
	}

	return 0;
}