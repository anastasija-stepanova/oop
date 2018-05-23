#pragma once
#include "IShape.h"
#include <string>

class CShape : public virtual IShape
{
public:
	CShape(const std::string& type, const std::string& color);
	~CShape();
	double GetArea() const override = 0;
	double GetPerimeter() const override = 0;
	std::string ToString() const override;
	std::string GetOutlineColor() const override;

protected:
	virtual void AppendProperties(std::ostream& strm) const = 0;

private:
	std::string m_type;
	std::string m_color;
};
