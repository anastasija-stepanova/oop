#pragma once
#include "CPoint.h"
#include "CSolidShape.h"
#include "ICanvas.h"

class CRectangle : public CSolidShape
{
public:
	CRectangle(const CPoint& leftTop,
		double width, double height,
		const std::string& outlineColor,
		const std::string& fillColor);
	~CRectangle();
	double GetArea() const override;
	double GetPerimeter() const override;
	CPoint GetLeftTop() const;
	CPoint GetRightTop() const;
	CPoint GetLeftBottom() const;
	CPoint GetRightBottom() const;
	double GetWidth() const;
	double GetHeight() const;
	void Draw(ICanvas& canvas) const override;

protected:
	void AppendProperties(std::ostream& strm) const override;

private:
	double m_width = 0;
	double m_height = 0;
	CPoint m_leftTop;
};
