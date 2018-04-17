#include "stdafx.h"
#include "..\htmlDecode\htmlDecode.h"
#include <iostream>

using namespace std;

// Функция HtmlDecode
BOOST_AUTO_TEST_SUITE(HtmlDecode_function)

// Декодируем двойную кавычку
BOOST_AUTO_TEST_CASE(decode_double_quotation_mark)
{
	string quot = "&quot;";
	string result = HtmlDecode(quot);
	BOOST_CHECK("\"" == result);
}

// Декодируем апостроф
BOOST_AUTO_TEST_CASE(decode_apostrophe)
{
	string apos = "&apos;";
	string result = HtmlDecode(apos);
	BOOST_CHECK("\'" == result);
}

// Декодируем знак меньше
BOOST_AUTO_TEST_CASE(decode_sign_less)
{
	string sign_less = "&lt;";
	string result = HtmlDecode(sign_less);
	BOOST_CHECK("<" == result);
}

// Декодируем знак больше
BOOST_AUTO_TEST_CASE(decode_sign_more)
{
	string sign_more = "&gt;";
	string result = HtmlDecode(sign_more);
	BOOST_CHECK(">" == result);
}

// Декодируем амперсанд
BOOST_AUTO_TEST_CASE(decode_ampersand)
{
	string ampersand = "&amp;";
	string result = HtmlDecode(ampersand);
	BOOST_CHECK("&" == result);
}

// Декодируем все имеющиеся HTML сущности
BOOST_AUTO_TEST_CASE(decode_all_html_entities)
{
	string allHtmlEntities = "&quot;&apos;&lt;&gt;&amp;";
	string result = HtmlDecode(allHtmlEntities);
	BOOST_CHECK("\"\'<>&" == result);
}

// Декодируем два подряд знака меньше
BOOST_AUTO_TEST_CASE(decode_two_signs_less)
{
	string twoSignsLess = "&lt;&lt;";
	string result = HtmlDecode(twoSignsLess);
	BOOST_CHECK("<<" == result);
}

// Декодируем два амперсанда, между которыми одна двойная кавычка
BOOST_AUTO_TEST_CASE(decode_double_quotation_mark_between_two_ampersand)
{
	string doubleQuotationMarkBetweenTwoAmpersand = "&amp;&quot;&amp;";
	string result = HtmlDecode(doubleQuotationMarkBetweenTwoAmpersand);
	BOOST_CHECK("&\"&" == result);
}

BOOST_AUTO_TEST_SUITE_END()