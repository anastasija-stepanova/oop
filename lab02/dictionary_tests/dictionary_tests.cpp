#include "stdafx.h"
#include "../dictionary/dictionary/dictionary.h"

using namespace std;

struct cout_redirect {
	cout_redirect(std::streambuf * new_buffer)
		: old(std::cout.rdbuf(new_buffer))
	{ }

	~cout_redirect() {
		std::cout.rdbuf(old);
	}

private:
	std::streambuf * old;	
};

BOOST_AUTO_TEST_SUITE(FindWordInDictionary_function)

	BOOST_AUTO_TEST_CASE(find_word_in_dictionary_and_get_translation)
	{
		boost::test_tools::output_test_stream output;
		{
			cout_redirect guard(output.rdbuf());
			multimap<string, string> dictionary;
			dictionary.insert(pair<string, string>("meat", "мясо"));
			const string userString = "meat";
			string userTranslation = "мясо";
			bool dictionaryHadChanged = false;
			FindWordInDictionary(dictionary, userString, userTranslation, dictionaryHadChanged);
		}
		BOOST_CHECK(output.is_equal("мясо \n"));
	}
	
	BOOST_AUTO_TEST_CASE(when_word_is_not_in_dictionary)
	{
		boost::test_tools::output_test_stream output;
		{
			cout_redirect guard(output.rdbuf());
			multimap<string, string> dictionary;
			dictionary.insert(pair<string, string>("meat", "мясо"));
			const string userString = "dog";
			string userTranslation = "собака";
			bool dictionaryHadChanged = false;
			FindWordInDictionary(dictionary, userString, userTranslation, dictionaryHadChanged);
		}
		BOOST_CHECK(output.is_equal("Неизвестное слово 'dog'. Введите перевод или пустую строку для отказа.\n> Слово 'dog' проигнорировано.\n"));
	}
	
	BOOST_AUTO_TEST_CASE(translate_phrase)
	{
		boost::test_tools::output_test_stream output;
		{
			cout_redirect guard(output.rdbuf());
			multimap<string, string> dictionary;
			dictionary.insert(pair<string, string>("beautiful city", "красивый город"));
			const string userString = "beautiful city";
			string userTranslation = "красивый город";
			bool dictionaryHadChanged = false;
			FindWordInDictionary(dictionary, userString, userTranslation, dictionaryHadChanged);
		}
		BOOST_CHECK(output.is_equal("красивый город \n"));
	}

	BOOST_AUTO_TEST_CASE(several_translations)
	{
		boost::test_tools::output_test_stream output;
		{
			cout_redirect guard(output.rdbuf());
			multimap<string, string> dictionary;
			dictionary.insert(pair<string, string>("cat", "кошка"));
			dictionary.insert(pair<string, string>("cat", "кот"));
			const string userString = "cat";
			string userTranslation = "кошка";
			bool dictionaryHadChanged = false;
			FindWordInDictionary(dictionary, userString, userTranslation, dictionaryHadChanged);
		}
		BOOST_CHECK(output.is_equal("кошка кот \n"));
	}

BOOST_AUTO_TEST_SUITE_END()