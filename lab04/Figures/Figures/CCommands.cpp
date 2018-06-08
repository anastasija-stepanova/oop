#include "stdafx.h"
#include "CCommands.h"

using namespace std;

namespace
{
	static const size_t COUNT_PARAMETERS_FOR_LINE_SEGMENT = 6;

	static const size_t COUNT_PARAMETERS_FOR_CIRCLE = 6;

	static const size_t COUNT_PARAMETERS_FOR_TRIANGLE = 9;

	static const size_t COUNT_PARAMETERS_FOR_RECTANGLE = 7;
}

CAddLineSegmentCommand::CAddLineSegmentCommand(vector<unique_ptr<IShape>>& shapes)
	: m_shapes(shapes)
{
}

void CAddLineSegmentCommand::Execute(const vector<string>& params)
{
	if (params.size() != COUNT_PARAMETERS_FOR_LINE_SEGMENT)
	{
		throw invalid_argument("Error: Invalid count argument for linesegment");
	}
	CPoint startPoint(stod(params[1]), stod(params[2]));
	CPoint endPoint(stod(params[3]), stod(params[4]));
	const auto outlineColor = params[4];

	m_shapes.push_back(make_unique<CLineSegment>(startPoint, endPoint, outlineColor));
}

CAddCircleCommand::CAddCircleCommand(vector<unique_ptr<IShape>>& shapes)
	: m_shapes(shapes)
{
}

void CAddCircleCommand::Execute(const vector<string>& params)
{
	if (params.size() != COUNT_PARAMETERS_FOR_CIRCLE)
	{
		throw invalid_argument("Error: Invalid count argument for circle");
	}
	const CPoint center(stod(params[1]), stod(params[2]));
	const auto radius = stod(params[3]);
	const auto outlineColor = params[4];
	const auto fillColor = params[5];

	m_shapes.push_back(make_unique<CCircle>(center, radius, outlineColor, fillColor));
}

CAddRectangleCommand::CAddRectangleCommand(vector<unique_ptr<IShape>>& shapes)
	: m_shapes(shapes)
{
}

void CAddRectangleCommand::Execute(const vector<string>& params)
{
	if (params.size() != COUNT_PARAMETERS_FOR_TRIANGLE)
	{
		throw invalid_argument("Error: Invalid count argument for triangle");
	}
	CPoint vertex1(stod(params[1]), stod(params[2]));
	CPoint vertex2(stod(params[3]), stod(params[4]));
	CPoint vertex3(stod(params[5]), stod(params[6]));
	const auto outlineColor = params[7];
	const auto fillColor = params[8];

	m_shapes.push_back(make_unique<CTriangle>(vertex1, vertex2, vertex3, outlineColor, fillColor));
}

CAddTriangleCommand::CAddTriangleCommand(vector<unique_ptr<IShape>>& shapes)
	: m_shapes(shapes)
{
}

void CAddTriangleCommand::Execute(const vector<string>& params)
{
	if (params.size() != COUNT_PARAMETERS_FOR_RECTANGLE)
	{
		throw invalid_argument("Error: Invalid count argument for rectangle");
	}
	CPoint leftTopVertex(stod(params[1]), stod(params[2]));
	const auto height = stod(params[3]);
	const auto width = stod(params[4]);
	const auto outlineColor = params[5];
	const auto fillColor = params[6];

	m_shapes.push_back(make_unique<CRectangle>(leftTopVertex, height, width, outlineColor, fillColor));
}

CPrintInfoCommand::CPrintInfoCommand(vector<unique_ptr<IShape>>& shapes)
	: m_shapes(shapes)
{
}

void CPrintInfoCommand::Execute(const vector<string>& params)
{
	(void)&params;
	if (m_shapes.empty())
	{
		cout << "Shapes is empty." << endl;
	}

	cout << "Info About Shapes:" << endl;
	for (auto& shape : m_shapes)
	{
		cout << shape->ToString() << endl;
	}
}

CPrintMinPerimeterCommand::CPrintMinPerimeterCommand(vector<unique_ptr<IShape>>& shapes)
	: m_shapes(shapes)
{
}

void CPrintMinPerimeterCommand::Execute(const vector<string>& params)
{
	(void)&params;
	if (!m_shapes.empty())
	{
		auto minPerimeter = min_element(m_shapes.begin(), m_shapes.end(), [](const auto& lhs, const auto& rhs) {
			return lhs->GetPerimeter() < rhs->GetPerimeter();
		});
		cout << "Min Perimeter: " << (*minPerimeter)->ToString() << endl;
	}
}

CPrintMaxAreaCommand::CPrintMaxAreaCommand(vector<unique_ptr<IShape>>& shapes)
	: m_shapes(shapes)
{
}

void CPrintMaxAreaCommand::Execute(const vector<string>& params)
{
	(void)&params;
	if (!m_shapes.empty())
	{
		auto maxArea = max_element(m_shapes.begin(), m_shapes.end(), [](const auto& lhs, const auto& rhs) {
			return lhs->GetArea() < rhs->GetArea();
		});
		cout << "Max Area: " << (*maxArea)->ToString() << endl;
	}
}