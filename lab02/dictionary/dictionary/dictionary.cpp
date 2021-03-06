// task1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "dictionary.h"

using namespace std;

static const string EXIT_LINE = "...";

void ReadDictionaryFromFile(const string& inputFileName, dictionary& dictionary)
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

void AddWordToDictionary(dictionary& dictionary, const string& word, const string& translation)
{
	dictionary.insert(pair<string, string>(word, translation));
}

void UpdateDictionaryFile(const string &fileName, const dictionary& dictionary)
{
	ofstream dictionaryFile(fileName);

	for (auto it = dictionary.begin(); it != dictionary.end(); ++it)
	{
		dictionaryFile << (*it).first << endl;
		dictionaryFile << (*it).second << endl;
	}
}

bool CheckUserTranslation(dictionary& dictionary, const string& userString, const string& userTranslation)
{
	bool dictionaryHadChanged = false;
	if (!userTranslation.empty())
	{
		AddWordToDictionary(dictionary, userString, userTranslation);
		cout << "Слово '" << userString << "' сохранено в словаре как '" << userTranslation << "'." << endl;
		dictionaryHadChanged = true;
	}
	else
	{
		cout << "Слово '" << userString << "' проигнорировано." << endl;
	}
	return dictionaryHadChanged;
}

void FindWordInDictionary(dictionary& dictionary, const string& userString, string& userTranslation, bool& dictionaryHadChanged)
{
	using DictionaryIterator = dictionary::iterator;
	pair<DictionaryIterator, DictionaryIterator> rangeOfElements;
	rangeOfElements = dictionary.equal_range(userString);

	if (dictionary.find(userString) == dictionary.end())
	{
		cout << "Неизвестное слово '" << userString << "'. Введите перевод или пустую строку для отказа." << endl;
		cout << "> ";
		getline(cin, userTranslation);
		dictionaryHadChanged = CheckUserTranslation(dictionary, userString, userTranslation);
	}
	else
	{
		for (auto it = rangeOfElements.first; it != rangeOfElements.second; ++it)
		{
			cout << it->second << ' ';
		}
		cout << endl;
	}
}

string ToLowerCase(const string& userString)
{
	size_t size = userString.size();
	string result = userString;

	for (size_t i = 0; i < size; i++)
	{
		result[i] = (char)tolower(userString[i]);
	}

	return result;
}

bool DialogWithUser(dictionary& dictionary)
{
	string userString = "";
	string userTranslation = "";
	bool dictionaryHadChanged = false;

	cout << "Введите слово для перевода. Для выхода введите: '...'" << endl;
	cout << "> ";

	getline(cin, userString);
	userString = ToLowerCase(userString);

	if (userString != EXIT_LINE)
	{
		while (userString != EXIT_LINE)
		{
			FindWordInDictionary(dictionary, userString, userTranslation, dictionaryHadChanged);
			cout << "> ";
			getline(cin, userString);
			userString = ToLowerCase(userString);
		}
	}

	if (dictionaryHadChanged)
	{
		cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом." << endl;
	}

	return dictionaryHadChanged;
}

bool NeedToSave(const string& userString)
{
	return (ToLowerCase(userString) == "y");
}

void CheckForSavingChanges(dictionary& dictionary, const string& dictionaryFileName, const string& userString)
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
