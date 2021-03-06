#include "stdafx.h"
#include "../RationalNumbers/RationalNumbers/CRational.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void VerifyRational(const CRational& rational, int expectedNumerator, int expectedDenominator)
{
	BOOST_CHECK(rational.GetNumerator() == expectedNumerator);
	BOOST_CHECK(rational.GetDenominator() == expectedDenominator);
}

void VerifyRationalToDouble(const CRational& rational, double expectedDouble)
{
	auto delta = abs(rational.ToDouble() - expectedDouble);
	BOOST_CHECK(delta < DBL_EPSILON);
}

void VerifyCompoundFraction(const CRational& rational, int expectedInteger, int expectedNumerator, int expectedDenominator)
{
	auto compoundFraction = rational.ToCompoundFraction();
	BOOST_CHECK(compoundFraction.first == expectedInteger);
	VerifyRational(compoundFraction.second, expectedNumerator, expectedDenominator);
}

BOOST_AUTO_TEST_SUITE(Rational)
	BOOST_AUTO_TEST_CASE(zero_by_default)
	{
		VerifyRational(CRational(), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_not_have_zero_denominator)
	{
		BOOST_REQUIRE_THROW(CRational(1, 0), invalid_argument);
	}
	BOOST_AUTO_TEST_CASE(can_be_initialized_with_numerator)
	{
		VerifyRational(CRational(12), 12, 1);
		VerifyRational(CRational(-12), -12, 1);
		VerifyRational(CRational(0), 0, 1);
	}
	BOOST_AUTO_TEST_CASE(can_be_initialized_with_numerator_and_denominator)
	{
		VerifyRational(CRational(12, 3), 4, 1);
		VerifyRational(CRational(-12, -3), 4, 1);
		VerifyRational(CRational(-12, 3), -4, 1);
		VerifyRational(CRational(12, -3), -4, 1);
	}
	BOOST_AUTO_TEST_CASE(is_normalized_form_after_construction)
	{
		VerifyRational(CRational(20, 10), 2, 1);
		VerifyRational(CRational(6, 42), 1, 7);
		VerifyRational(CRational(-6, 42), -1, 7);
		VerifyRational(CRational(-15, -90), 1, 6);
	}
	BOOST_AUTO_TEST_CASE(can_be_converted_to_double)
	{
		VerifyRationalToDouble(CRational(3, 5), 0.6);
		VerifyRationalToDouble(CRational(1, 2), 0.5);
	}

	struct binary_operator_
	{
		CRational rational = CRational(3, 2);
	};

	BOOST_FIXTURE_TEST_SUITE(binary_operator, binary_operator_)
		BOOST_AUTO_TEST_SUITE(opearator_addition)
			BOOST_AUTO_TEST_CASE(addition_of_two_rational_numbers)
			{
				auto result = rational + CRational(1, 2);
				VerifyRational(result, 2, 1);
			}
			BOOST_AUTO_TEST_CASE(addition_of_rational_and_integer)
			{
				auto result = rational + 3;
				VerifyRational(result, 9, 2);
			}
			BOOST_AUTO_TEST_CASE(addition_of_integer_and_rational)
			{
				auto result = 2 + rational;
				VerifyRational(result, 7, 2);
			}
		BOOST_AUTO_TEST_SUITE_END()
		BOOST_AUTO_TEST_SUITE(opearator_subtraction)
			BOOST_AUTO_TEST_CASE(subtraction_of_two_rational_numbers)
			{
				auto result = rational - CRational(1, 2);
				VerifyRational(result, 1, 1);
			}
			BOOST_AUTO_TEST_CASE(subtraction_of_rational_and_integer)
			{
				auto result = rational - 1;
				VerifyRational(result, 1, 2);
			}
			BOOST_AUTO_TEST_CASE(subtraction_of_integer_and_rational)
			{
				auto result = 1 - rational;
				VerifyRational(result, -1, 2);
			}
		BOOST_AUTO_TEST_SUITE_END()
		BOOST_AUTO_TEST_SUITE(opearator_multiplication)
			BOOST_AUTO_TEST_CASE(multiplication_of_two_rational_numbers)
			{
				auto result = rational * CRational(1, 2);
				VerifyRational(result, 3, 4);
			}
			BOOST_AUTO_TEST_CASE(multiplication_of_rational_and_integer)
			{
				auto result = rational * 2;
				VerifyRational(result, 3, 1);
			}
			BOOST_AUTO_TEST_CASE(multiplication_of_integer_and_rational)
			{
				auto result = 4 * rational;
				VerifyRational(result, 6, 1);
			}
		BOOST_AUTO_TEST_SUITE_END()
		BOOST_AUTO_TEST_SUITE(opearator_division)
			BOOST_AUTO_TEST_CASE(division_of_two_rational_numbers)
			{
				auto result = rational / CRational(1, 2);
				VerifyRational(result, 3, 1);
			}
			BOOST_AUTO_TEST_CASE(division_of_rational_and_integer)
			{
				auto result = rational / 2;
				VerifyRational(result, 3, 4);
			}
			BOOST_AUTO_TEST_CASE(division_of_integer_and_rational)
			{
				auto result = 4 / rational;
				VerifyRational(result, 8, 3);
			}
		BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE_END()

	struct unary_operator_
	{
		CRational rational = CRational(3, 2);
	};

	BOOST_FIXTURE_TEST_SUITE(unary_operatory, unary_operator_)
		BOOST_AUTO_TEST_CASE(unary_minus_changes_the_sign_of_numerator)
		{
			VerifyRational(-CRational(7, 2), -7, 2);
			VerifyRational(-CRational(-7, 2), 7, 2);
		}
		BOOST_AUTO_TEST_CASE(unary_plus_does_not_change_number)
		{
			VerifyRational(+CRational(5, 2), 5, 2);
			VerifyRational(+CRational(-5, 2), -5, 2);
		}
		BOOST_AUTO_TEST_SUITE(unary_addition)
			BOOST_AUTO_TEST_CASE(addition_of_rational)
			{
				rational += CRational(2, 5);
				VerifyRational(rational, 19, 10);
			}
			BOOST_AUTO_TEST_CASE(addition_of_integer)
			{
				rational += 5;
				VerifyRational(rational, 13, 2);
			}
		BOOST_AUTO_TEST_SUITE_END()
		BOOST_AUTO_TEST_SUITE(unary_subtraction)
			BOOST_AUTO_TEST_CASE(subtraction_of_rational)
			{
				rational -= CRational(1, 2);
				VerifyRational(rational, 1, 1);
			}
			BOOST_AUTO_TEST_CASE(subtraction_of_integer)
			{
				rational -= 5;
				VerifyRational(rational, -7, 2);
			}
		BOOST_AUTO_TEST_SUITE_END()
		BOOST_AUTO_TEST_SUITE(unary_multiplication)
			BOOST_AUTO_TEST_CASE(multiplication_of_rational)
			{
				rational *= CRational(1, 2);
				VerifyRational(rational, 3, 4);
			}
			BOOST_AUTO_TEST_CASE(multiplication_of_integer)
			{
				rational *= 5;
				VerifyRational(rational, 15, 2);
			}
		BOOST_AUTO_TEST_SUITE_END()
		BOOST_AUTO_TEST_SUITE(unary_divison)
			BOOST_AUTO_TEST_CASE(divison_of_rational)
			{
				rational /= CRational(1, 2);
				VerifyRational(rational, 3, 1);
			}
			BOOST_AUTO_TEST_CASE(divison_of_integer)
			{
				rational /= 5;
				VerifyRational(rational, 3, 10);
			}
		BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE_END()

	struct bool_operator_
	{
		CRational rational = CRational(5, 3);
	};

	BOOST_FIXTURE_TEST_SUITE(bool_operator, bool_operator_)

		BOOST_AUTO_TEST_SUITE(operator_equality)
			BOOST_AUTO_TEST_CASE(equality_of_two_rational_numbers)
			{
				BOOST_CHECK(!(rational == CRational(1, 2)));
				BOOST_CHECK(rational == CRational(5, 3));
			}
			BOOST_AUTO_TEST_CASE(equality_of_rational_and_integer)
			{
				BOOST_CHECK(!(rational == 2));
				BOOST_CHECK(CRational(10) == 10);
			}
			BOOST_AUTO_TEST_CASE(equality_of_integer_and_rational)
			{
				BOOST_CHECK(!(2 == rational));
				BOOST_CHECK(10 == CRational(10));
			}
		BOOST_AUTO_TEST_SUITE_END()

		BOOST_AUTO_TEST_SUITE(operator_inequality)
			BOOST_AUTO_TEST_CASE(inequality_of_two_rational_numbers)
			{
				BOOST_CHECK(rational != CRational(1, 2));
				BOOST_CHECK(!(rational != CRational(5, 3)));
			}
			BOOST_AUTO_TEST_CASE(inequality_of_rational_and_integer)
			{
				BOOST_CHECK(rational != 2);
				BOOST_CHECK(!(CRational(10) != 10));
			}
			BOOST_AUTO_TEST_CASE(inequality_of_integer_and_rational)
			{
				BOOST_CHECK(2 != rational);
				BOOST_CHECK(!(10 != CRational(10)));
			}
		BOOST_AUTO_TEST_SUITE_END()

		BOOST_AUTO_TEST_SUITE(operator_larger)
			BOOST_AUTO_TEST_CASE(one_rational_number_is_greater_than_the_other)
			{
				BOOST_CHECK(rational > CRational(2, 3));
				BOOST_CHECK(!(rational > CRational(7, 3)));
			}
			BOOST_AUTO_TEST_CASE(rational_number_greater_than_integer)
			{
				BOOST_CHECK(rational > 1);
				BOOST_CHECK(!(CRational(10) > 10));
			}
			BOOST_AUTO_TEST_CASE(integer_number_greater_than_rational)
			{
				BOOST_CHECK(2 > CRational(3, 2));
				BOOST_CHECK(!(10 > CRational(10)));
			}
		BOOST_AUTO_TEST_SUITE_END()

		BOOST_AUTO_TEST_SUITE(operator_larger_or_equally)
			BOOST_AUTO_TEST_CASE(larger_or_equally_of_two_rational_numbers)
			{
				BOOST_CHECK(rational >= CRational(5, 3));
				BOOST_CHECK(!(rational >= CRational(8, 3)));
			}
		
			BOOST_AUTO_TEST_CASE(larger_or_equally_of_rational_and_integer)
			{
				BOOST_CHECK(!(rational >= 5));
				BOOST_CHECK(CRational(10) >= 10);
			}
			BOOST_AUTO_TEST_CASE(larger_or_equally_of_integer_and_rational)
			{
				BOOST_CHECK(!(3 >= CRational(8, 2)));
				BOOST_CHECK(10 >= CRational(10));
			}
		BOOST_AUTO_TEST_SUITE_END()

		BOOST_AUTO_TEST_SUITE(operator_less)
			BOOST_AUTO_TEST_CASE(less_of_two_rational_numbers)
			{
				BOOST_CHECK(rational < CRational(7, 2));
				BOOST_CHECK(!(rational < CRational(1, 2)));
			}
			BOOST_AUTO_TEST_CASE(less_of_rational_and_integer)
			{
				BOOST_CHECK(rational < 2);
				BOOST_CHECK(!(CRational(10) < 10));
			}
			BOOST_AUTO_TEST_CASE(integer_less_than_rational)
			{
				BOOST_CHECK(2 < CRational(5, 2));
				BOOST_CHECK(!(10 < CRational(10)));
			}
		BOOST_AUTO_TEST_SUITE_END()

		BOOST_AUTO_TEST_SUITE(operator_less_or_equally)
			BOOST_AUTO_TEST_CASE(less_or_equally_of_two_rational_numbers)
			{
				BOOST_CHECK(rational <= CRational(5, 3));
				BOOST_CHECK(!(rational <= CRational(1, 2)));
			}
			BOOST_AUTO_TEST_CASE(less_or_equally_of_rational_and_integer)
			{
				BOOST_CHECK(!(rational <= 1));
				BOOST_CHECK(CRational(10) <= 10);
			}
			BOOST_AUTO_TEST_CASE(integer_less_than_or_equal_to_rational)
			{
				BOOST_CHECK(!(2 <= CRational(1, 2)));
				BOOST_CHECK(10 <= CRational(10));
			}
		BOOST_AUTO_TEST_SUITE_END()
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(stream)
		BOOST_AUTO_TEST_CASE(get_rational_from_istream)
		{
			CRational rational;
			istringstream istrm("7/13");
			istrm >> rational;
			VerifyRational(rational, 7, 13);
		}
		BOOST_AUTO_TEST_CASE(get_negative_rational_from_istream)
		{
			CRational rational;
			istringstream istrm("-7/13");
			istrm >> rational;
			VerifyRational(rational, -7, 13);
		}
		BOOST_AUTO_TEST_CASE(rational_to_ostream)
		{
			CRational rational(7, 13);
			ostringstream ostrm;
			ostrm << rational;
			BOOST_CHECK(ostrm.str() == "7/13");
		}
		BOOST_AUTO_TEST_CASE(negative_rational_to_ostream)
		{
			CRational rational(-7, 13);
			ostringstream ostrm;
			ostrm << rational;
			BOOST_CHECK(ostrm.str() == "-7/13");
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_CASE(when_rregular_fraction_can_be_allocated_whole_fractional_part)
	{
		CRational rational(16, 5);
		VerifyCompoundFraction(rational, 3, 1, 5);
	}
	BOOST_AUTO_TEST_CASE(can_get_compound_negative_fraction)
	{
		CRational rational(-16, 4);
		VerifyCompoundFraction(rational, -4, 0, 1);
	}
	BOOST_AUTO_TEST_CASE(when_fraction_less_than_1_then_integer_equal_to_zero)
	{
		CRational rational(1, 2);
		VerifyCompoundFraction(rational, 0, 1, 2);
	}
BOOST_AUTO_TEST_SUITE_END()
