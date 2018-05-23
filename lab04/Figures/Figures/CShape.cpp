#include "stdafx.h"
#include "CShape.h"

using namespace std;

CShape::CShape(const string& type, const string& color)
	: m_type(type)
	, m_color(color)
{
}

string CShape::ToString() const
{
	ostringstream strm;
	strm << m_type << ":" << endl
		 << setprecision(10)
		 << "\tarea = " << GetArea() << endl
		 << "\tperimeter = " << GetPerimeter() << endl
		 << "\tcolor = " << GetOutlineColor() << endl;
	AppendProperties(strm);
	return strm.str();
}

string CShape::GetOutlineColor() const
{
	return m_color;
}

CShape::~CShape()
{
}
