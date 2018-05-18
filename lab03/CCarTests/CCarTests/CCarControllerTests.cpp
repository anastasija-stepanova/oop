#include "stdafx.h"
#include "../../CCar/CCar/CCar.h"
#include "../../CCar/CCar/CCarController.h"

using namespace std;

struct CarControllerDependencies
{
	CCar car;
	stringstream input;
	stringstream output;
};

struct CarContollerFixture : CarControllerDependencies
{
	CCarController carControl;

	CarContollerFixture()
		: carControl(car, input, output)
	{
	}

	void VerifyCommandHandling(const string& command, const string& expectedOutput)
	{
		input = stringstream();
		output = stringstream();
		BOOST_CHECK(input << command);
		BOOST_CHECK(carControl.HandleCommand());
		BOOST_CHECK(input.eof());
		BOOST_CHECK_EQUAL(output.str(), expectedOutput);
	}
};

BOOST_FIXTURE_TEST_SUITE(Car_Controller, CarContollerFixture)
	BOOST_AUTO_TEST_CASE(get_info_by_default)
	{
		VerifyCommandHandling("Info", "Car is turned off\nDirection is still\nSpeed is 0\nCondition of gear box is 0\n");
	}
	BOOST_AUTO_TEST_CASE(turn_on_car)
	{
		VerifyCommandHandling("EngineOn", "Car has turned on\n");
	}

	struct when_car_turned_on_ : CarContollerFixture
	{
		when_car_turned_on_()
		{
			car.TurnOnEngine();
		}
	};
	BOOST_FIXTURE_TEST_SUITE(when_car_is_turn_on, when_car_turned_on_)
		BOOST_AUTO_TEST_CASE(cannot_turn_on_if_already_had_turned_on)
		{
			VerifyCommandHandling("EngineOn", "Car is already turned on\n");
		}
		BOOST_AUTO_TEST_CASE(from_neutral_to_first)
		{
			VerifyCommandHandling("SetGear 1", "Condition of gear box has changed\n");
		}
		BOOST_AUTO_TEST_CASE(from_reverse_to_first)
		{
			VerifyCommandHandling("SetGear -1", "Condition of gear box has changed\n");
			VerifyCommandHandling("SetGear 1", "Condition of gear box has changed\n");
		}
		BOOST_AUTO_TEST_CASE(from_first_to_reverse)
		{
			VerifyCommandHandling("SetGear 1", "Condition of gear box has changed\n");
			VerifyCommandHandling("SetGear -1", "Condition of gear box has changed\n");
		}
		BOOST_AUTO_TEST_CASE(when_neutral)
		{
			VerifyCommandHandling("SetSpeed 10", "Speed has not changed\n");
		}
		BOOST_AUTO_TEST_CASE(can_turn_off_car_when_car_is_standing_still)
		{
			VerifyCommandHandling("EngineOff", "Car has turned off\n");
		}
		BOOST_AUTO_TEST_CASE(cannot_turn_off_car_on_while_driving)
		{
			VerifyCommandHandling("SetGear -1", "Condition of gear box has changed\n");
			VerifyCommandHandling("SetSpeed 10", "Speed has changed\n");
			VerifyCommandHandling("Info", "Car is turned on\nDirection is reverse\nSpeed is 10\nCondition of gear box is -1\n");
			VerifyCommandHandling("EngineOff", "Car has not turned off\n");
		}
		BOOST_AUTO_TEST_CASE(cannot_switch_to_reverse_gear_when_speed_more_zero)
		{
			VerifyCommandHandling("SetGear -1", "Condition of gear box has changed\n");
			VerifyCommandHandling("SetSpeed 5", "Speed has changed\n");
			VerifyCommandHandling("Info", "Car is turned on\nDirection is reverse\nSpeed is 5\nCondition of gear box is -1\n");
			VerifyCommandHandling("SetGear 0", "Condition of gear box has changed\n");
			VerifyCommandHandling("SetGear -1", "Condition of gear box has not changed\n");
			VerifyCommandHandling("Info", "Car is turned on\nDirection is reverse\nSpeed is 5\nCondition of gear box is 0	\n");
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_SUITE(when_enigne_is_turn_off)
		BOOST_AUTO_TEST_CASE(cannot_turn_off_if_already_had_turned_off)
		{
			VerifyCommandHandling("EngineOff", "Car is already turned off\n");
		}
		BOOST_AUTO_TEST_CASE(cannot_change_gear)
		{
			VerifyCommandHandling("SetGear 1", "Car has not turned on\n");
		}
		BOOST_AUTO_TEST_CASE(cannot_change_speed)
		{
			VerifyCommandHandling("SetSpeed 10", "Car has not turned on\n");
		}
		BOOST_AUTO_TEST_CASE(can_turn_on_car)
		{
			VerifyCommandHandling("EngineOn", "Car has turned on\n");
		}

	BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE_END()
