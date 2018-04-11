#include "stdafx.h"

TEST_CASE("TrimBlanks test")
{
	CHECK(TrimBlanks("") == "");
	CHECK(TrimBlanks("Hello") == "Hello");
	CHECK(TrimBlanks("   Hello") == "Hello");
	CHECK(TrimBlanks("Hello   ") == "Hello");
	CHECK(TrimBlanks("    Hello   ") == "Hello");
	CHECK(TrimBlanks("    ") == "");
	CHECK(TrimBlanks("A") == "A");
}