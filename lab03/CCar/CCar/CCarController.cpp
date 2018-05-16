#include "stdafx.h"
#include "CCarController.h"

using namespace std;
using namespace std::placeholders;

CCarController::CCarController(CCar & car, istream & const input, ostream & const output)
	: m_car(car)
	, m_input(input)
	, m_output(output)
	, m_actionMap({
		{ "Info", bind(&CCarController::Info, this, _1) },
		{ "EngineOn", bind(&CCarController::EngineOn, this, _1) },
		{ "EngineOff", bind(&CCarController::EngineOff, this, _1) },
		{ "SetGear", bind(&CCarController::SetGear, this, _1) },
		{ "SetSpeed", bind(&CCarController::SetSpeed, this, _1) }
	})
{
}

bool CCarController::HandleCommand()
{
	std::string commandLine;
	std::getline(m_input, commandLine);
	std::istringstream strstream(commandLine);
	std::string action;
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
	string carCondition = m_car.GetCarCondition() ? "on" : "off";

	m_output << "Car is turned " + carCondition << endl;
	m_output << "Direction is " << static_cast<int>(m_car.GetDirection()) << endl;
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
		m_output << "Car had turned on" << endl;
	}
}

void CCarController::EngineOff(istream& input)
{
	if ((m_car.GetGear() != ConditionOfGearBox::Neutral) ||( m_car.GetSpeed() != 0))
	{
		m_output << "Car had not turned off" << endl;
	}
	else if (m_car.TurnOffEngine())
	{
		m_output << "Car had turned off" << endl;
	}
	else if (!m_car.TurnOffEngine())
	{
		m_output << "Car is already turned off" << endl;
	}
}

void CCarController::SetGear(istream& input)
{
	if (!m_car.GetCarCondition())
	{
		m_output << "Car had not turned on" << endl;
		return;
	}
	int gear;
	input >> gear;
	if (!m_car.SetGear(static_cast<ConditionOfGearBox>(gear)))
	{
		m_output << "Condition of gear box had not changed" << endl;
		return;
	}
	m_output << "Condition of gear box had changed" << endl;
}

void CCarController::SetSpeed(istream& input)
{
	if (!m_car.GetCarCondition())
	{
		m_output << "Car had not turned on" << endl;
		return;
	}
	int speed;
	input >> speed;
	if (!m_car.SetSpeed(speed))
	{
		m_output << "Speed had not changed" << endl;
		return;
	}
	m_output << "Speed had changed" << endl;
}