#include "stdafx.h"
#include "dictionary.h"

using namespace std;

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
	cout << dictionaryFileName << endl;
	multimap<string, string> dictionary;
	ReadDictionaryToMap(dictionaryFileName, dictionary);
	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		cout << (*it).first << ' ';
		cout << (*it).second << endl;
	}

	bool dialogResult = DialogWithUser(dictionary);

	string userString = "";
	if (dialogResult)
	{
		cout << "> ";
		getline(cin, userString);

		CheckForSavingChanges(dictionary, dictionaryFileName, userString);
	}

	return 0;
}