#pragma once
#include "CPoint.h"
#include "CSolidShape.h"
#include "ICanvas.h"

class CTriangle : public CSolidShape
{
public:
	CTriangle(const CPoint& v1, const CPoint& v2, const CPoint& v3,
		const std::string& outlineColor, const std::string& fillColor);
	~CTriangle();
	double GetArea() const override;
	double GetPerimeter() const override;
	CPoint GetVertexFirst() const;
	CPoint GetVertexSecond() const;
	CPoint GetVertexThird() const;
	void Draw(ICanvas& canvas) const override;

protected:
	void AppendProperties(std::ostream& strm) const;

private:
	CPoint m_firstVertex;
	CPoint m_secondVertex;
	CPoint m_thirdVertex;
	bool OrientingAreaOfTriangleIsEqualZero(const CPoint& v1, const CPoint& v2, const CPoint& v3) const;
};
