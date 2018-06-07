#include "stdafx.h"
#include "CAthlete.h"

using namespace std;

CAthlete::CAthlete(string const & name, double height, double weight)
	: m_name(name)
	, m_height(height)
	, m_weight(weight)
{
}

string CAthlete::GetName() const
{
	return m_name;
}

double CAthlete::GetWeight() const
{
	return m_weight;
}

double CAthlete::GetHeight() const
{
	return m_height;
}

void CAthlete::GetAthleteInfo(const CAthlete & athlete)
{
	cout << athlete.GetName() << ' ' << athlete.GetWeight() << ' ' << athlete.GetHeight() << endl;
}



CBadAthlete::CBadAthlete(std::string const & name, double height, double weight, bool throwExc)
	:m_name(name)
	, m_height(height)
	, m_weight(weight)
	, m_throwExc(throwExc)
{
}

CBadAthlete & CBadAthlete::operator=(const CBadAthlete & param)
{
	throw runtime_error("Error");
}

bool operator==(const CBadAthlete & lhs, const CBadAthlete & rhs)
{
	return lhs.m_height == rhs.m_height
		&& lhs.m_name == rhs.m_name
		&& lhs.m_weight == rhs.m_weight;
}

bool operator<(const CBadAthlete & lhs, const CBadAthlete & rhs)
{
	if (lhs.m_throwExc || rhs.m_throwExc)
	{
		throw runtime_error("Error");
	}

	return lhs.m_height < rhs.m_height;
}