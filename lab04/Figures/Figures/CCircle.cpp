#include "stdafx.h"
#include "CCircle.h"
#include "CUtilites.h"
#include "Config.h"

using namespace std;

CCircle::CCircle(const CPoint& center, double radius, const string& outlineColor, const string& fillColor)
	: m_radius(radius)
	, m_center(center)
	, CSolidShape("Circle", outlineColor, fillColor)
{
	if (radius <= ABSOLUTE_ZERO)
	{
		throw invalid_argument("The radius can not be less than or equal to zero");
	}
}

CCircle::~CCircle()
{
}

double CCircle::GetArea() const
{
	return M_PI * pow(m_radius, SECOND_DEGREE);
}

double CCircle::GetPerimeter() const
{
	return M_PI * m_radius;
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

void CCircle::Draw(ICanvas& canvas) const
{
	canvas.FillCircle(m_center, m_radius, CUtilites::StringToUInt(GetFillColor()));
	canvas.DrawCircle(GetCenter(), GetRadius(), CUtilites::StringToUInt(GetOutlineColor()));
}

void CCircle::AppendProperties(ostream& strm) const
{
	strm << "\tcenter = " << GetCenter().ToString() << "\n"
		 << "\tradius = " << GetRadius() << "\n";
}
