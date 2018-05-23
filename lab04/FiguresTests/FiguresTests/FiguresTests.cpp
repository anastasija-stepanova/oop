#include "stdafx.h"
#include "../../Figures/Figures/CShapeCreator.h"

using namespace std;

struct CShapeCreatorDependencies
{
	stringstream input;
};

struct CShapeCreatorFixture : CShapeCreatorDependencies
{
	CShapeCreator creator;

	CShapeCreatorFixture()
		: creator(input)
	{
	}

	void VerifyCommandHandling(const string& command)
	{
		input = stringstream();
		BOOST_CHECK(input << command);
		BOOST_CHECK_THROW(creator.HandleCommand(), exception);
	}
};


BOOST_FIXTURE_TEST_SUITE(ShapeCreator, CShapeCreatorFixture)
	BOOST_AUTO_TEST_CASE(this_command_is_not_available)
	{
		VerifyCommandHandling("This command is not available");
	}
	BOOST_AUTO_TEST_CASE(draw_line)
	{
		VerifyCommandHandling("Line");
	}
	BOOST_AUTO_TEST_CASE(draw_triangle)
	{
		VerifyCommandHandling("Triangle");
	}
	BOOST_AUTO_TEST_CASE(draw_rectangle)
	{
		VerifyCommandHandling("Rectangle");
	}
	BOOST_AUTO_TEST_CASE(draw_circle)
	{
		VerifyCommandHandling("Circle");
	}
BOOST_AUTO_TEST_SUITE_END()
