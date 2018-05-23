#pragma once
#include "CShape.h"
#include "ISolidShape.h"

class CSolidShape : public CShape
	, public ISolidShape
{
public:
	CSolidShape(const std::string& type, const std::string& outlineColor, const std::string& fillColor);
	double GetArea() const override = 0;
	double GetPerimeter() const override = 0;
	std::string GetOutlineColor() const override;
	std::string ToString() const override;
	std::string GetFillColor() const;
	~CSolidShape();

protected:
	void AppendProperties(std::ostream& strm) const;

private:
	std::string m_fillColor;
};
