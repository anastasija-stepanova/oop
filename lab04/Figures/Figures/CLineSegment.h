#pragma once
#include "CPoint.h"
#include "CShape.h"
#include "ICanvas.h"

class CLineSegment : public CShape
{
public:
	CLineSegment(const CPoint& start, const CPoint& end, const std::string& color);
	double GetArea() const override;
	double GetPerimeter() const override;
	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;
	void Draw(ICanvas& canvas) const override;
	~CLineSegment();

protected:
	void AppendProperties(std::ostream& strm) const override;

private:
	CPoint m_start;
	CPoint m_end;
};
