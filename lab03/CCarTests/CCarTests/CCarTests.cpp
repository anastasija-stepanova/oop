// CCarTests.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../CCar/CCar/CCar.h"

struct CarFixture
{
	CCar car;

	void CheckSetSpeed(Gear gear, int speed, bool result)
	{
		BOOST_CHECK(car.GetGear() == gear);
		BOOST_CHECK(car.SetSpeed(speed) == result);
	}

	void CheckSetGear(Gear gear, Gear newGear, bool result)
	{
		BOOST_CHECK(car.GetGear() == gear);
		BOOST_CHECK(car.SetGear(newGear) == result);
	}
};

BOOST_FIXTURE_TEST_SUITE(Car, CarFixture)
	BOOST_AUTO_TEST_CASE(is_turned_off_by_default)
	{
		BOOST_CHECK(!car.EngineIsTurnOn());
	}
	BOOST_AUTO_TEST_CASE(is_zero_by_default)
	{
		BOOST_CHECK_EQUAL(car.GetSpeed(), 0);
	}
	BOOST_AUTO_TEST_CASE(is_neutral_by_default)
	{
		BOOST_CHECK(car.GetGear() == Gear::Neutral);
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
			CheckSetGear(Gear::Neutral, Gear::First, true);
		}
		BOOST_AUTO_TEST_CASE(from_first_to_reverse)
		{
			CheckSetGear(Gear::Neutral, Gear::First, true);
			CheckSetGear(Gear::First, Gear::Reverse, true);
		}
		BOOST_AUTO_TEST_CASE(from_neutral_to_reverse)
		{
			CheckSetGear(Gear::Neutral, Gear::Reverse, true);
		}
		BOOST_AUTO_TEST_CASE(from_reverse_to_first)
		{
			CheckSetGear(Gear::Neutral, Gear::Reverse, true);
			CheckSetGear(Gear::Reverse, Gear::First, true);
		}
		BOOST_AUTO_TEST_CASE(when_neutral_speed_is_only_zero)
		{
			CheckSetSpeed(Gear::Neutral, 50, false);
		}
		BOOST_AUTO_TEST_CASE(when_first)
		{
			CheckSetGear(Gear::Neutral, Gear::First, true);
			CheckSetSpeed(Gear::First, 30, true);
			CheckSetSpeed(Gear::First, 150, false);
		}
		BOOST_AUTO_TEST_CASE(when_second)
		{
			CheckSetGear(Gear::Neutral, Gear::First, true);
			CheckSetSpeed(Gear::First, 30, true);
			CheckSetGear(Gear::First, Gear::Second, true);
			CheckSetSpeed(Gear::Second, 40, true);
			CheckSetSpeed(Gear::Second, 51, false);
			CheckSetSpeed(Gear::Second, 19, false);
		}
		BOOST_AUTO_TEST_CASE(when_third)
		{
			CheckSetGear(Gear::Neutral, Gear::First, true);
			CheckSetSpeed(Gear::First, 30, true);
			CheckSetGear(Gear::First, Gear::Second, true);
			CheckSetSpeed(Gear::Second, 40, true);
			CheckSetGear(Gear::Second, Gear::Third, true);
			CheckSetSpeed(Gear::Third, 50, true);
			CheckSetSpeed(Gear::Third, 61, false);
			CheckSetSpeed(Gear::Third, 29, false);
		}
		BOOST_AUTO_TEST_CASE(when_fourth)
		{
			CheckSetGear(Gear::Neutral, Gear::First, true);
			CheckSetSpeed(Gear::First, 30, true);
			CheckSetGear(Gear::First, Gear::Second, true);
			CheckSetSpeed(Gear::Second, 40, true);
			CheckSetGear(Gear::Second, Gear::Third, true);
			CheckSetSpeed(Gear::Third, 60, true);
			CheckSetGear(Gear::Third, Gear::Fourth, true);
			CheckSetSpeed(Gear::Fourth, 70, true);
			CheckSetSpeed(Gear::Fourth, 91, false);
			CheckSetSpeed(Gear::Fourth, 39, false);
		}
		BOOST_AUTO_TEST_CASE(when_fifth)
		{
			CheckSetGear(Gear::Neutral, Gear::First, true);
			CheckSetSpeed(Gear::First, 30, true);
			CheckSetGear(Gear::First, Gear::Second, true);
			CheckSetSpeed(Gear::Second, 40, true);
			CheckSetGear(Gear::Second, Gear::Third, true);
			CheckSetSpeed(Gear::Third, 50, true);
			CheckSetGear(Gear::Third, Gear::Fourth, true);
			CheckSetSpeed(Gear::Fourth, 60, true);
			CheckSetGear(Gear::Fourth, Gear::Fifth, true);
			CheckSetSpeed(Gear::Fifth, 110, true);
			CheckSetSpeed(Gear::Fifth, 151, false);
			CheckSetSpeed(Gear::Fifth, 49, false);
		}
		BOOST_AUTO_TEST_CASE(when_forward)
		{
			CheckSetGear(Gear::Neutral, Gear::First, true);
			CheckSetSpeed(Gear::First, 25, true);
			BOOST_CHECK(car.GetDirection() == Direction::Forward);
			CheckSetGear(Gear::First, Gear::Neutral, true);
			CheckSetGear(Gear::Neutral, Gear::Reverse, false);
		}
		BOOST_AUTO_TEST_CASE(when_reverse)
		{
			CheckSetGear(Gear::Neutral, Gear::Reverse, true);
			CheckSetSpeed(Gear::Reverse, 10, true);
			CheckSetGear(Gear::Reverse, Gear::Neutral, true);
			BOOST_CHECK(car.GetDirection() == Direction::Reverse);
			CheckSetGear(Gear::Neutral, Gear::First, false);
			CheckSetSpeed(Gear::Neutral, 0, true);
			BOOST_CHECK(car.GetDirection() == Direction::Still);
			CheckSetGear(Gear::Neutral, Gear::First, true);
		}
		BOOST_AUTO_TEST_CASE(when_still)
		{
			BOOST_CHECK(car.TurnOffEngine());
		}
		BOOST_AUTO_TEST_CASE(when_driving)
		{
			CheckSetGear(Gear::Neutral, Gear::First, true);
			CheckSetSpeed(Gear::First, 20, true);
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
			CheckSetGear(Gear::Neutral, Gear::Reverse, false);
			CheckSetGear(Gear::Neutral, Gear::First, false);
		}
		BOOST_AUTO_TEST_CASE(cannot_change_speed)
		{
			CheckSetSpeed(Gear::Neutral, 50, false);
		}
		BOOST_AUTO_TEST_CASE(can_turn_on_car)
		{
			BOOST_CHECK(car.TurnOnEngine());
			BOOST_CHECK(car.EngineIsTurnOn());
		}
	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
