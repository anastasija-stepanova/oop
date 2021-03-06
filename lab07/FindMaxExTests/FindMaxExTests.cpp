#include "stdafx.h"
#include "../FindMaxEx/FindMaxEx/CAthlete.h"
#include "../FindMaxEx/FindMaxEx/FindMaxEx.h"

using namespace std;

BOOST_AUTO_TEST_SUITE(find_max)

	BOOST_AUTO_TEST_CASE(when_vector_is_empty)
	{
		vector<CAthlete> emptyVector;
		CAthlete element;
		BOOST_CHECK(!FindMax(emptyVector, element, [](const auto& first, const auto& second) {
			return first.GetHeight() < first.GetHeight();
		}));
	}

	BOOST_AUTO_TEST_CASE(when_vector_is_not_empty)
	{
		vector<CAthlete> athletes = {
			CAthlete("Misha", 50, 160),
			CAthlete("Valya", 49, 158),
			CAthlete("Roma", 75, 180),
			CAthlete("Petya", 61, 177),
			CAthlete("Sasha", 84, 190),
		};

		CAthlete athlete;
		BOOST_CHECK(FindMax(athletes, athlete, [](const auto& first, const auto& second) {
			return first.GetHeight() < first.GetHeight();
		}));
	}

BOOST_AUTO_TEST_SUITE_END()

struct ElementsInt
{
	int value1;
	int value2;
	string stringId;
};

BOOST_FIXTURE_TEST_SUITE(get_max_in_int_array, ElementsInt)

	BOOST_AUTO_TEST_CASE(get_max_when_vector_consist_integer_numbers)
	{
		vector<ElementsInt> elements = {
			{ 1, 2, "1" },
			{ 3, 4, "2" },
			{ 5, 6, "3" }
		};

		ElementsInt element;
		BOOST_CHECK(FindMax(elements, element, [](const auto& first, const auto& second) {
			return first.value1 < second.value1;
		}));

		BOOST_CHECK_EQUAL(element.stringId, "3");
	}

	BOOST_AUTO_TEST_CASE(get_max_when_vector_consist_equals_integer_numbers)
	{
		vector<ElementsInt> elements = {
			{ 1, 1, "1" },
			{ 1, 1, "2" },
			{ 1, 1, "3" }
		};

		ElementsInt element;
		BOOST_CHECK(FindMax(elements, element, [](const auto& first, const auto& second) {
			return first.value1 < second.value1;
		}));

		BOOST_CHECK_EQUAL(element.stringId, "1");
	}

	BOOST_AUTO_TEST_CASE(get_min_when_vector_consist_equals_integer_numbers)
	{
		vector<ElementsInt> elements = {
			{ 1, 1, "1" },
			{ 1, 1, "2" },
			{ 1, 1, "3" }
		};

		ElementsInt element;
		BOOST_CHECK(FindMax(elements, element, [](const auto& first, const auto& second) {
			return first.value1 > second.value1;
		}));

		BOOST_CHECK_EQUAL(element.stringId, "1");
	}

BOOST_AUTO_TEST_SUITE_END()

struct ElementsDouble
{
	double value1;
	double value2;
	string stringId;
};

BOOST_FIXTURE_TEST_SUITE(get_max_in_double_array, ElementsDouble)

	BOOST_AUTO_TEST_CASE(get_max_when_vector_consist_double_numbers)
	{
		vector<ElementsDouble> elements = {
			{ 5.123, 2.321, "1" },
			{ 3.4321, 4.4312, "2" },
			{ 1.242314, 6.431, "3" },
		};

		ElementsDouble element;
		BOOST_CHECK(FindMax(elements, element, [](const auto& first, const auto& second) {
			return first.value2 < second.value2;
		}));

		BOOST_CHECK_EQUAL(element.stringId, "3");
	}

	BOOST_AUTO_TEST_CASE(get_max_when_vector_consist__equals_double_numbers)
	{
		vector<ElementsDouble> elements = {
			{ 1.0, 1.0, "1" },
			{ 1.0, 1.0, "2" },
			{ 1.0, 1.0, "3" },
		};

		ElementsDouble element;
		BOOST_CHECK(FindMax(elements, element, [](const auto& first, const auto& second) {
			return first.value2 < second.value2;
		}));

		BOOST_CHECK_EQUAL(element.stringId, "1");
	}

	BOOST_AUTO_TEST_CASE(get_min_when_vector_consist__equals_double_numbers)
	{
		vector<ElementsDouble> elements = {
			{ 1.0, 1.0, "1" },
			{ 1.0, 1.0, "2" },
			{ 1.0, 1.0, "3" },
		};

		ElementsDouble element;
		BOOST_CHECK(FindMax(elements, element, [](const auto& first, const auto& second) {
			return first.value2 > second.value2;
		}));

		BOOST_CHECK_EQUAL(element.stringId, "1");
	}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE(check_commit_or_rollback)

	BOOST_AUTO_TEST_CASE(use_CBadAthlete)
	{
		std::vector<CBadAthlete> badAthletes{
			{ "Misha", 50, 160 },
			{ "Valya", 49, 158 },
			{ "Roma", 75, 180 },
			{ "Petya", 61, 177 },
			{ "Sasha", 84, 190 },
		};

		CBadAthlete max;
		badAthletes[1].m_throwExc = true;
		try
		{
			FindMax(badAthletes, max, [](const CBadAthlete& first, const CBadAthlete& second) {
				return first.m_weight < second.m_weight;
			});
		}
		catch (...)
		{
			BOOST_CHECK(max == CBadAthlete());
		}
	}

BOOST_AUTO_TEST_SUITE_END()
