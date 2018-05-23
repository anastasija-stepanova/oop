#include "stdafx.h"
#include "CLineSegment.h"
#include "CUtilites.h"
#include "Config.h"

using namespace std;

CLineSegment::CLineSegment(const CPoint& start, const CPoint& end, const string& color)
	: m_start(start)
	, m_end(end)
	, CShape("Line segment", color)
{
}

double CLineSegment::GetArea() const
{
	return ABSOLUTE_ZERO;
}

double CLineSegment::GetPerimeter() const
{
	return m_start.GetDistanceToPoint(m_end);
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_start;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_end;
}

void CLineSegment::Draw(ICanvas& canvas) const
{
	canvas.DrawLine(GetStartPoint(), GetEndPoint(), CUtilites::StringToUInt(GetOutlineColor()));
}

void CLineSegment::AppendProperties(ostream& strm) const
{
	strm << "\tstart = " << GetStartPoint().ToString() << endl
		 << "\tend = " << GetEndPoint().ToString() << endl;
}

CLineSegment::~CLineSegment()
{
}
