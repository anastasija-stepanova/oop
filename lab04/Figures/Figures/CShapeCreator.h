#pragma once
#include "CCanvas.h"
#include "CPoint.h"
#include "IShape.h"

class CShapeCreator
{
public:
	CShapeCreator(std::istream& input);
	~CShapeCreator();
	std::shared_ptr<IShape> HandleCommand() const;

private:
	std::map<std::string, std::function<std::shared_ptr<IShape>(std::istringstream& strm)>> m_actionMap;
	std::shared_ptr<IShape> CreateLine(std::istringstream& strm) const;
	std::shared_ptr<IShape> CreateTriangle(std::istringstream& strm) const;
	std::shared_ptr<IShape> CreateRectangle(std::istringstream& strm) const;
	std::shared_ptr<IShape> CreateCircle(std::istringstream& strm) const;

	std::istream& m_input;

	void AddOpacityToColor(std::string& color) const;
	static bool IsHexColor(const std::string& color);
	static CPoint GetPointFromInput(std::istringstream& strm);
	static bool IsValidColor(const std::string& color);
};
