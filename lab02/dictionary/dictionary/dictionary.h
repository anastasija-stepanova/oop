#pragma once
#include <string>
#include <map>
#include <cctype>

void ReadDictionaryToMap(const std::string& inputFileName, std::multimap<std::string, std::string>& dictionary);
bool DialogWithUser(std::multimap<std::string, std::string>& dictionary);
void CheckForSavingChanges(std::multimap<std::string, std::string>& dictionary, const std::string& dictionaryFileName, const std::string& userString);
void CheckUserString(std::multimap<std::string, std::string>& dictionary, const std::string& userString, std::string& userTranslation, bool& dictionaryHadChanged);
