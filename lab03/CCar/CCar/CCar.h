#pragma once
#include <map>

using SpeedRange = std::pair<int, int>;

enum class Gear
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

	bool SetGear(const Gear gear);
	bool SetSpeed(const int speed);

	Gear GetGear() const;
	int GetSpeed() const;

	bool EngineIsTurnOn() const;

	Direction GetDirection() const;

private:
	bool m_engineIsTurnedOn;
	Gear m_gear;
	int m_speed;
};
