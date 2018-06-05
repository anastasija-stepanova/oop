#pragma once

#include <string>

class CAthlete
{
public:
	CAthlete() = default;
	CAthlete(std::string const& name, double height, double weight);

	std::string GetName() const;
	double GetWeight() const;
	double GetHeight() const;
	void GetAthleteInfo(const CAthlete & athlete);
private:
	std::string m_name;
	double m_height;
	double m_weight;
};