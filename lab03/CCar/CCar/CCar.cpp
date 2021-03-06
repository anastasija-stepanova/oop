// CCar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CCar.h"

using namespace std;

static const map<Gear, SpeedRange> SpeedRangeOfGear = {
	{ Gear::First, { 0, 30 } },
	{ Gear::Second, { 20, 50 } },
	{ Gear::Third, { 30, 60 } },
	{ Gear::Fourth, { 40, 90 } },
	{ Gear::Fifth, { 50, 150 } },
	{ Gear::Neutral, { 0, 150 } },
	{ Gear::Reverse, { 0, 20 } },
};

CCar::CCar()
	: m_engineIsTurnedOn(false)
	, m_gear(Gear::Neutral)
	, m_speed(0)
{
}

static bool SpeedIsInRange(const SpeedRange & range, int speed)
{
	speed = abs(speed);
	return ((range.first <= speed) && (range.second >= speed));
}

static SpeedRange GetAllowedSpeed(const Gear gear)
{
	auto it = SpeedRangeOfGear.find(gear);
	return it->second;
}

static bool GearIsInRange(const Gear gear)
{
	if ((gear < Gear::Reverse) || (gear > Gear::Fifth))
	{
		return false;
	}
	return true;
}

static bool GearCanBeSwitchFromReverseToFirst(const Direction currentDirection, const Gear gear, const int speed, const Gear m_gear)
{
	if ((speed != 0) && (currentDirection != Direction::Forward) && (m_gear == Gear::Reverse) && (gear != Gear::Neutral))
	{
		return false;
	}
	return true;
}

static bool GearCanBeSwitchToReverse(const Gear gear, const int speed)
{
	if ((gear == Gear::Reverse) && (speed != 0))
	{
		return false;
	}
	return true;
}

static bool SpeedIsRangeOfGear(const Gear gear, const int speed)
{
	SpeedRange allowedSpeed = GetAllowedSpeed(gear);
	if (!SpeedIsInRange(allowedSpeed, abs(speed)))
	{
		return false;
	}
	return true;
}

static bool GearCanBeSwitchFromNeutralToFirst(const Gear gear, const int speed, const Direction currentDirection, const Gear m_gear)
{
	if ((speed != 0) && (currentDirection == Direction::Reverse) && (m_gear == Gear::Neutral) && (gear == Gear::First))
	{
		return false;
	}
	return true;
}

static bool GearIsNeutral(const Gear gear, const int speed, const int m_speed)
{
	if ((gear == Gear::Neutral) && (speed >= std::abs(m_speed)))
	{
		return false;
	}
	return true;
}

static bool SpeedSignCanBeChanged(const Gear gear, const int speed)
{
	if ((gear == Gear::Reverse) || (speed < 0))
	{
		return true;
	}
	return false;
}

static bool GearCanBeSwitch(const Gear gear, const int speed, const Direction currentDirection, const Gear m_gear)
{
	if (GearCanBeSwitchFromReverseToFirst(currentDirection, gear, speed, m_gear) &&
		GearCanBeSwitchFromNeutralToFirst(gear, speed, currentDirection, m_gear) &&
		GearCanBeSwitchToReverse(gear, speed))
	{
		return true;
	}
	return false;
}

bool CCar::TurnOnEngine()
{
	if (!m_engineIsTurnedOn)
	{
		m_engineIsTurnedOn = true;
		return true;
	}
	return false;
}

bool CCar::TurnOffEngine()
{
	if (m_engineIsTurnedOn && (m_speed == 0) && (m_gear == Gear::Neutral))
	{
		return true;
	}
	m_engineIsTurnedOn = false;
	return false;
}

bool CCar::SetGear(const Gear gear)
{
	const auto currentDirection = GetDirection();
	if (m_engineIsTurnedOn && 
		GearIsInRange(gear) && 
		SpeedIsRangeOfGear(gear, m_speed) && 
		GearCanBeSwitch(gear, m_speed, currentDirection, m_gear))
	{
		m_gear = gear;
		return true;
	}
	return false;
}

bool CCar::SetSpeed(const int speed)
{
	if (!SpeedIsRangeOfGear(m_gear, speed) || !GearIsNeutral(m_gear, speed, m_speed))
	{
		return false;
	}

	m_speed = SpeedSignCanBeChanged(m_gear, m_speed) ? -speed : speed;
	return true;
}

Gear CCar::GetGear() const
{
	return m_gear;
}

int CCar::GetSpeed() const
{
	return abs(m_speed);
}

bool CCar::EngineIsTurnOn() const
{
	return m_engineIsTurnedOn;
}

Direction CCar::GetDirection() const
{
	if (m_speed < 0)
	{
		return Direction::Reverse;
	}
	if (m_speed > 0)
	{
		return Direction::Forward;
	}
	return Direction::Still;
}