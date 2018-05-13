#pragma once
#include "stdafx.h"

using namespace std;

void ReadDictionaryToMap(const string& inputFileName, multimap<string, string>& dictionary);
bool DialogWithUser(multimap<string, string>& dictionary);
void CheckForSavingChanges(multimap<string, string>& dictionary, const string& dictionaryFileName, const string& userString);
void CheckUserString(multimap<string, string>& dictionary, const string& userString, string& userTranslation, bool& dictionaryHadChanged);
