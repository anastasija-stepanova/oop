#pragma once

class CPoint
{
public:
	CPoint();
	~CPoint();
	CPoint(double x, double y);
	double GetX() const;
	double GetY() const;
	std::string ToString() const;
	double GetDistanceToPoint(const CPoint& point) const;
	void SetXCoord(double x);
	void SetYCoord(double y);

private:
	double m_x;
	double m_y;
};
