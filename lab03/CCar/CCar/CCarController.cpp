#include "stdafx.h"
#include "CCarController.h"

using namespace std;
using namespace std::placeholders;

static const map<Direction, string> DIRECTION = {
	{ Direction::Reverse, "reverse" },
	{ Direction::Still, "still" },
	{ Direction::Forward, "forward" }
};

CCarController::CCarController(CCar& car, istream& input, ostream& output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({ { "Info", bind(&CCarController::Info, this, _1) },
		  { "EngineOn", bind(&CCarController::EngineOn, this, _1) },
		  { "EngineOff", bind(&CCarController::EngineOff, this, _1) },
		  { "SetGear", bind(&CCarController::SetGear, this, _1) },
		  { "SetSpeed", bind(&CCarController::SetSpeed, this, _1) } })
{
}

bool CCarController::HandleCommand()
{
	string commandLine;
	getline(m_input, commandLine);
	istringstream strstream(commandLine);
	string action;
	strstream >> action;

	auto it = m_actionMap.find(action);
	if (it != m_actionMap.end())
	{
		it->second(strstream);
		return true;
	}
	return false;
}

void CCarController::Info(istream& input)
{
	string carCondition = m_car.EngineIsTurnOn() ? "on" : "off";

	m_output << "Car is turned " + carCondition << endl;
	m_output << "Direction is " << (DIRECTION.at(m_car.GetDirection())) << endl;
	m_output << "Speed is " << m_car.GetSpeed() << endl;
	m_output << "Condition of gear box is " << static_cast<int>(m_car.GetGear()) << endl;
}

void CCarController::EngineOn(istream& input)
{
	if (!m_car.TurnOnEngine())
	{
		m_output << "Car is already turned on" << endl;
	}
	else
	{
		m_output << "Car has been turned on" << endl;
	}
}

void CCarController::EngineOff(istream& input)
{
	if ((m_car.GetGear() != Gear::Neutral) || (m_car.GetSpeed() != 0))
	{
		m_output << "Car has not been turned off" << endl;
	}
	else if (m_car.TurnOffEngine())
	{
		m_output << "Car has been turned off" << endl;
	}
	else if (!m_car.TurnOffEngine())
	{
		m_output << "Car is already turned off" << endl;
	}
}

void CCarController::SetGear(istream& input)
{
	if (!m_car.EngineIsTurnOn())
	{
		m_output << "Car has not been turned on" << endl;
		return;
	}
	int gear;
	input >> gear;
	if (!m_car.SetGear(static_cast<Gear>(gear)))
	{
		m_output << "Condition of gear box has not been changed" << endl;
		return;
	}
	m_output << "Condition of gear box has been changed" << endl;
}

void CCarController::SetSpeed(istream& input)
{
	if (!m_car.EngineIsTurnOn())
	{
		m_output << "Car has not been turned on" << endl;
		return;
	}
	int speed;
	input >> speed;
	if (!m_car.SetSpeed(speed))
	{
		m_output << "Speed has not been changed" << endl;
		return;
	}
	m_output << "Speed has been changed" << endl;
}
