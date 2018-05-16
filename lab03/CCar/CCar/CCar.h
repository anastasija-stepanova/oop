#pragma once
#include "stdafx.h"

using namespace std;

using Speed = pair<int, int>;

enum class ConditionOfGearBox
{
	Reverse = -1,
	Neutral = 0,
	First = 1,
	Second = 2,
	Third = 3,
	Fourth = 4,
	Fifth = 5
};

enum class Direction
{
	Reverse = -1,
	Still = 0,
	Forward = 1
};

class CCar
{
public:
	CCar();
	bool TurnOnEngine();
	bool TurnOffEngine();

	bool SetGear(ConditionOfGearBox const& gear);
	bool SetSpeed(int const speed);

	ConditionOfGearBox GetGear() const;
	int GetSpeed() const;

	bool GetCarCondition() const;

	Direction GetDirection() const;

private:
	bool m_carCondition;
	ConditionOfGearBox m_gear;
	int m_speed;

	static bool SpeedIsInRange(Speed const& range, int speed);
	Speed GetAllowableSpeed(ConditionOfGearBox const& gear) const;
};
