#include "stdafx.h"
#include "../../Figures/Figures/CShapeCreator.h"
#include <sstream>

using namespace std;

struct CShapeCreatorFixture_
{
	CShapeCreator creator;
	vector<unique_ptr<IShape>> shape;
};

BOOST_FIXTURE_TEST_SUITE(ShapeCreator, CShapeCreatorFixture_)
	BOOST_AUTO_TEST_SUITE(Commands)
		BOOST_AUTO_TEST_CASE(run_add_line_segment)
		{
			CAddLineSegmentCommand command(shape);
			vector<string> params({ "line segment", "12", "45", "12" });
			BOOST_CHECK_THROW(command.Execute(params), invalid_argument);
			BOOST_CHECK(shape.empty());
		}
		BOOST_AUTO_TEST_CASE(run_add_cicrle)
		{
			CAddCircleCommand command(shape);
			vector<string> params{ "circle", "12", "123", "123" "451231", "12312" };
			BOOST_CHECK_THROW(command.Execute(params), invalid_argument);
		}
	BOOST_AUTO_TEST_SUITE_END()

	BOOST_AUTO_TEST_CASE(handle_an_unknown_command)
	{
		stringstream command("show all figure");
		BOOST_CHECK_THROW(creator.Run(command), invalid_argument);
	}
	BOOST_AUTO_TEST_CASE(add_linesegment_with_invalid_count_parameter)
	{
		stringstream command("linesegment 12 45 12");
		BOOST_CHECK_THROW(creator.Run(command), invalid_argument);
	}
	BOOST_AUTO_TEST_CASE(add_circle_with_invalid_count_parameter)
	{
		stringstream command("circle 12 45");
		BOOST_CHECK_THROW(creator.Run(command), invalid_argument);
	}
	BOOST_AUTO_TEST_CASE(add_rectangle_with_invalid_count_parameter)
	{
		stringstream command("rectangle 12 45");
		BOOST_CHECK_THROW(creator.Run(command), invalid_argument);
	}
	BOOST_AUTO_TEST_CASE(add_triangle_with_invalid_count_parameter)
	{
		stringstream command("triangle 12 45");
		BOOST_CHECK_THROW(creator.Run(command), invalid_argument);
	}
	/*BOOST_AUTO_TEST_CASE(print_min_perimeter_will_not_exception_when_shapes_is_empty)
	{
		stringstream command("min perimeter");
		BOOST_CHECK_NO_THROW(creator.Run(command));
	}
	BOOST_AUTO_TEST_CASE(print_max_area_will_not_exception_when_shapes_is_empty)
	{
		stringstream command("max area");
		BOOST_CHECK_NO_THROW(creator.Run(command));
	}*/
	BOOST_AUTO_TEST_CASE(composition_of_figures)
	{
		stringstream command("linesegment 12 45 12 rectangle 12 45 triangle 12 45 circle 12 45");
		BOOST_CHECK_THROW(creator.Run(command), invalid_argument);
	}
BOOST_AUTO_TEST_SUITE_END()
