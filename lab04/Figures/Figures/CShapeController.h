#pragma once
#include <memory>
#include <map>
#include <vector>
#include <algorithm>
#include <functional>
#include <iostream>
#include <fstream>
#include "CPoint.h"
#include "IShape.h"
#include "CLineSegment.h"
#include "CRectangle.h"
#include "CTriangle.h"
#include "CCircle.h"

using ActionMap = std::map<std::string, std::function<void(std::vector<std::string>&)>>;

class CShapeController
{
public:
	CShapeController();
	~CShapeController() = default;
	void HandleCommand(std::string command);
	void PrintInfo() const;
	void PrintMinPerimeter() const;
	void PrintMaxArea() const;

private:
	void AddLineSegment(std::vector<std::string> & params);
	void AddCircle(std::vector<std::string> & params);
	void AddTriangle(std::vector<std::string> & params);
	void AddRectangle(std::vector<std::string> & params);

	std::unique_ptr<IShape> CreateLineSegment(std::vector<std::string> & params);
	std::unique_ptr<IShape> CreateCircle(std::vector<std::string> & params);
	std::unique_ptr<IShape> CreateTriangle(std::vector<std::string> & params);
	std::unique_ptr<IShape> CreateRectangle(std::vector<std::string> & params);

	ActionMap m_actionMap;
	std::vector<std::unique_ptr<IShape>> m_shapes;
};