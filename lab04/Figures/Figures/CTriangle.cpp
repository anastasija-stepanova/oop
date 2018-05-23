#include "stdafx.h"
#include "CTriangle.h"
#include "CUtilites.h"
#include "Config.h"

using namespace std;

CTriangle::CTriangle(const CPoint& v1, const CPoint& v2, const CPoint& v3,
	const string& outlineColor, const string& fillColor)
	: CSolidShape("Triangle", outlineColor, fillColor)
{
	if (abs(v1.GetX() * (v2.GetY() - v3.GetY()) + v1.GetY() * (v2.GetX() - v3.GetX())
			+ (v2.GetX() * v3.GetY()) - (v2.GetY() * v3.GetX()))
		< ABSOLUTE_ZERO)
	{
		throw invalid_argument("Incorrect points, you can not create a triangle");
	}
	m_firstVertex = v1;
	m_secondVertex = v2;
	m_thirdVertex = v3;
}

CTriangle::~CTriangle()
{
}

double CTriangle::GetPerimeter() const
{
	return (m_firstVertex.GetDistanceToPoint(m_secondVertex)
		+ m_secondVertex.GetDistanceToPoint(m_thirdVertex)
		+ m_thirdVertex.GetDistanceToPoint(m_firstVertex));
}

double CTriangle::GetArea() const
{
	return abs(HALF_DIGIT_ONE * (m_firstVertex.GetX() * (m_secondVertex.GetY() - m_thirdVertex.GetY()) + m_secondVertex.GetX() * (m_thirdVertex.GetY() - m_firstVertex.GetY()) + m_thirdVertex.GetX() * (m_firstVertex.GetY() - m_secondVertex.GetY())));
}

CPoint CTriangle::GetVertexFirst() const
{
	return m_firstVertex;
}

CPoint CTriangle::GetVertexSecond() const
{
	return m_secondVertex;
}

CPoint CTriangle::GetVertexThird() const
{
	return m_thirdVertex;
}

void CTriangle::Draw(ICanvas& canvas) const
{
	vector<CPoint> points = {
		GetVertexFirst(),
		GetVertexSecond(),
		GetVertexThird()
	};

	canvas.FillPolygon(points, CUtilites::StringToUInt(GetFillColor()));

	uint32_t outlineColor = CUtilites::StringToUInt(GetOutlineColor());
	canvas.DrawLine(points[0], points[1], outlineColor);
	canvas.DrawLine(points[1], points[2], outlineColor);
	canvas.DrawLine(points[0], points[2], outlineColor);
}

void CTriangle::AppendProperties(ostream& strm) const
{
	strm << "\tfirst vertex = " << GetVertexFirst().ToString() << "\n"
		 << "\tsecond vertex = " << GetVertexSecond().ToString() << "\n"
		 << "\tthird vertex = " << GetVertexThird().ToString() << "\n";
}

bool CTriangle::OrientingAreaOfTriangleIsEqualZero(const CPoint& v1, const CPoint& v2, const CPoint& v3) const
{
	return (abs(v1.GetX() * (v2.GetY() - v3.GetY())
				+ v1.GetY() * (v2.GetX() - v3.GetX())
				+ (v2.GetX() * v3.GetY())
				- (v2.GetY() * v3.GetX()))
		< ABSOLUTE_ZERO);
}
