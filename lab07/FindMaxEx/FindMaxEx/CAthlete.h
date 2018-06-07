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

class CBadAthlete
{
public:
	CBadAthlete(std::string const & name = "Vasya", double height = 1, double weight = 1, bool throwExc = false);
	friend bool operator==(const CBadAthlete& lhs, const CBadAthlete& rhs);
	friend bool operator<(const CBadAthlete& lhs, const CBadAthlete& rhs);
	CBadAthlete& operator=(const CBadAthlete& param);

	std::string m_name;
	double m_height;
	double m_weight;
	bool m_throwExc = false;
};