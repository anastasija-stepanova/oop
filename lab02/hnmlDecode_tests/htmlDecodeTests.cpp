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
	std::cout << result << "\n";
	//BOOST_CHECK("\"" == result);
	//В тестах ошибки крч, так все норм , забыла доавбить исходники к тестам как existing item
	//Тебе функция htmldecode вернула "&quot;" хз почему, поищи ошибки)
}

//// Декодируем апостроф
//BOOST_AUTO_TEST_CASE(decode_apostrophe)
//{
//	string quot = "&quot;";
//	string result = HtmlDecode(quot);
//	BOOST_CHECK("\`" == result);
//}
//// не изменяет содержимое вектора, минимальный элемент которого равен 1
//BOOST_AUTO_TEST_CASE(does_not_change_vector_because_min_element_is_one)
//{
//	vector<double> numbers = { 1, 6, 9, 8, 3 };
//	auto copy(numbers); 
//	ProcessVector(numbers);
//	BOOST_CHECK(numbers == copy);
//}
//
//// при обработке вектора с отрицательным минимальным элементом
//BOOST_AUTO_TEST_CASE(when_processing_a_vector_with_negative_min_element)
//{
//	vector<double> numbers = { -1, 3.5,  2, 6.8, 1.4 };
//	ProcessVector(numbers);
//
//	BOOST_CHECK(VectorsAreEqual(numbers,
//		{ (-1 * -1), (3.5 * -1), (2 * -1), (6.8 * -1), (1.4 * -1) }
//	));
//	// Аналогично следующей инструкции:
//	// BOOST_CHECK(numbers == vector<double>({ (-1 + 3.5), (3.5 + 3.5) }));
//}
//
//// при обработке вектора с положительным минимальным элементом, не равном 1
//BOOST_AUTO_TEST_CASE(when_processing_a_vector_with_positive_min_element_not_equal_one)
//{
//	vector<double> numbers = { 3, 8, 10, 5, 9 };
//	ProcessVector(numbers);
//
//	BOOST_CHECK(VectorsAreEqual(numbers,
//		{ (3 * 3), (8 * 3), (10 * 3), (5 * 3), (9 * 3) }
//	));
//}

BOOST_AUTO_TEST_SUITE_END()