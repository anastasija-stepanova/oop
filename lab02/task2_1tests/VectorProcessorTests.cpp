#include "stdafx.h"
#include "..\task2_1\task2_1\VectorProcessor.h"
#include <iostream>

using namespace std;

bool VectorsAreEqual(vector<double> const& x, vector<double> const& y)
{
	return x == y;
}

// Функция ProcessVector
BOOST_AUTO_TEST_SUITE(ProcessVector_function)

// Создает пустой вектор из пустого вектора
BOOST_AUTO_TEST_CASE(makes_empty_vector_from_empty_vector)
{
	vector<double> emptyVector;
	vector<double> finishedVector;
	ProcessVector(emptyVector, finishedVector);
	BOOST_CHECK(emptyVector.empty());
}

// не изменяет содержимое вектора, минимальный элемент которого равен 1
BOOST_AUTO_TEST_CASE(does_not_change_vector_because_min_element_is_one)
{
	vector<double> numbers = { 1, 6, 9, 8, 3 };
	vector<double> finishedVector;
	auto copy(numbers); 
	ProcessVector(numbers, finishedVector);
	BOOST_CHECK(finishedVector == copy);
}

// при обработке вектора с отрицательным минимальным элементом
BOOST_AUTO_TEST_CASE(when_processing_a_vector_with_negative_min_element)
{
	vector<double> numbers = { -1, 3.5,  2, 6.8, 1.4 };
	vector<double> finishedVector;
	ProcessVector(numbers, finishedVector);

	BOOST_CHECK(VectorsAreEqual(finishedVector,
		{ (-1 * -1), (3.5 * -1), (2 * -1), (6.8 * -1), (1.4 * -1) }
	));
	// Аналогично следующей инструкции:
	// BOOST_CHECK(numbers == vector<double>({ (-1 + 3.5), (3.5 + 3.5) }));
}

// при обработке вектора с положительным минимальным элементом, не равном 1
BOOST_AUTO_TEST_CASE(when_processing_a_vector_with_positive_min_element_not_equal_one)
{
	vector<double> numbers = { 3, 8, 10, 5, 9 };
	vector<double> finishedVector;
	ProcessVector(numbers, finishedVector);

	BOOST_CHECK(VectorsAreEqual(finishedVector,
		{ (3 * 3), (8 * 3), (10 * 3), (5 * 3), (9 * 3) }
	));
}

BOOST_AUTO_TEST_SUITE_END()