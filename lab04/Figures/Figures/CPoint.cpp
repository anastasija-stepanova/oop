#include "stdafx.h"
#include "CPoint.h"
#include "CUtilites.h"
#include "Config.h"

using namespace std;

CPoint::CPoint()
{
}

CPoint::CPoint(double x, double y)
	: m_x(x)
	, m_y(y)
{
}

double CPoint::GetX() const
{
	return m_x;
}

double CPoint::GetY() const
{
	return m_y;
}

string CPoint::ToString() const
{
	return "(" + CUtilites::DoubleToString(m_x) + ", " + CUtilites::DoubleToString(m_y) + ")";
}

double CPoint::GetDistanceToPoint(const CPoint& point) const
{
	return sqrt(pow((point.m_x - m_x), SECOND_DEGREE) + pow((point.m_y - m_y), SECOND_DEGREE));
}

void CPoint::SetXCoord(double x)
{
	m_x = x;
}

void CPoint::SetYCoord(double y)
{
	m_y = y;
}

CPoint::~CPoint()
{
}
