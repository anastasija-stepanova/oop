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