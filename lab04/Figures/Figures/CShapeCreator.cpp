#include "stdafx.h"
#include "CShapeCreator.h"
#include "CCircle.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "Config.h"

using namespace std;

CShapeCreator::CShapeCreator(istream& input)
	: m_input(input)
	, m_actionMap({ { "Line", bind(&CShapeCreator::CreateLine, this, std::placeholders::_1) },
		  { "Triangle", bind(&CShapeCreator::CreateTriangle, this, std::placeholders::_1) },
		  { "Rectangle", bind(&CShapeCreator::CreateRectangle, this, std::placeholders::_1) },
		  { "Circle", bind(&CShapeCreator::CreateCircle, this, std::placeholders::_1) } })
{
}

CShapeCreator::~CShapeCreator()
{
}

shared_ptr<IShape> CShapeCreator::HandleCommand() const
{
	string command;
	if (!getline(m_input, command))
	{
		return {};
	}
	transform(command.begin(), command.end(), command.begin(), tolower);
	istringstream strm(command);
	string figure;
	strm >> figure;

	auto it = m_actionMap.find(figure);
	if (it != m_actionMap.end())
	{
		return it->second(strm);
	}
	throw invalid_argument("Unknown command");
}

shared_ptr<IShape> CShapeCreator::CreateLine(istringstream& strm) const
{
	CPoint start = GetPointFromInput(strm);
	CPoint end = GetPointFromInput(strm);
	string color;
	strm >> color;
	AddOpacityToColor(color);
	if (!IsValidColor(color))
	{
		throw invalid_argument("Invalid color");
	}
	AddOpacityToColor(color);
	return make_shared<CLineSegment>(start, end, color);
}

shared_ptr<IShape> CShapeCreator::CreateTriangle(istringstream& strm) const
{
	CPoint v1 = GetPointFromInput(strm);
	CPoint v2 = GetPointFromInput(strm);
	CPoint v3 = GetPointFromInput(strm);
	string outlineColor;
	string fillColor;
	strm >> outlineColor >> fillColor;
	if (!IsValidColor(outlineColor) || !IsValidColor(fillColor))
	{
		throw invalid_argument("Invalid color");
	}
	AddOpacityToColor(outlineColor);
	AddOpacityToColor(fillColor);
	return make_shared<CTriangle>(v1, v2, v3, outlineColor, fillColor);
}

shared_ptr<IShape> CShapeCreator::CreateRectangle(istringstream& strm) const
{
	CPoint leftTop = GetPointFromInput(strm);
	double width;
	double height;
	strm >> width >> height;
	string outlineColor;
	string fillColor;
	strm >> outlineColor >> fillColor;
	if (!IsValidColor(outlineColor) || !IsValidColor(fillColor))
	{
		throw invalid_argument("Invalid color");
	}
	AddOpacityToColor(outlineColor);
	AddOpacityToColor(fillColor);
	return make_shared<CRectangle>(leftTop, width, height, outlineColor, fillColor);
}

shared_ptr<IShape> CShapeCreator::CreateCircle(istringstream& strm) const
{
	CPoint center = GetPointFromInput(strm);
	double radius;
	strm >> radius;
	string outlineColor;
	string fillColor;
	strm >> outlineColor >> fillColor;
	if (!IsValidColor(outlineColor) || !IsValidColor(fillColor))
	{
		throw invalid_argument("Invalid color");
	}
	AddOpacityToColor(outlineColor);
	AddOpacityToColor(fillColor);
	return make_shared<CCircle>(center, radius, outlineColor, fillColor);
}

void CShapeCreator::AddOpacityToColor(string& color) const
{
	if (color.size() == VALID_COLOR_SIZE)
	{
		color += FULL_OPACITY;
	}
}

bool CShapeCreator::IsHexColor(const string& color)
{
	char ch = ' ';
	for (size_t i = 0; i < color.size(); ++i)
	{
		ch = color[i];
		if (!(ch >= '0' && ch <= '9') && !(ch >= 'a' && ch <= 'f'))
		{
			return false;
		}
	}
	return true;
}

CPoint CShapeCreator::GetPointFromInput(istringstream& strm)
{
	double x;
	double y;
	strm >> x >> y;
	CPoint point(x, y);
	return point;
}

bool CShapeCreator::IsValidColor(const string& color)
{
	return (((color.size() == VALID_COLOR_SIZE)
				|| (color.size() == VALID_COLOR_SIZE_WITH_OPACITY))
		&& IsHexColor(color));
}
