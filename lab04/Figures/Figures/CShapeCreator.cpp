#include "stdafx.h"
#include "CShapeCreator.h"
#include <boost/algorithm/string.hpp>
#include <boost/range/algorithm/find_if.hpp>

using namespace std;

CShapeCreator::CShapeCreator()
{
	AddItem("line segment", make_unique<CAddLineSegmentCommand>(m_shapes));
	AddItem("cicrle", make_unique<CAddCircleCommand>(m_shapes));
	AddItem("rectangle", make_unique<CAddRectangleCommand>(m_shapes));
	AddItem("triangle", make_unique<CAddTriangleCommand>(m_shapes));
	AddItem("info", make_unique<CPrintInfoCommand>(m_shapes));
	AddItem("min perimeter", make_unique<CPrintMinPerimeterCommand>(m_shapes));
	AddItem("max area", make_unique<CPrintMaxAreaCommand>(m_shapes));
}

void CShapeCreator::Run(istream& stream)
{
	string command;
	while (getline(stream, command))
	{
		boost::to_lower(command);
		vector<string> params;
		boost::split(params, command, boost::is_space());

		auto action = boost::find_if(m_actionMap, [&](const Item& item) {
			return item.shortcut == params[0];
		});

		if (action == boost::end(m_actionMap))
		{
			throw invalid_argument("Error: Unknown command");
		}
		action->command->Execute(params);

		auto minPerimeter = boost::find_if(m_actionMap, [&](const Item& item) {
			return item.shortcut == "min perimeter";
		});
		minPerimeter->command->Execute(params);

		auto maxArea = boost::find_if(m_actionMap, [&](const Item& item) {
			return item.shortcut == "max area";
		});
		maxArea->command->Execute(params);
	}
}
