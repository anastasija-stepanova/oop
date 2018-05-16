// CCar.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CCar.h"

using namespace std;

static const map<ConditionOfGearBox, Speed> SpeedRange = {
	{ ConditionOfGearBox::First, { 0, 30 } },
	{ ConditionOfGearBox::Second, { 20, 50 } },
	{ ConditionOfGearBox::Third, { 30, 60 } },
	{ ConditionOfGearBox::Fourth, { 40, 90 } },
	{ ConditionOfGearBox::Fifth, { 50, 150 } },
	{ ConditionOfGearBox::Neutral, { 0, 150 } },
	{ ConditionOfGearBox::Reverse, { 0, 20 } },
};

CCar::CCar()
	: m_carCondition(false)
	, m_gear(ConditionOfGearBox::Neutral)
	, m_speed(0)
{
}

bool CCar::TurnOnEngine()
{
	if (!m_carCondition)
	{
		m_carCondition = true;
		return true;
	}
	return false;
}

bool CCar::TurnOffEngine()
{
	if (m_carCondition && (m_speed == 0) && (m_gear == ConditionOfGearBox::Neutral))
	{
		return true;
	}
	m_carCondition = false;
	return false;
}

bool CCar::SetGear(ConditionOfGearBox const& gear)
{
	if (!m_carCondition)
	{
		return false;
	}
	if ((gear < ConditionOfGearBox::Reverse) || (gear > ConditionOfGearBox::Fifth))
	{
		return false;
	}
	const auto currentDirection = GetDirection();
	if ((m_speed != 0) && (currentDirection != Direction::Reverse) && (gear == ConditionOfGearBox::Reverse))
	{
		return false;
	}
	if ((m_speed != 0) && (currentDirection != Direction::Forward) && (m_gear == ConditionOfGearBox::Reverse) && (gear == ConditionOfGearBox::First))
	{
		return false;
	}
	Speed allowableSpeed = GetAllowableSpeed(gear);
	if (!SpeedIsInRange(allowableSpeed, m_speed))
	{
		return false;
	}

	m_gear = gear;
	return true;
}

bool CCar::SetSpeed(int const speed)
{
	if (m_gear == ConditionOfGearBox::Neutral && speed >= std::abs(m_speed))
	{
		return false;
	}
	Speed const allowableSpeed = GetAllowableSpeed(m_gear);
	if (!SpeedIsInRange(allowableSpeed, abs(speed)))
	{
		return false;
	}

	bool speedCanChange = (m_gear == ConditionOfGearBox::Reverse) || (m_speed < 0);
	m_speed = speedCanChange ? -speed : speed;
	return true;
}

ConditionOfGearBox CCar::GetGear() const
{
	return m_gear;
}

int CCar::GetSpeed() const
{
	return abs(m_speed);
}

bool CCar::GetCarCondition() const
{
	return m_carCondition;
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

bool CCar::SpeedIsInRange(Speed const& range, int speed)
{
	speed = abs(speed);
	return ((range.first <= speed) && (range.second >= speed));
}

Speed CCar::GetAllowableSpeed(ConditionOfGearBox const& gear) const
{
	auto it = SpeedRange.find(gear);
	return it->second;
}
