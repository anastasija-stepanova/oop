#pragma once
#include <string>
#include <map>
#include <cctype>

using dictionary = std::multimap<std::string, std::string>;

void ReadDictionaryFromFile(const std::string& inputFileName, dictionary& dictionary);
bool DialogWithUser(dictionary& dictionary);
void CheckForSavingChanges(dictionary& dictionary, const std::string& dictionaryFileName, const std::string& userString);
void FindWordInDictionary(dictionary& dictionary, const std::string& userString, std::string& userTranslation, bool& dictionaryHadChanged);
