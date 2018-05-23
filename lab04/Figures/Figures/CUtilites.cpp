#include "stdafx.h"
#include "CUtilites.h"
#include "Config.h"

using namespace std;

const string CUtilites::DoubleToString(double value)
{
	stringstream strm;
	strm << setprecision(NUMBER_DIGIT_AFTER_DECIMAL) << value;
	string str;
	strm >> str;
	return str;
}

const uint32_t CUtilites::StringToUInt(const string& str)
{
	uint32_t x;
	std::stringstream ss;
	ss << hex << str;
	ss >> x;
	return x;
}
