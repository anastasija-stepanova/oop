#include "stdafx.h"
#include "CSolidShape.h"

using namespace std;

CSolidShape::CSolidShape(const string& type, const string& outlineColor, const string& fillColor)
	: CShape(type, outlineColor)
	, m_fillColor(fillColor)
{
}

string CSolidShape::GetOutlineColor() const
{
	return CShape::GetOutlineColor();
}

string CSolidShape::ToString() const
{
	ostringstream strm;
	strm << "\tfill color = " << GetFillColor() << endl;
	return CShape::ToString() + strm.str();
}

string CSolidShape::GetFillColor() const
{
	return m_fillColor;
}

void CSolidShape::AppendProperties(ostream& strm) const
{
	strm << "\tfill color = #" << m_fillColor << endl;
}

CSolidShape::~CSolidShape()
{
}
