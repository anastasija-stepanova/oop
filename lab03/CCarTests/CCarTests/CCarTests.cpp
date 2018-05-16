// CCarTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../CCar/CCar/CCar.h"

struct CarFixture
{
	CCar car;

	void CheckSetSpeed(ConditionOfGearBox gear, int speed, bool result)
	{
		BOOST_CHECK(car.GetGear() == gear);
		BOOST_CHECK(car.SetSpeed(speed) == result);
	}

	void CheckSetGear(ConditionOfGearBox gear, ConditionOfGearBox newGear, bool result)
	{
		BOOST_CHECK(car.GetGear() == gear);
		BOOST_CHECK(car.SetGear(newGear) == result);
	}
};

BOOST_FIXTURE_TEST_SUITE(Car, CarFixture)
	BOOST_AUTO_TEST_CASE(is_turned_off_by_default)
	{
		BOOST_CHECK(!car.GetCarCondition());
	}
	BOOST_AUTO_TEST_CASE(is_zero_by_default)
	{
		BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	}
	BOOST_AUTO_TEST_CASE(is_neutral_by_default)
	{
		BOOST_CHECK(car.GetGear() == ConditionOfGearBox::Neutral);
	}
	BOOST_AUTO_TEST_CASE(is_still_by_default)
	{
		BOOST_CHECK(car.GetDirection() == Direction::Still);
	}

	struct when_car_turned_on_ : CarFixture
	{
		when_car_turned_on_()
		{
			car.TurnOnEngine();
		}
	};
	BOOST_FIXTURE_TEST_SUITE(when_car_is_turn_on, when_car_turned_on_)
		BOOST_AUTO_TEST_CASE(cannot_turn_on_if_already_had_turned_on)
		{
			BOOST_CHECK(!car.TurnOnEngine());
		}
		BOOST_AUTO_TEST_CASE(from_neutral_to_first)
		{
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::First, true);
		}
		BOOST_AUTO_TEST_CASE(from_first_to_reverse)
		{
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::First, true);
			CheckSetGear(ConditionOfGearBox::First, ConditionOfGearBox::Reverse, true);
		}
		BOOST_AUTO_TEST_CASE(from_neutral_to_reverse)
		{
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::Reverse, true);
		}
		BOOST_AUTO_TEST_CASE(from_reverse_to_first)
		{
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::Reverse, true);
			CheckSetGear(ConditionOfGearBox::Reverse, ConditionOfGearBox::First, true);
		}
		BOOST_AUTO_TEST_CASE(when_neutral_speed_is_only_zero)
		{
			CheckSetSpeed(ConditionOfGearBox::Neutral, 50, false);
		}
		BOOST_AUTO_TEST_CASE(when_first)
		{
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::First, true);
			CheckSetSpeed(ConditionOfGearBox::First, 30, true);
			CheckSetSpeed(ConditionOfGearBox::First, 150, false);
		}
		BOOST_AUTO_TEST_CASE(when_second)
		{
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::First, true);
			CheckSetSpeed(ConditionOfGearBox::First, 30, true);
			CheckSetGear(ConditionOfGearBox::First, ConditionOfGearBox::Second, true);
			CheckSetSpeed(ConditionOfGearBox::Second, 40, true);
			CheckSetSpeed(ConditionOfGearBox::Second, 51, false);
			CheckSetSpeed(ConditionOfGearBox::Second, 19, false);
		}
		BOOST_AUTO_TEST_CASE(when_third)
		{
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::First, true);
			CheckSetSpeed(ConditionOfGearBox::First, 30, true);
			CheckSetGear(ConditionOfGearBox::First, ConditionOfGearBox::Second, true);
			CheckSetSpeed(ConditionOfGearBox::Second, 40, true);
			CheckSetGear(ConditionOfGearBox::Second, ConditionOfGearBox::Third, true);
			CheckSetSpeed(ConditionOfGearBox::Third, 50, true);
			CheckSetSpeed(ConditionOfGearBox::Third, 61, false);
			CheckSetSpeed(ConditionOfGearBox::Third, 29, false);
		}
		BOOST_AUTO_TEST_CASE(when_fourth)
		{
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::First, true);
			CheckSetSpeed(ConditionOfGearBox::First, 30, true);
			CheckSetGear(ConditionOfGearBox::First, ConditionOfGearBox::Second, true);
			CheckSetSpeed(ConditionOfGearBox::Second, 40, true);
			CheckSetGear(ConditionOfGearBox::Second, ConditionOfGearBox::Third, true);
			CheckSetSpeed(ConditionOfGearBox::Third, 60, true);
			CheckSetGear(ConditionOfGearBox::Third, ConditionOfGearBox::Fourth, true);
			CheckSetSpeed(ConditionOfGearBox::Fourth, 70, true);
			CheckSetSpeed(ConditionOfGearBox::Fourth, 91, false);
			CheckSetSpeed(ConditionOfGearBox::Fourth, 39, false);
		}
		BOOST_AUTO_TEST_CASE(when_fifth)
		{
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::First, true);
			CheckSetSpeed(ConditionOfGearBox::First, 30, true);
			CheckSetGear(ConditionOfGearBox::First, ConditionOfGearBox::Second, true);
			CheckSetSpeed(ConditionOfGearBox::Second, 40, true);
			CheckSetGear(ConditionOfGearBox::Second, ConditionOfGearBox::Third, true);
			CheckSetSpeed(ConditionOfGearBox::Third, 50, true);
			CheckSetGear(ConditionOfGearBox::Third, ConditionOfGearBox::Fourth, true);
			CheckSetSpeed(ConditionOfGearBox::Fourth, 60, true);
			CheckSetGear(ConditionOfGearBox::Fourth, ConditionOfGearBox::Fifth, true);
			CheckSetSpeed(ConditionOfGearBox::Fifth, 110, true);
			CheckSetSpeed(ConditionOfGearBox::Fifth, 151, false);
			CheckSetSpeed(ConditionOfGearBox::Fifth, 49, false);
		}
		BOOST_AUTO_TEST_CASE(when_forward)
		{
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::First, true);
			CheckSetSpeed(ConditionOfGearBox::First, 25, true);
			BOOST_CHECK(car.GetDirection() == Direction::Forward);
			CheckSetGear(ConditionOfGearBox::First, ConditionOfGearBox::Neutral, true);
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::Reverse, false);
		}
		BOOST_AUTO_TEST_CASE(when_reverse)
		{
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::Reverse, true);
			CheckSetSpeed(ConditionOfGearBox::Reverse, 10, true);
			CheckSetGear(ConditionOfGearBox::Reverse, ConditionOfGearBox::Neutral, true);
			BOOST_CHECK(car.GetDirection() == Direction::Reverse);
			//CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::First, false);
			CheckSetSpeed(ConditionOfGearBox::Neutral, 0, true);
			BOOST_CHECK(car.GetDirection() == Direction::Still);
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::First, true);
		}
		BOOST_AUTO_TEST_CASE(when_still)
		{
			BOOST_CHECK(car.TurnOffEngine());
		}
		BOOST_AUTO_TEST_CASE(when_driving)
		{
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::First, true);
			CheckSetSpeed(ConditionOfGearBox::First, 20, true);
			BOOST_CHECK(!car.TurnOffEngine());
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(when_car_is_turn_off)
		BOOST_AUTO_TEST_CASE(cannot_turn_off_if_already_had_turned_off)
		{
			BOOST_CHECK(!car.TurnOffEngine());
		}
		BOOST_AUTO_TEST_CASE(cannot_change_gear)
		{
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::Reverse, false);
			CheckSetGear(ConditionOfGearBox::Neutral, ConditionOfGearBox::First, false);
		}
		BOOST_AUTO_TEST_CASE(cannot_change_speed)
		{
			CheckSetSpeed(ConditionOfGearBox::Neutral, 50, false);
		}
		BOOST_AUTO_TEST_CASE(can_turn_on_car)
		{
			BOOST_CHECK(car.TurnOnEngine());
			BOOST_CHECK(car.GetCarCondition());
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
