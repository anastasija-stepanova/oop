#include "stdafx.h"
#include "CShapeController.h"
#include <boost/algorithm/string.hpp>

namespace
{
	static const size_t COUNT_PARAMETERS_FOR_LINE_SEGMENT = 6;

	static const size_t COUNT_PARAMETERS_FOR_CIRCLE = 6;

	static const size_t COUNT_PARAMETERS_FOR_TRIANGLE = 9;

	static const size_t COUNT_PARAMETERS_FOR_RECTANGLE = 7;
}

CShapeController::CShapeController()
	:m_actionMap({
		{ "linesegment", std::bind(&CShapeController::AddLineSegment, this, std::placeholders::_1) },
		{ "circle", std::bind(&CShapeController::AddCircle, this, std::placeholders::_1) },
		{ "triangle", std::bind(&CShapeController::AddTriangle, this, std::placeholders::_1) },
		{ "rectangle", std::bind(&CShapeController::AddRectangle, this, std::placeholders::_1) },
		})
{
}

void CShapeController::HandleCommand(std::string command)
{
	boost::to_lower(command);
	std::vector<std::string> params;
	boost::split(params, command, boost::is_space());

	auto action = m_actionMap.find(params[0]);

	if (params[0] == "info")
	{
		PrintInfo();
		return;
	}

	if (action == m_actionMap.end())
	{
		throw std::invalid_argument("Error: Unknown command");
	}

	action->second(params);
}

void CShapeController::AddLineSegment(std::vector<std::string>& params)
{
	m_shapes.push_back(std::move(CreateLineSegment(params)));
}

void CShapeController::AddCircle(std::vector<std::string>& params)
{
	m_shapes.push_back(std::move(CreateCircle(params)));
}

void CShapeController::AddTriangle(std::vector<std::string>& params)
{
	m_shapes.push_back(std::move(CreateTriangle(params)));
}

void CShapeController::AddRectangle(std::vector<std::string>& params)
{
	m_shapes.push_back(std::move(CreateRectangle(params)));
}

std::unique_ptr<IShape> CShapeController::CreateLineSegment(std::vector<std::string>& params)
{
	if (params.size() != COUNT_PARAMETERS_FOR_LINE_SEGMENT)
	{
		throw std::invalid_argument("Error: Invalid count argument for linesegment");
	}
	CPoint startPoint(std::stod(params[1]), std::stod(params[2]));
	CPoint endPoint(std::stod(params[3]), std::stod(params[4]));
	const auto outlineColor = params[4];
	return std::make_unique<CLineSegment>(startPoint, endPoint, outlineColor);
}

std::unique_ptr<IShape> CShapeController::CreateCircle(std::vector<std::string>& params)
{
	if (params.size() != COUNT_PARAMETERS_FOR_CIRCLE)
	{
		throw std::invalid_argument("Error: Invalid count argument for circle");
	}
	const CPoint center(std::stod(params[1]), std::stod(params[2]));
	const auto radius = std::stod(params[3]);
	const auto outlineColor = params[4];
	const auto fillColor = params[5];
	return std::make_unique<CCircle>(center, radius, outlineColor, fillColor);
}

std::unique_ptr<IShape> CShapeController::CreateTriangle(std::vector<std::string>& params)
{
	if (params.size() != COUNT_PARAMETERS_FOR_TRIANGLE)
	{
		throw std::invalid_argument("Error: Invalid count argument for triangle");
	}
	CPoint vertex1(std::stod(params[1]), std::stod(params[2]));
	CPoint vertex2(std::stod(params[3]), std::stod(params[4]));
	CPoint vertex3(std::stod(params[5]), std::stod(params[6]));
	const auto outlineColor = params[7];
	const auto fillColor = params[8];
	return std::make_unique<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor);
}

std::unique_ptr<IShape> CShapeController::CreateRectangle(std::vector<std::string>& params)
{
	if (params.size() != COUNT_PARAMETERS_FOR_RECTANGLE)
	{
		throw std::invalid_argument("Error: Invalid count argument for rectangle");
	}
	CPoint leftTopVertex(std::stod(params[1]), std::stod(params[2]));
	const auto height = std::stod(params[3]);
	const auto width = std::stod(params[4]);
	const auto outlineColor = params[5];
	const auto fillColor = params[6];
	return std::make_unique<CRectangle>(leftTopVertex, height, width, outlineColor, fillColor);
}

void CShapeController::PrintInfo() const
{
	if (m_shapes.empty())
	{
		std::cout << "Shapes is empty." << std::endl;
	}

	std::cout << "Info About Shapes:" << std::endl;
	for (auto& shape : m_shapes)
	{
		std::cout << shape->ToString() << std::endl;
	}
}

void CShapeController::PrintMinPerimeter() const
{
	if (!m_shapes.empty())
	{
		auto minPerimeter = std::min_element(m_shapes.begin(), m_shapes.end(), [](const std::unique_ptr<IShape> & lhs, const std::unique_ptr<IShape> & rhs) {
			return lhs->GetPerimeter() < rhs->GetPerimeter();
		});
		std::cout << "Min Perimeter: " << (*minPerimeter)->ToString() << std::endl;
	}
}

void CShapeController::PrintMaxArea() const
{
	if (!m_shapes.empty())
	{
		auto maxArea = std::max_element(m_shapes.begin(), m_shapes.end(), [](const std::unique_ptr<IShape> & lhs, const std::unique_ptr<IShape> & rhs) {
			return lhs->GetArea() < rhs->GetArea();
		});
		std::cout << "Max Area: " << (*maxArea)->ToString() << std::endl;
	}
}